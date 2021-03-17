//
// Created by hamro on 14/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_FONCTION_ACTIVATION_H
#define IMAGES_CLASSIFICATION_IA_FONCTION_ACTIVATION_H
#include <cmath>

class Fonction_activation {

public:
    virtual double operator ()(double) = 0 ;
    virtual double  prim(double) = 0;
};


#endif //IMAGES_CLASSIFICATION_IA_FONCTION_ACTIVATION_H
