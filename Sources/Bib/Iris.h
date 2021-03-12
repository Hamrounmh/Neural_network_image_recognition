//
// Created by hamro on 12/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_IRIS_H
#define IMAGES_CLASSIFICATION_IA_IRIS_H
#include "Input.h"

class Iris : Input {
private:
    static const int taille_description = 4;
    double description[taille_description];

public:
    Iris(char);
    ~Iris();
    double* get_description();
    double & operator [] (int) ;

};


#endif //IMAGES_CLASSIFICATION_IA_IRIS_H