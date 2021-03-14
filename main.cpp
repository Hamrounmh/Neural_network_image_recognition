#include <iostream>
using namespace std;
#include "Sources/Bib/Iris.h"
#include "Sources/Bib/Image.h"

int main() {

    //test de l'ouverture de toute les iris:p
    Iris ir = Iris();
   for(int i=0;i<150;i++){
        ir.get_description(i);
    }


/*
    Image im = Image(9);

    for( i=0;i<(28*28);i++){
        cout << "pixel "<< i<<"= "<<im[i]<<"\n";
    }*/
    //cout<< im.get_label();

    return 0;




}