#include <iostream>
using namespace std;
#include "Sources/Libraries/Iris.h"
#include "Sources/Libraries/Image.h"

int main() {

    //test de l'ouverture de toute les iris:p

   /*for(int i=0;i<150;i++){
        Iris::get_description(i);
    }*/

   Image::get_description(52);
   /*Image im =  Image(10);
   cout << "label :"<<im.get_label()<<'\n';
     for ( int i=0; i<28*28;i++){
         cout << "pixel " <<i <<":"<<im[i]<<'\n';
     }
     */




    return 0;




}