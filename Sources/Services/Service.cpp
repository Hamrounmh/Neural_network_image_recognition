//
// Created by hamro on 14/03/2021.
//

#include "../Libraries/Service.h"
#include <random>
#include <chrono>


Service::~Service() {

}

Service::Service() {

}
double Service::genarteRandomDouble(double min, double max){

    default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> distribution(min, max);
    double value =  distribution(generator);
    return value;

}
ifstream Service::readFile(char *FILE_PATH, int integerPosition) {

    char filePosition[5] ;
    sprintf(filePosition, "%d", integerPosition);
    strcat(FILE_PATH,filePosition);
    ifstream in(FILE_PATH, ios ::in);

    return in;
}
