#include <iostream>
using namespace std;
#include "Sources/Bib/Iris.h"
#include "Sources/Bib/Image.h"

int main() {

 /*   //test de l'ouverture de toute les iris:p
   for(int i=0;i<150;i++){
        Iris ir = Iris(i);
        cout<< ir.get_label()<<"---->" << '['<<ir[0]<<',' <<ir[1]<<',' << ir[2]<<',' << ir[3]<<']'<< "---->"<<i <<"\n";
    }*/


    Image im = Image(9);
    int i;
    for( i=0;i<(28*28);i++){
        cout << "pixel "<< i<<"= "<<im[i]<<"\n";
    }
    //cout<< im.get_label();

    return 0;




}