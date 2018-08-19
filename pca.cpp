//
// Created by Clayton on 2018/08/19.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "pca.h"

std::vector<float> jan;
std::vector<float> jul;

void SBNCLA002::readFile(std::string file_name){
    std::string line;
    std::ifstream file(file_name);

    if(!file.is_open()){
        std::cout<<"file not open";
    }
    else {
        int i = 1;
        while (std::getline(file, line)) {
            if (!line.empty()) {

                if (std::isdigit(line.at(0))) {
                    //std::cout << (i % 2 == 0 ? "even " : "odd ") << std::stof(line) << std::endl;
                    if (i % 2 == 0)
                        jul.emplace_back(std::stof(line));
                    else
                        jan.emplace_back(std::stof(line));
                    ++i;
                }


            }

        }
        file.close();
    }

//    for(int i=0;i<jan.size();++i)
//        //std::cout<<jan[i]<<" jul is "<<jul[i]<<"\n";
//
}

//function to calculate the covariance of the two vectors, as well as the covariance matrix

float SBNCLA002::calc_covariance(std::vector<float> &X,std::vector<float> &Y){

//subtract mean from each data
float mean_x = SBNCLA002::calc_mean(X);
float mean_y = SBNCLA002::calc_mean(Y);

std::transform(begin(X),end(X),begin(X),[&mean_x](float v){
  //  std::cout << v<< " v-mean_y " << v - mean_x << " mean_y " << mean_x<< "\n";

    return v-mean_x;
});


if(X!=Y) {
    std::transform(begin(Y), end(Y), begin(Y), [&mean_y](float value) {
        return value - mean_y;
    });
}

//now can calculate the covarience
float total=0;
for(int i=0;i<Y.size();++i){
  //  std::cout<<X[i]<<" "<<Y[i]<<"\n";
    total+=(X[i]*Y[i]);

}

    return total/(63);
}

float SBNCLA002::calc_mean(std::vector<float> &X){

    float total=0;
    for(float value:X){
        total+=value;
    }

    return total/(X.size());
}

std::vector<float> SBNCLA002::calc_covariance_matrix(){
    std::vector<float> matrix;

    matrix.push_back(SBNCLA002::calc_covariance(jan,jan));
    matrix.push_back(SBNCLA002::calc_covariance(jan,jul));
    matrix.push_back(SBNCLA002::calc_covariance(jan,jul));
    matrix.push_back(SBNCLA002::calc_covariance(jul,jul));


return matrix;
}