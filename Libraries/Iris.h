//
// Created by hamro on 12/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_IRIS_H
#define IMAGES_CLASSIFICATION_IA_IRIS_H
#include "Input.h"


class Iris : public Input {
private:
    static const int taille_description = 4;
    double description[taille_description];
public:
    Iris(int index );
    ~Iris();
    static void get_description(int i);
    double operator [] (int);



};


#endif //IMAGES_CLASSIFICATION_IA_IRIS_H
