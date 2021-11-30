#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "compare/HistogramCompare.h"

using namespace std;

int main()
{
    int border;
    std::cin >> border;
    std::cin.ignore(256, '\n');
    vector<string>pictures_paths {};
    string path;
    while (getline(cin, path))
    {
        if (path.empty())
            break;
        pictures_paths.push_back(path);
    }
    for (int i = 0; i < pictures_paths.size(); ++i)
    {
        cv::Mat first = cv::imread(pictures_paths[i]);
        if (first.empty())
            return -1;

        for (int j = i + 1; j < pictures_paths.size(); ++j)
        {
            cv::Mat second = cv::imread(pictures_paths[j]);
            if (second.empty())
                return -1;

            int hist_res = HistogramCompare::compare(first, second);
            if (hist_res > border)
                std::cout << pictures_paths[i] << ", " << pictures_paths[j] << ", " << hist_res << "%" << endl;
        }
    }
    return 0;
}
