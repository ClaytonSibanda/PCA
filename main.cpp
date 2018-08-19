#include <iostream>
#include <fstream>
#include <vector>
#include "pca.h"

using namespace std;


int main() {

  SBNCLA002::readFile("C:\\Users\\Nyasha\\CLionProjects\\PCA\\data.txt");
  vector<float> data=SBNCLA002::calc_covariance_matrix();

  for(auto &value:data)
    cout<<value<<endl;
    return 0;

}

