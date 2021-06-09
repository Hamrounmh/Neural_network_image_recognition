//
// Created by HAO1DY2 on 08/06/2021.
//

#include "../../Libraries/Perceptron_hidden.h"
#include "../../Libraries/Perceptron.h"



Perceptron_hidden::Perceptron_hidden(int inputSize, Fonction_activation *activation, char labelOfPerceptron,
                                       vector<Perceptron * > p_perceptronsList) : Perceptron(inputSize,activation,labelOfPerceptron) {
    perceptronsList =  p_perceptronsList;
}

//TODO : ici verifier si le r est bien le nobre d'element du vecteur et aussi si le getpoids(i) est bon !
double Perceptron_hidden::calcul_delta(Input * input) {
    // TODO : ici le poids est s qui correspend au Sème poids qui a le meme indice que notre perceptron comment le trouver ?
    // J'ai trouvé que label  du chiffre - 48 nous donne le int :)
    int s = (int)getLabel()-48;
    double somme = get_poids(0);
    double xi;
    for(int i=0; i<tailleInput;i++){
        xi =(*input)[i];
        somme= somme +  (get_poids(i+1)*xi);
    }
    double part1 = fonctionActivation->prim(somme);

    double part2 = 0.;
    for(int i = 0 ; i<PerceptronsSize(); i++){
        part2 += perceptronsList[i]->get_delta() * perceptronsList[i]->get_poids(s);
    }

    double r_delta = part1*part2;
    return r_delta ;
}

int Perceptron_hidden::PerceptronsSize(){
    return perceptronsList.size();
}

void Perceptron_hidden::backprop(Input * input , double learningRate){
    double l_delta = Perceptron_hidden::calcul_delta(input);
    poids[0]= get_poids(0) - learningRate*l_delta;
    for(int i=0; i<tailleInput; i++){
        poids[i+1]  = get_poids(i+1) - learningRate* (*input)[i] *l_delta;
    }
}
