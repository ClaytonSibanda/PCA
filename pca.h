//
// Created by Nyasha on 2018/08/19.
//

#ifndef PCA_PCA_H
#define PCA_PCA_H

#include <string>
#include <vector>

namespace SBNCLA002{
    void readFile(std::string file_name);
    float calc_covariance(std::vector<float> &X,std::vector<float> &Y);
    float calc_mean(std::vector<float> &X);
    std::vector<float> calc_covariance_matrix();
}


#endif //PCA_PCA_H
