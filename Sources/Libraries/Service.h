//
// Created by hamro on 14/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_SERVICE_H
#define IMAGES_CLASSIFICATION_IA_SERVICE_H
#include <iostream>
#include <fstream>
using namespace std;
#include <cstdio>
#include <cstring>

class Service {

public:
    char FILE_PATH_IRIS[200] = "../Data/iris_training/iris_training/iris";
    char FILE_PATH_TRAINING[200] = "../Data/MNIST_training/training";
    char FILE_PATH_LABEL[200]="../Data/train-labels-idx1-ubyte";

    static ifstream readFile(char* FILE_PATH ,int integerPosition);
    virtual ~Service();
    Service();
};


#endif //IMAGES_CLASSIFICATION_IA_SERVICE_H
