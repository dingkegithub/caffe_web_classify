//
// Created by dk on 12/12/19.
//

#ifndef _ACR_H_
#define _ACR_H_

#include "classifier.h"
#include <vector>

using std::string;
using std::vector;

namespace acr {

    class Acr {

    public:
        static Acr* instance();

        static void config(string model_file,
                           string trained_file,
                           string mean_file,
                           string label_file,
                           bool gpu= false,
                           int num=0);

        Prediction predict(const string &content, bool memory= false);

    private:
        static Acr* volatile instance_;
        static string mean;
        static string model;
        static string deploy;
        static string label;
        static bool gpu_enable;
        static int gpu;
        Classifier* classifier_;

    private:
        Acr();
    };

}

#endif
