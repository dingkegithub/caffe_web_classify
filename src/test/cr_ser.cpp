#include "crow_all.h"
#include "crow_body.h"
#include <cstdio>

struct AcrMiddleWare {
    std::string message;

    AcrMiddleWare() {
        message = "acr";
    }

    void setMessage(std::string newMsg) {
        message = std::move(newMsg);
    }

    struct context {
    };

    void before_handle(crow::request& req, crow::response& res, context& ctx) {
    }

    void after_handle(crow::request& req, crow::response& res, context& ctx) {
    }
};


void router(crow::SimpleApp &app) {

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    CROW_ROUTE(app, "/classify_upload").methods("POST"_method)
        ([](const crow::request& req) {
            for (const auto &h : req.headers) {
                std::cout << h.first << " = " << h.second << std::endl;
            }

            std::string content_type;
            if (req.headers.count("Content-Type") == 1) {
                content_type = req.headers.find("Content-Type")->second;
            } else {
                return "failed";
            }

            auto body = req.body;
            form_data_t form = parse_img_body(content_type, body);
            std::cout << "<----------------------------->" << std::endl;
            std::cout << "field: " << form.field << std::endl;
            std::cout << "file : " << form.file << std::endl;
            std::cout << "type : " << form.type << std::endl;
            std::cout << "img  : " << form.img.size() << std::endl;
            std::cout << form.img << std::endl;
            FILE *fp = fopen(form.file.c_str(), "wb");
            fwrite(form.img.c_str(), 1, form.img.size(), fp);
            fclose(fp);
            std::cout << "<----------------------------->" << std::endl;
            return "ok";
        });
}

int main()
{
    crow::SimpleApp app;
    router(app);
    app.port(18080).multithreaded().run();
}
