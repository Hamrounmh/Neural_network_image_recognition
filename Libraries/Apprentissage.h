//
// Created by hamro on 05/06/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_APPRENTISSAGE_H
#define IMAGES_CLASSIFICATION_IA_APPRENTISSAGE_H

#include "NN1.h"
#include "Input.h"
#include "Image.h"
#include "Iris.h"

template <class input_type_class, int exemplesNumberForInput,class NeuralNetwork>
        class Apprentissage {
private :
    NeuralNetwork * neuralNetwork;
    char * serviceNameInput ;
public :
    Apprentissage( NeuralNetwork * );
    void apprendre_base(int k_iterations, double learningRate);
    int evaluer();

};


#endif //IMAGES_CLASSIFICATION_IA_APPRENTISSAGE_H
