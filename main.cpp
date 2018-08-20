//
// Created by Nyasha on 2018/08/20.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "pca.h"

using namespace std;


int main() {

    SBNCLA002::readFile("C:\\Users\\Nyasha\\CLionProjects\\PCA\\data.txt");
    vector<float> data=SBNCLA002::calc_covariance_matrix();

    int count =1;
    cout<<"The covariance matrix is: \n";
    for(auto &value:data) {
        cout << value << (count % 2 == 0 ? "\n" : " ");
        ++count;
    }
float total_variance =data[0]+data[data.size()-1];
    cout<<"\nTotal variance is:\n"<<data[0]+data[data.size()-1]<<"\n\n";

    cout<<"\n********Eigen values and vectors we calculated using an online tool provided on the notes********\n\n";

    cout<<"First principal component of the dataset corresponds to the eigen value:\n154.3105\n\n";
    cout<<"Its eigen vector is:\n0.9391\n0.3435\n\n";

    cout<<"Second principal component of the dataset corresponds to the eigen value:\n9.1630\n\n";

    cout<<"Its eigen vector is:\n-0.3435\n0.9391\n\n";


    cout<<"First Component explains:\n"<<((9.1630)/total_variance)*100<<"% of the total variance\n\n";
    cout<<"Second Component explains:\n"<<((154.3105)/total_variance*100)<<"% of the total variance\n\n";

    return 0;

}

//[1] Real Eigenvalue =    154.3105
//[1] Real Eigenvector:
//0.9391
//0.3435
//
//[2] Real Eigenvalue =      9.1630
//[2] Real Eigenvector:
//-0.3435
//0.9391

