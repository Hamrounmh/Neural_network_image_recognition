//
// Created by HAO1DY2 on 08/06/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_PERCEPTRON_HIDDEN_H
#define IMAGES_CLASSIFICATION_IA_PERCEPTRON_HIDDEN_H


#include "Perceptron.h"

class Perceptron_hidden : public  Perceptron {
public:

    Perceptron_hidden(int inputSize, Fonction_activation *activation, char labelOfPerceptron,
                      vector<Perceptron *> p_perceptronsList);

    double calcul_delta(Input *,int s );
    void backprop(Input * , double);
    int PerceptronsSize();
private :
    vector<Perceptron * > perceptronsList;


};



#endif //IMAGES_CLASSIFICATION_IA_PERCEPTRON_HIDDEN_H
