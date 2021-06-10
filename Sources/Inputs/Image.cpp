//
// Created by ahmed on 12/03/2021.
//

#include "../../Libraries/Input.h"
#include "../../Libraries/Image.h"
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
    char FILE_PATH[200];

    char filePosition[5] ;
    sprintf(filePosition, "%d", index);
    strcpy(FILE_PATH,sc.FILE_PATH_TRAINING);
    strcat(FILE_PATH,filePosition);
    ifstream in(FILE_PATH, ios ::in);

   // ifstream in=  sc.readFile(sc.FILE_PATH_TRAINING, index);
    ifstream monFluxLabel(sc.FILE_PATH_LABEL, ios ::binary);


    if(in.good()){
        // se placer en 1078 octect a partir du debut de fichier
        in.seekg(1078, ios::beg);
        while(!in.eof()) {
            for (int i = 0; i < tailleDePixel; i++) {
                in.read((char*) &pixels[i], sizeof(char));

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
    in.close();

     //lecture des labels
        label = Service::assigneLabelValuesImages(label_of_str);
}


// prend en entée un entier correspond a l'indice du pixel
// un pixel c'est un niveau de gris (une valeur entre 0 et 255)
// TODO : verifier si les doubles des pixels retournées sont bon ( si il faut que le pixels soit entre [0,1] ou sinon le garder entre 0 et 255 .
double Image::operator[](int i) {
    double pixel= pixels[i]<0 ?  pixels[i]+256. : (double)pixels[i];
    return pixel/255.;

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
