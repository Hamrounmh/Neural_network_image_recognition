//
// Created by hamro on 17/03/2021.
//


#include <random>
#include <chrono>
#include "../Libraries/Perceptron.h"
using namespace std;

//TODO:  tester les methodes de la class
//TODO: trouver une solution pour la méthode get_label() qui doit retourner un entier pour les calcul
// TODO: verifier que les labels ici sont des char seulement
Perceptron::Perceptron(int taille_Input, Fonction_activation   *fct, char  labelInput) {
    tailleInput = taille_Input+1;
    fonctionActivation = fct;
    poids = new int[taille_Input+1];
    label =  labelInput;
    delta = 0.;
    Service::generateRandomIntArray(-1, 1, tailleInput, poids);
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
    for(int i=1; i<tailleInput;i++){
        xi =(*in)[i-1];
        somme+= (*(poids+i+1))*xi;
    }
   return (*fonctionActivation)(somme);
}

double Perceptron::calcul_delta(Input * in) {
    double somme = *(poids);
    double xi;
    for(int i=0; i<tailleInput;i++){
        xi =(*in)[i];
        somme+= (*(poids+i))*xi;
    }
    double part1 = (*fonctionActivation).prim(somme);
    double part2 =forward(in) - (int)(*in).get_label();
    delta = part1*part2;
    return delta ;
}

//TODO : verifier les taille des tableau sachant que poids est de taille n+1 et input.x est de taille n
void Perceptron::backprop(Input * in, double mu) {
poids[0]= poids[0] - mu*delta;
for(int i=1; i<tailleInput; i++){
    poids[i]  = poids[i] - mu* (*in)[i-1] *delta;
}

}
