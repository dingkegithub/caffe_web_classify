//
//  classifycation.h
//  caffe_web_classify
//
//  Created by 丁科 on 2019/1/15.
//  Copyright © 2019年 丁科. All rights reserved.
//
#ifndef _CLASSIFIER_H_
#define _CLASSIFIER_H_

#include <caffe/caffe.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <algorithm>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using namespace caffe;
using std::string;

typedef std::pair<string, float> Prediction;

namespace acr {

    class Classifier {

    public:
        Classifier(const string& model_file,
                   const string& trained_file,
                   const string& mean_file,
                   const string& label_file,
                   bool gpu_enable = false,
                   int gpu=0);

        std::vector<Prediction> classify(const cv::Mat& img, int n = 1);

        std::vector<Prediction> classify(const string content, int n = 1);

    private:
        void SetMean(const string& mean_file);

        std::vector<float> Predict(const cv::Mat& img);

        void WrapInputLayer(std::vector<cv::Mat>* input_channels);

        void Preprocess(const cv::Mat& img,
                        std::vector<cv::Mat>* input_channels);

    private:
        shared_ptr<Net<float> > net_;
        cv::Size input_geometry_;
        int num_channels_;
        cv::Mat mean_;
        std::vector<string> labels_;
    };

}
#endif
