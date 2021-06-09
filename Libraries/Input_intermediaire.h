//
// Created by HAO1DY2 on 08/06/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_INPUT_INTERMEDIAIRE_H
#define IMAGES_CLASSIFICATION_IA_INPUT_INTERMEDIAIRE_H


#include "Input.h"
#include <vector>
class Input_intermediaire : public Input {
private:
    vector<double> valeursIntermediaires ;
public:
    Input_intermediaire(char label);
    void add(double );
    double  operator[](int);
};


#endif //IMAGES_CLASSIFICATION_IA_INPUT_INTERMEDIAIRE_H
