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
    char STRING_IMAGE[200]="image";
    char STRING_IRIS[200]="iris";
    constexpr static int  DATA_SIZE_IMAGE = 60000;
    constexpr static int  DATA_SIZE_IRIS = 150 ;
    constexpr static int  SIZE_CARACTERESTIQUES_IRIS = 4 ;
    constexpr static int  SIZE_CATEGORIES_IRIS = 3 ;
    constexpr static int  SIZE_CATEGORIES_IMAGE = 10 ;
    constexpr static int  SIZE_CARACTERESTIQUES_IMAGE = 784 ;


    static ifstream readFile(char* FILE_PATH ,int integerPosition);

    virtual ~Service();
    Service();
    static char assigneLabelValuesIris(char * strLabel);
    static char assigneLabelValuesImages(char * strLabel);
    static int* generateRandomIntArray(int min, int max, int ArrayLength, int * values);
    static int generateRandomInt(int min ,int  max);
    static double* generateRandomDoubleArray(double min, double max, int ArrayLength, double * values);
};


#endif //IMAGES_CLASSIFICATION_IA_SERVICE_H
