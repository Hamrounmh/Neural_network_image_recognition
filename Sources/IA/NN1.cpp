//
// Created by hamro on 01/06/2021.
//

#include <unistd.h>
#include "../../Libraries/NN1.h"
#include "../../Libraries/Sigmoide.h"

// TODO : definir comment passer la fonction d'activation car c'est encore flou peut etre la passer en parametres , et aussi verifier quand et comment mettre '0'+i et i dans le parametre label du perceptron
NN1::NN1(int InputSize, int CategoriesNumber,Fonction_activation * fct ) {

    for(int i = 0 ; i<CategoriesNumber; i++ ){
        perceptronList[i] = new Perceptron(InputSize,fct ,'0' + i);
    }
    NbPerceptronInNN1 = CategoriesNumber;
}

char NN1::evaluation(Input * input) {

double value  = perceptronList[0]->forward(input);
    char result  = perceptronList[0]->getLabel();
    for(int i = 1 ; i < NbPerceptronInNN1 ; i++ ){
        double nextValuePerceptron = perceptronList[i]->forward(input);
         if(nextValuePerceptron>value){
              result = perceptronList[i]->getLabel();
              value=nextValuePerceptron;
         }
    }
    return result;
}

void NN1::apprentissage(Input * input, double learningRante) {
    for(int i = 0 ; i<NbPerceptronInNN1 ; i++ ){
        perceptronList[i]->calcul_delta(input);
        perceptronList[i]->backprop(input,learningRante);
    }
}

int NN1::getNbPerceptronInNn1() const {
    return NbPerceptronInNN1;
}
