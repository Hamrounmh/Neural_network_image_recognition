//
// Created by ahmed on 12/03/2021.
//

#include "Bib/Input.h"
#include "Bib/Image.h"
#include <iostream>
#include<fstream>

using namespace std;



// prend en entrée un entier correspond a l'indice de l'image (0,1 .....59999)
Image::Image(int index) {

    label = new char[100];
    int i = 0;
    char line[100];
    char charIndexFile[5] ;
    int intIndexFile = index < 0 ? -1*index : index; // valeur absolut de l'indice

    sprintf(charIndexFile, "%d", intIndexFile);
    strcat(PATH,charIndexFile);
    cout <<"path=" <<PATH<<"/n";
    ifstream monFlux("/home/ahmed/CLionProjects/Images_classification_IA/Data/MNIST_training/training5", ios ::binary);

    if(monFlux.good()){
        // se placer en 1078 octect a partir du debut de fichier
        monFlux.seekg(1078,ios::beg);
        while(!monFlux.eof()) {
            for (int i = 0; i < tailleDePixel; i++) {
                monFlux.read((char*) &pixels[i], sizeof(double));
            }
        }



    }
    else{
        cerr<< "ERREUR: Impossible d'ouvrir le fichier en lecture." <<endl
        ;exit(1);
    }


    // lecture des labels
    label = new char[100];
    for(int j=0;j<8;j++){
        label[j]='a';
    }

}

// prend en entée un entier correspond a l'indice du pixel
// un pixel c'est un niveau de gris (une valeur entre 0 et 255)
double &Image::operator[](int i) {
    return pixels[i];
}

Image::~Image() = default;
