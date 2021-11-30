//
// Created by Михаил Мурунов on 29.11.2021.
//

#include "HistogramCompare.h"


int HistogramCompare::compare(const cv::Mat& first, const cv::Mat& second)
{
    cv::Mat hsv_first, hsv_second;
    cv::cvtColor( first, hsv_first, cv::COLOR_BGR2HSV);
    cv::cvtColor( second, hsv_second, cv::COLOR_BGR2HSV);

    cv::Mat hsv_half_down = hsv_first(cv::Range(hsv_first.rows/2, hsv_first.rows), cv::Range(0, hsv_first.cols));

    int h_bins = 50, s_bins = 60;
    int histSize[] = {h_bins, s_bins};

    float h_ranges[] = {0, 180};
    float s_ranges[] = {0, 256};
    const float* ranges[] = {h_ranges, s_ranges};

    int channels[] = {0, 1};

    cv::Mat hist_first, hist_second;
    calcHist(&hsv_first, 1, channels, cv::Mat(), hist_first, 2, histSize, ranges, true, false);
    normalize(hist_first, hist_first, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
    calcHist(&hsv_second, 1, channels, cv::Mat(), hist_second, 2, histSize, ranges, true, false);
    normalize(hist_second, hist_second, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    double ret = compareHist(hist_first, hist_second, 0);

    return int(ret * 100);
}
