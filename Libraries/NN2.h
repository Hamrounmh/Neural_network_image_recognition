//
// Created by HAO1DY2 on 09/06/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_NN2_H
#define IMAGES_CLASSIFICATION_IA_NN2_H

#include "Perceptron.h"
#include "Perceptron_hidden.h"
#include "Fonction_activation.h"
#include "Input.h"
#include <vector>

class NN2 {
private:

    vector<Perceptron_hidden *> hiddenLayerPerceptrons;
    vector<Perceptron *> outLayerPerceptron;

public:

    NN2(int inputSize, int outLayerSize_CategoriesNumber, int hiddenLayerSize, Fonction_activation *fct);
    void apprentissage(Input * input,double learningrate);
    char evaluation(Input *input);
};


#endif //IMAGES_CLASSIFICATION_IA_NN2_H
