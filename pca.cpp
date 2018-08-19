//
// Created by Clayton on 2018/08/19.
//

#include <fstream>
#include <iostream>
#include <vector>
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
                    std::cout << (i % 2 == 0 ? "even " : "odd ") << std::stof(line) << std::endl;
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
}

//function to calculate the covariance of the two vectors, as well as the covariance matrix

std::vector<float> calcCovaianceMatric(std::vector<float> jan1,std::vector<float> jul1){

    std::vector<float> covMatrix;



    return covMatrix;
}