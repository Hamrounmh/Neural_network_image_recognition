#include <iostream>
#include <random>
#include <chrono>

using namespace std;
#include "Sources/Libraries/Iris.h"
#include "Sources/Libraries/Image.h"
#include "Sources/Libraries/Tanh.h"
#include "Sources/Perceptrons/Perceptron.h"

int main() {

    //test de l'ouverture de toute les iris:p

   /*for(int i=0;i<150;i++){
        Iris::get_description(i);
    }*/

    //Image::get_description(10);
    //Iris::get_description(54);


//    Image im =  Image(10);
//    cout << "label :"<<im.get_label()<<'\n';
//      for ( int i=0; i<28*28;i++){
//          cout << "pixel " <<i <<":"<<im[i]<<'\n';
//      }

//    for ( int i=0; i<28*28;i++){
//        Image im =  Image(i);
//        cout << "label :"<<im.get_label()<<'\n';
//    }

Tanh tangante =  Tanh();

Perceptron perceptron= Perceptron(4,(tangante),"Iris_Setosa");

    return 0;




}