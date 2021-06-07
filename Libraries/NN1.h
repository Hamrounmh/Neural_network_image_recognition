//
// Created by hamro on 01/06/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_NN1_H
#define IMAGES_CLASSIFICATION_IA_NN1_H
#include "Input.h"
#include "Perceptron.h"

class NN1 {
private :
    Perceptron *perceptronList[785] ;
    int NbPerceptronInNN1;
public:

    NN1(int ,int,Fonction_activation*  );
    char evaluation(Input *);
    void apprentissage(Input * , double);

    int getNbPerceptronInNn1() const;
};


#endif //IMAGES_CLASSIFICATION_IA_NN1_H
