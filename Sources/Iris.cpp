//
// Created by hamro on 12/03/2021.
//

#include "Bib/Iris.h"
Iris::Iris(char car) {
int i;

label = new char[100];

//    ifstream in(" nom_fichier ”", ios ::in);
//    int nbr;
//    if(in)
//        in >> nbr;

for(i= 0 ; i<=taille_description;i++ )
{
    *(description+i)=.012;
    label[i]='c';
}

}

Iris::~Iris() = default;

double* Iris::get_description() {
    return description;
}

//Iris ir = new Iris();
//ir[2]  =descritpiton[2]
double &Iris::operator[](int i ) {
    return *(description+i);
}