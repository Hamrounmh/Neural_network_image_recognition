//
// Created by hamro on 17/03/2021.
//


#include <random>
#include <chrono>
#include <unistd.h>
#include "../../Libraries/Perceptron.h"
using namespace std;

//TODO:  tester les methodes de la class
//TODO: trouver une solution pour la méthode get_label() qui doit retourner un entier pour les calcul
// TODO: verifier que les labels ici sont des char seulement
Perceptron::Perceptron(int taille_Input, Fonction_activation   *fct, char  labelInput) {
    tailleInput = taille_Input;
    fonctionActivation = fct;
    int * values = new int[taille_Input+1];
    label =  labelInput;
    delta = 0.;
    Service::generateRandomIntArray(-1,1,taille_Input+1,values);
    for(int i= 0 ; i<taille_Input+1 ; i++ ){
        poids.push_back(*(values+i));
    }
    //ici le sleep est a cause du random qui utilise le chrono
    sleep(0.2);

}

double Perceptron::get_poids(int index) {
    return poids[index];
}

double Perceptron::get_delta() {
    return delta;
}

void Perceptron::setDelta(double delta) {
    Perceptron::delta = delta;
}

double Perceptron::forward(Input * in) {
    double somme = get_poids(0);
    double xi;
    for(int i=0; i<tailleInput;i++){
        xi =(*in)[i];
        somme = somme + get_poids(i+1)*xi;
    }
  return  (*fonctionActivation)(somme);


}

double Perceptron::calcul_delta(Input * in) {
    double somme = get_poids(0);
    double xi;
    for(int i=0; i<tailleInput;i++){
        xi =(*in)[i];
        somme= somme +  (get_poids(i+1)*xi);
    }
    double part1 = fonctionActivation->prim(somme);
    double yj;

    if(getLabel() == in->get_label()){
         yj =1.0;
    }else{
         yj =0.0;
    }

    double Axj = forward(in);
    double part2 = Axj-yj;
    delta = part1*part2;

    setDelta(delta);
    return delta ;
}

//TODO : verifier les taille des tableau sachant que poids est de taille n+1 et input.x est de taille n
void Perceptron::backprop(Input * in, double learningRate) {
    poids[0]= get_poids(0) - learningRate*delta;
    for(int i=0; i<tailleInput; i++){
        poids[i+1]  = get_poids(i+1) - learningRate* (*in)[i] *delta;
    }

}

char Perceptron::getLabel()  {
    return label;
}




