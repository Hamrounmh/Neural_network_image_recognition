//
// Created by hamro on 12/03/2021.
//


#include "Bib/Iris.h"

Iris::Iris(char car) {

    int integerPosition = car < 0 ? car+256 : car ;
    Service sc = Service();
    ifstream in =  sc.readFile(sc.FILE_PATH_IRIS,  integerPosition);
    label = new char[100];
    int i = 0;
    char line[100];
    in.getline(line,100);

    char * pch = strtok (line,",");
    while (pch != nullptr)
    {
    if(i<taille_description){
        *(description+i) = atof(pch);
        i++;
    }else{
        strcpy(label,pch);
    }
    pch = strtok (nullptr, ",");
    }
    in.close();
}

Iris::~Iris() = default;

void Iris::get_description(int i) {
    Iris ir = Iris(i);
    cout<< ir.get_label()<<"---->" << '['<<ir[0]<<',' <<ir[1]<<',' << ir[2]<<',' << ir[3]<<']'<< "---->"<<i <<"\n";
}

double &Iris::operator[]( int i ) {
    return *(description+i);
}
