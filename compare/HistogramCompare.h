//
// Created by Михаил Мурунов on 29.11.2021.
//

#ifndef PICTURE_COMPARISON_HISTOGRAMCOMPARE_H
#define PICTURE_COMPARISON_HISTOGRAMCOMPARE_H
#include "opencv2/imgproc/imgproc.hpp"

class HistogramCompare
{
public:
    static int compare(const cv::Mat& first, const cv::Mat& second);
};


#endif //PICTURE_COMPARISON_HISTOGRAMCOMPARE_H
