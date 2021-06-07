//
// Created by hamro on 05/06/2021.
//

#include "../../Libraries/Test.h"
#include "../../Libraries/Apprentissage.h"
#include "../../Libraries/Sigmoide.h"
// TODO : ici c'est une note pour ne pas oublier d'inclure le source de patron apprentissage afin d'éeviter le beug des templates undifined
#include "../IA/Apprentissage.cpp"

const double LEARNING_RATE_IMAGE = 1.;
const double LEARNING_RATE_IRIS = 0.1;
const int K_ITERATION_IMAGE_TRAINING = 100 000;
const int K_ITERATION_IRIS_TRAINING = 15 000;



double  learnIris(){
    Service sc = Service();
    int result;
    double pourcentage;

        NN1 *nn1 = new NN1(sc.SIZE_CARACTERESTIQUES_IRIS, sc.SIZE_CATEGORIES_IRIS,new Sigmoide());
        Apprentissage<Iris,sc.DATA_SIZE_IRIS> patronApprentissage( nn1);
        patronApprentissage.apprendre_base(K_ITERATION_IRIS_TRAINING,LEARNING_RATE_IRIS);

        result= patronApprentissage.evaluer();
        pourcentage = (result / (double)sc.DATA_SIZE_IRIS) * 100;


    cout << "le resultat de l'evaluation des fleurs est de : " <<pourcentage  <<"%\n"  ;

    return pourcentage;
}

double learnImage(){

    Service sc = Service();
    NN1 *nn1 = new NN1(sc.SIZE_CARACTERESTIQUES_IMAGE, sc.SIZE_CATEGORIES_IMAGE,new Sigmoide());

    Apprentissage<Image,sc.DATA_SIZE_IMAGE> patronApprentissage(  nn1);
    patronApprentissage.apprendre_base(K_ITERATION_IMAGE_TRAINING,LEARNING_RATE_IMAGE);
    int result = patronApprentissage.evaluer();

    double pourcentage = (result / (double)sc.DATA_SIZE_IMAGE) * 100;
    cout << "le resultat de l'evaluation des images est de : " <<pourcentage  <<"%\n"  ;
return pourcentage;

}


int main() {
    double resultOfLearning;
    double aimedRate = 95;

    do {
         resultOfLearning= learnIris();
    }while(resultOfLearning<aimedRate);




return 0;
}
