//
// Created by hamro on 17/03/2021.
//


#include <random>
#include <chrono>
#include "../Libraries/Perceptron.h"
using namespace std;

Perceptron::Perceptron(int taille_Input, Fonction_activation   *fct, char * labelInput) {
    tailleInput = taille_Input;
    fonctionActivation = fct;
    label = new char[100];
    poids = new double[taille_Input];
    strcpy(label, labelInput);
    delta = 0.;
    Service::genarteRandomDoubleArray(-1.0, 1.0, taille_Input,poids);
}

double Perceptron::get_poids(int i) {
    return *(poids+i);
}

double Perceptron::get_delta() {
    return delta;
}

double Perceptron::forward(Input * in) {
    double somme = *(poids);
    double xi;
    for(int i=0; i<tailleInput;i++){
        xi =(*in)[i];
        somme+= (*(poids+i))*xi;
    }
   return (*fonctionActivation)(somme);


}
