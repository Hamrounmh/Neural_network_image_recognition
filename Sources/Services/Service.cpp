//
// Created by hamro on 14/03/2021.
//

#include "../../Libraries/Service.h"
#include <random>
#include <chrono>


Service::~Service() {

}

Service::Service() {

}
// TODO: Ce service doit nous retourner des valeurs entières :
int* Service::generateRandomIntArray(int min, int max, int ArrayLength, int * values){

    default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(min, max);
    for(int i=0; i<ArrayLength; i++ )
        *(values+i) =distribution(generator);
    return values;

}
double* Service::generateRandomDoubleArray(double min, double max, int ArrayLength, double * values){


    default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> distribution(min, max);
    for(int i=0; i<ArrayLength; i++ )
        *(values+i) =distribution(generator);
    return values;

}
ifstream Service::readFile(char *FILE_PATH, int integerPosition) {

    char filePosition[5] ;
    sprintf(filePosition, "%d", integerPosition);
    strcat(FILE_PATH,filePosition);
    ifstream in(FILE_PATH, ios ::in);

    return in;
}
//TODO : comprendre l'histoire des labels ..
char Service::assigneLabelValuesIris(char *strLabel) {

    if (strLabel == "Iris-setosa")
    {
        return '0';
    }
    else if (strLabel == "Iris-virginica")
    {
        return '1';
    }
    else if (strLabel == "Iris-versicolor")
    {
        return '2';
    }
    else
    {
        return '0';
    }
}

char Service::assigneLabelValuesImages(char *strLabel) {
    return strLabel[0];
}

int Service::generateRandomInt(int min, int max) {
    default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

    uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}
