//
// Created by dk on 12/14/19.
//

#ifndef _CLASSIFY_IMG_H_
#define _CLASSIFY_IMG_H_

#include "crow_all.h"
#include "crow_body.h"
#include "middleware.h"
#include <string>
#include <ctime>
#include "acr.h"


namespace http_server {

    crow::json::wvalue gen_response(int error, const std::string &msg, const std::string &name = "", float score = .0) {
        crow::json::wvalue resp;

        if (error != 200) {
            resp["status"] = error;
            resp["reason"] = msg;
            return resp;
        }

        resp["status"] = 200;
        resp["caffe_scores"] = score;
        resp["name"] = name;
        resp["update"] = "2019-09-24T21:16:11";
        resp["source_type"] = "";
        resp["reason"] = "ok";
        resp["operator"] = "";
        resp["type"] = "unknown";
        resp["std_channel_id"] = "065BB874-FA93-46B1-B0A7-CDCA7B510C99";
        return resp;
    }

    void router(crow::SimpleApp &app) {
        CROW_ROUTE(app, "/classify_upload")
        .methods("POST"_method)
        ([](const crow::request &req) {
                    std::string content_type;
                    if (req.headers.count("Content-Type") == 1) {
                        content_type = req.headers.find("Content-Type")->second;
                    } else {
                        return gen_response(-1, "bad request header");
                    }

                    auto body = req.body;
                    clock_t b_s = clock();
                    form_data_t form = parse_img_body(content_type, body);
                    double b_el = (double)(clock() - b_s)/CLOCKS_PER_SEC;
                    std::cout << "body elapse time: " << b_el << "s" << std::endl;
                    if (form.field != "imagefile") {
                        return gen_response(-2, "form field imagefile need");
                    }

                    if (form.img.size() <= 0) {
                        return gen_response(-3, "invalid image");
                    }

                    clock_t cl_s = clock();
                    Prediction p = acr::Acr::instance()->predict(form.img, true);
                    double cl_el = double(clock() - cl_s) / CLOCKS_PER_SEC;
                    std::cout << "net elapse time" << cl_el << "s" << std::endl;
                    boost::regex r{".+/(.+)"};
                    boost::smatch res;
                    if (!boost::regex_search(p.first, res, r)) {
                        return gen_response(-4, "can't recognise");
                    }

                    std::string logo_name = res[1];
                    return gen_response(200, "ok", logo_name, p.second);
                });
    }
}
#endif
