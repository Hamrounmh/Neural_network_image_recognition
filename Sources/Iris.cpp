//
// Created by hamro on 12/03/2021.
//


#include "Bib/Iris.h"


Iris::Iris(char car) {

label = new char[100];
int i = 0;
char filePosition[5] ;
char line[100];
int integerPosition = car < 0 ? -1*car : car ;

sprintf(filePosition, "%d", integerPosition);
strcat(FILE_PATH,filePosition);
ifstream in(FILE_PATH, ios ::binary);


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

double* Iris::get_description() {
    return description;
}

//Iris ir = new Iris();
//ir[2]  =descritpiton[2]
double &Iris::operator[](int i ) {
    return *(description+i);
}