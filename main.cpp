#include <iostream>
#include <random>
#include <chrono>
#include <unistd.h>

using namespace std;
#include "Sources/Libraries/Iris.h"
#include "Sources/Libraries/Image.h"
#include "Sources/Libraries/Tanh.h"
#include "Sources/Libraries/Perceptron.h"

int main2() {

    //test de l'ouverture de toute les iris:p

  /* for(int i=0;i<150;i++){
        Iris::get_description(i);
    }
*/
    //Image::get_description(10);
    //Iris::get_description(54);



//    Image im =  Image(10);
//    cout << "label :"<<im.get_label()<<'\n';
//      for ( int i=0; i<28*28;i++){
//          cout << "pixel " <<i <<":"<<im[i]<<'\n';
//      }

    /*for ( int i=0; i<60000;i++){
        Image im =  Image(i);
        cout << "label :"<<im.get_label()<<'\n';
    }*/

//Fonction_activation  *tangante = new Tanh();
//Input *iris=new Iris(4);
//
//Perceptron perceptron= Perceptron(4,tangante,'c');
//cout << perceptron.get_poids(0);

/*Mat img = imread("image.jpg");
namedWindow("image", WINDOW_AUTOSIZE);
imshow("image", img);
waitKey();*/






return 0;





}