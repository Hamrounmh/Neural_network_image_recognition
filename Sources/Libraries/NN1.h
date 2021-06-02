//
// Created by hamro on 01/06/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_NN1_H
#define IMAGES_CLASSIFICATION_IA_NN1_H
#include "Input.h"

class NN1 {
public:
    NN1(int ,int ,char );
    void evaluation(Input *);
    void apprentissage(Input * , double);

};


#endif //IMAGES_CLASSIFICATION_IA_NN1_H
