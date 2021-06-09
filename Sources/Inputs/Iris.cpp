//
// Created by hamro on 12/03/2021.
//


#include "../../Libraries/Iris.h"

Iris::Iris(int integerPosition) {


    Service sc = Service();
    ifstream in =  sc.readFile(sc.FILE_PATH_IRIS,  integerPosition);
   char* label_file_str = new char[100];
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
        strcpy(label_file_str,pch);
    }
    pch = strtok (nullptr, ",");
    }
    in.close();
    label = Service::assigneLabelValuesIris(label_file_str);
}

Iris::~Iris() = default;

void Iris::get_description(int i) {
    Iris ir = Iris(i);
    cout<< ir.get_label()<<"---->" << '['<<ir[0]<<',' <<ir[1]<<',' << ir[2]<<',' << ir[3]<<']'<< "---->"<<i <<"\n";
}

double Iris::operator[]( int i ) {
    return *(description+i);
}
