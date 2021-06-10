//
// Created by HAO1DY2 on 08/06/2021.
//

#include "../../Libraries/Input_intermediaire.h"



// TODO : trouver un moyen pour savoir comment remplir le tableau ou sinon il suffit seulement de l'initialiser ? je sais pas encore !
Input_intermediaire::Input_intermediaire(char p_label) {
label = p_label;

}

void Input_intermediaire::add(double element) {
valeursIntermediaires.push_back(element);
}

double Input_intermediaire::operator[](int index) {
    return valeursIntermediaires[index];
}
