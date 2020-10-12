//
// Created by dk on 12/12/19.
//
#include "acr.h"
#include <mutex>
#include <iostream>

namespace acr {
    std::mutex g_mutex;

    Acr* volatile Acr::instance_ = nullptr;
    std::string Acr::model = "";
    std::string Acr::mean = "";
    std::string Acr::label = "";
    std::string Acr::deploy = "";
    bool Acr::gpu_enable = false;
    int Acr::gpu = 0;

    Acr* Acr::instance() {
        if (Acr::instance_ == nullptr) {
            std::cout << "init caffe" << std::endl;
            g_mutex.lock();

            if (Acr::instance_ == nullptr) {
                Acr* volatile temp = new Acr();
                temp->classifier_ = new Classifier(
                        Acr::model,
                        Acr::deploy,
                        Acr::mean,
                        Acr::label,
                        Acr::gpu_enable,
                        Acr::gpu);
                Acr::instance_ = temp;
            }

            g_mutex.unlock();
        }

        std::cout << "reuse caffe" << std::endl;
        return Acr::instance_;
    }

    void Acr::config(std::string model_file,
                     std::string deploy_file,
                     std::string mean_file,
                     std::string label_file,
                     bool enable, int num) {

        Acr::mean = mean_file;
        Acr::model = model_file;
        Acr::label = label_file;
        Acr::deploy = deploy_file;
        Acr::gpu_enable = enable;
        Acr::gpu = num;
    }

    Prediction Acr::predict(const std::string &content, bool mem) {

        if (mem) {
            std::cout << "use memory" << std::endl;
            vector<Prediction > res = this->classifier_->classify(content);
            return res[0];
        }

        std::cout << "use disk" << std::endl;
        cv::Mat img = cv::imread(content, -1);
        vector<Prediction > res = this->classifier_->classify(img);
        return res[0];
    }

    Acr::Acr() {

    }
}
