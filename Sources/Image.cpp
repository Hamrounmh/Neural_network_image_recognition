//
// Created by ahmed on 12/03/2021.
//

#include "Bib/Input.h"
#include "Bib/Image.h"
#include <iostream>
#include<fstream>

using namespace std;
double  pixel;


// prend en entrée un entier correspond a l'indice de l'image (0,1 .....59999)
Image::Image(int index) {

    label = new char[100];
    int i = 0;
    char line;
    char charIndexFile[5] ;
    int intIndexFile = index < 0 ? -1*index : index; // valeur absolut de l'indice

    sprintf(charIndexFile, "%d", intIndexFile);
    strcat(PATH,charIndexFile);
    cout <<"path=" <<PATH<<"\n";
    ifstream monFlux(PATH, ios ::binary);

    if(monFlux.good()){
        // se placer en 1078 octect a partir du debut de fichier
        monFlux.seekg(1078,ios::beg);
        cout << "ma position de lecture :"<< monFlux .tellg() <<"\n";
        while(!monFlux.eof()) {
            for (int i = 0; i < tailleDePixel; i++) {
                monFlux.read((char*) &pixels[i], sizeof(char));
                //double pixel=(double )pixels [i];
                //cout << pixel<<"\n";
            }
        }



    }
    else{
        cerr<< "ERREUR: Impossible d'ouvrir le fichier en lecture." <<endl
        ;exit(1);
    }
    monFlux.close();

    ifstream monFluxLabel(PATH_LABEL, ios ::binary);
    cout << PATH_LABEL <<"\n";
    if(monFluxLabel.good()){
        int indexRead=8+index;
        monFluxLabel.seekg(indexRead,ios::beg);
        cout << "ma position de lecture dans PATH LABEL :"<< monFluxLabel.tellg() <<"\n";
        monFluxLabel.read((char*) &line, sizeof(char));
        cout <<"label :" << (int)line <<"\n";

    } else{
        cerr<< "ERREUR: Impossible d'ouvrir le fichier en lecture." <<endl
        ;exit(1);
    }
    monFluxLabel.close();


    // lecture des labels
    label = new char[100];
    for(int j=0;j<8;j++){
        label[j]='a';
    }

}

// prend en entée un entier correspond a l'indice du pixel
// un pixel c'est un niveau de gris (une valeur entre 0 et 255)
double &Image::operator[](int i) {
    pixel=(double )pixels[i];
    return pixel;

}

Image::~Image() = default;
