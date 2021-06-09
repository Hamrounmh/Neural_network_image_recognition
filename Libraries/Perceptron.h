//
// Created by hamro on 17/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_PERCEPTRON_H
#define IMAGES_CLASSIFICATION_IA_PERCEPTRON_H


#include "Fonction_activation.h"
#include "Input.h"
#include "Tanh.h"
#include <vector>
#include <utility>

class Perceptron {
private:
    double delta;
    char label;
protected:
    vector<double> poids;
    int tailleInput;
    Fonction_activation *fonctionActivation ;
public:
    /*
     * Un constructeur qui prend en paramètre un entier correspondant à la taille de l’input (par exemple, 4 pour les fleurs et 784 pour les images),
     * une fonction d’activation (de préférence un pointeur pour avoir une même fonction d’activation commune à tous les perceptrons),
     * ainsi qu’un char correspondant au label du perceptron.
     * Le constructeur va initialiser les poids du perceptron de manière aléatoire (par exemple en choisissant des valeurs entières entre -1 et 1 aléatoirement).
     */
    Perceptron(int , Fonction_activation*  ,char );

    //Une fonction membre get_poids qui prend en paramètre un indice (int)
    // et renvoie une valeur réelle (double) correspondant à la valeur du
    // poids correspondant à l’indice en paramètre.
    double get_poids(int);

    //correspond au calcul de 𝒜(𝒙)).
    double forward(Input *);


    //Une fonction membre calcul_delta qui prend en paramètre un Input (de préférence par référence),
    // et qui renvoie une valeur réelle (double) correspondant à l’évaluation de la valeur 𝛿𝑘−1=𝜑′(𝑤0𝑘−1+Σ𝑤𝑖𝑘−1𝑥𝑖𝑛𝑖=1)×(𝒜(𝒙𝒋)−𝑦𝑗)
    //pour l’input (𝒙𝑗,y𝑗) donné en paramètre. Cette fonction va également stocker cette valeur dans le champ delta.
    double calcul_delta(Input *);

    //Une fonction membre get_delta sans paramètre qui renvoie la valeur du champs delta.
    double get_delta();

    //Une fonction membre backprop qui prend en paramètre
    // un Input (de préférence par référence),
    // ainsi qu’une valeur réelle (double) correspondant au pas de gradient 𝜇,
    // et qui ne renvoie rien. Cette fonction va apprendre les poids à partir de l’input en paramètre en utilisant la formule
    //𝑤𝒊𝑘={𝑤𝒊𝑘−1−𝜇𝛿𝑘−1 𝑠𝑖 𝑖=0 𝑤𝒊𝑘−1−𝜇𝑥𝑖𝛿𝑘−1 𝑠𝑖𝑛𝑜𝑛
    void backprop(Input *, double mu);

    char getLabel() ;

    void setDelta(double delta);

};


#endif //IMAGES_CLASSIFICATION_IA_PERCEPTRON_H
