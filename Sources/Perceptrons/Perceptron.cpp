//
// Created by hamro on 17/03/2021.
//


#include <random>
#include <chrono>
#include "Perceptron.h"
using namespace std;

Perceptron::Perceptron(int taille_Input, Fonction_activation   *fct, char * labelInput) {

    fonctionActivation=fct;
    label = new char[100];
    poids = new double[taille_Input];
    strcpy(label,labelInput);
    delta=0.;
    default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> distribution(-1.0, 1.0);

for(int i = 0; i<taille_Input; i++ ){
    *(poids+i) = distribution(generator);
}

}

double Perceptron::get_poids(int i) {
    return *(poids+i);
}

double Perceptron::get_delta() {
    return delta;
}
