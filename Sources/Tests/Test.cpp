//
// Created by hamro on 05/06/2021.
//

#include "../../Libraries/Test.h"
#include "../../Libraries/Apprentissage.h"
#include "../../Libraries/Sigmoide.h"
// TODO : ici c'est une note pour ne pas oublier d'inclure le source de patron apprentissage afin d'éeviter le beug des templates undifined
#include "../IA/Apprentissage.cpp"
#include "../../Libraries/Perceptron_hidden.h"
#include "../../Libraries/NN2.h"

const double LEARNING_RATE_IMAGE = 0.1;
const double LEARNING_RATE_IRIS = 0.01;
const int K_ITERATION_IMAGE_TRAINING = 100000;
const int K_ITERATION_IRIS_TRAINING = 10000;



double  learnIrisNN1(){
    Service sc = Service();

    NN1 *nn1 = new NN1(sc.SIZE_CARACTERESTIQUES_IRIS, sc.SIZE_CATEGORIES_IRIS,new Sigmoide());
    Apprentissage<Iris,sc.DATA_SIZE_IRIS,NN1> patronApprentissage( nn1);
    patronApprentissage.apprendre_base(K_ITERATION_IRIS_TRAINING,LEARNING_RATE_IRIS);

    int result= patronApprentissage.evaluer();
    double pourcentage =  (result / (double)sc.DATA_SIZE_IRIS) * 100;


    cout << "le resultat de l'evaluation des fleurs est de : " <<pourcentage  <<"%\n"  ;

    return pourcentage;
}

double  learnIrisNN2(){
    Service sc = Service();

    NN2 *nn2 = new NN2(sc.SIZE_CARACTERESTIQUES_IRIS, sc.SIZE_CATEGORIES_IRIS,sc.SIZE_CARACTERESTIQUES_IRIS,new Sigmoide());
    Apprentissage<Iris,sc.DATA_SIZE_IRIS,NN2> patronApprentissage( nn2);
    patronApprentissage.apprendre_base(K_ITERATION_IRIS_TRAINING,LEARNING_RATE_IRIS);

    int result= patronApprentissage.evaluer();
    double pourcentage =  (result / (double)sc.DATA_SIZE_IRIS) * 100;


    cout << "le resultat de l'evaluation des fleurs est de : " <<pourcentage  <<"%\n"  ;

    return pourcentage;
}

double learnImageNN1(){

    Service sc = Service();
    NN1 *nn1 = new NN1(sc.SIZE_CARACTERESTIQUES_IMAGE, sc.SIZE_CATEGORIES_IMAGE,new Sigmoide());

    Apprentissage<Image,sc.DATA_SIZE_IMAGE,NN1> patronApprentissage(nn1);
    patronApprentissage.apprendre_base(K_ITERATION_IMAGE_TRAINING,LEARNING_RATE_IMAGE);
    int result = patronApprentissage.evaluer();

    double pourcentage = (result / (double)sc.DATA_SIZE_IMAGE) * 100;
    cout << "le resultat de l'evaluation des images est de : " <<pourcentage  <<"%\n"  ;
    delete nn1;
return pourcentage;

}

double learnImageNN2(){

    Service sc = Service();
    NN2 *nn2 = new NN2(sc.SIZE_CARACTERESTIQUES_IMAGE, sc.SIZE_CATEGORIES_IMAGE,sc.SIZE_CARACTERESTIQUES_IMAGE,new Sigmoide());

    Apprentissage<Image,sc.DATA_SIZE_IMAGE,NN2> patronApprentissage(nn2);
    patronApprentissage.apprendre_base(K_ITERATION_IMAGE_TRAINING,LEARNING_RATE_IMAGE);
    int result = patronApprentissage.evaluer();

    double pourcentage = (result / (double)sc.DATA_SIZE_IMAGE) * 100;
    cout << "le resultat de l'evaluation des images est de : " <<pourcentage  <<"%\n"  ;
return pourcentage;

}


int main() {
    double resultOfLearning;
    double aimedRate = 101;


    resultOfLearning= learnImageNN2();
//    resultOfLearning= learnIrisNN2();
    //resultOfLearning= learnImageNN1();
//    resultOfLearning= learnIrisNN1();







return 0;
}
