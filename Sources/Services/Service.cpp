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
ifstream Service::readFile(char *FILE_PATH, int integerPosition) {

    char filePosition[5] ;
    sprintf(filePosition, "%d", integerPosition);
    strcat(FILE_PATH,filePosition);
    ifstream in(FILE_PATH, ios ::in);

    return in;
}
