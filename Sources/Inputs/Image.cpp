//
// Created by ahmed on 12/03/2021.
//

#include "../Libraries/Input.h"
#include "../Libraries/Image.h"
#include <iostream>

using namespace std;
double  pixel;

//TODO : trouver comment implémenter les labels des  images comme les labels sont des char
// prend en entrée un entier correspond a l'indice de l'image (0,1 .....59999)
Image::Image(int index) {

    //label = new char[100];
    char * label_of_str = new char [100];
    char  pixel;
    int i = 0;
    char line;


    Service sc = Service();
    ifstream monFlux=  sc.readFile(sc.FILE_PATH_TRAINING,  index);
    ifstream monFluxLabel(sc.FILE_PATH_LABEL, ios ::binary);


    if(monFlux.good()){
        // se placer en 1078 octect a partir du debut de fichier
        monFlux.seekg(1078,ios::beg);
        while(!monFlux.eof()) {
            for (int i = 0; i < tailleDePixel; i++) {
                monFlux.read((char*) &pixels[i], sizeof(char));

            }
        }
    }
    else{
        cerr<< "ERREUR: Impossible d'ouvrir le fichier en lecture." <<endl
        ;exit(1);
    }

    char labelresult[1];
    if(monFluxLabel.good()){
        int indexRead=8+index;
        monFluxLabel.seekg(indexRead,ios::beg);
        monFluxLabel.read((char*) &line, sizeof(char));
        sprintf(labelresult, "%d", line);
        strcpy(label_of_str,labelresult);
    } else{
        cerr<< "ERREUR: Impossible d'ouvrir le fichier en lecture." <<endl
        ;exit(1);
    }
    monFluxLabel.close();
    monFlux.close();

     //lecture des labels
        label = Service::assigneLabelValuesImages(label_of_str);
}

// prend en entée un entier correspond a l'indice du pixel
// un pixel c'est un niveau de gris (une valeur entre 0 et 255)
double Image::operator[](int i) {
    pixel= pixels[i]<0 ?  pixels[i]+256 : pixels[i];
    return pixel;

}

void Image::get_description(int i) {
    Image im = Image(i);
    for (int i = 0; i < 28*28; i++)
    {
        if(im[i] != 0.)
            cout << "*" << "\t";
        else
            cout << " " << "\t";
        if(i%28 == 0 )
            cout<<endl;

    }
}




Image::~Image() = default;
