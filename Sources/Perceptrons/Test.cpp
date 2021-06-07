//
// Created by hamro on 05/06/2021.
//

#include "../Libraries/Test.h"
#include "../Libraries/PatronApprentissage.h"
#include "../Libraries/Sigmoide.h"
PatronApprentissage  learnIris(int aimedRate){
    Service sc = Service();

    int result;
    double pourcentage;
    PatronApprentissage * patronApprentissage;

    do{
        NN1 *nn1 = new NN1(sc.SIZE_CARACTERESTIQUES_IRIS, sc.SIZE_CATEGORIES_IRIS);
        patronApprentissage= new PatronApprentissage(sc.STRING_IRIS, sc.DATA_SIZE_IRIS, nn1);
        patronApprentissage->apprendre_base(15000,0.1);


        result= patronApprentissage->evaluer();
        pourcentage = (result / (double)sc.DATA_SIZE_IRIS) * 100;
    } while (pourcentage < aimedRate);



    cout << "le resultat de l'evaluation est de : " <<pourcentage  <<"%"  ;

    return *patronApprentissage;
}

PatronApprentissage  learnImage(){

    Service sc = Service();
    NN1 *nn1 = new NN1(sc.SIZE_CARACTERESTIQUES_IMAGE, sc.SIZE_CATEGORIES_IMAGE);

    PatronApprentissage patronApprentissage = PatronApprentissage(sc.STRING_IMAGE, sc.DATA_SIZE_IMAGE, nn1);
    patronApprentissage.apprendre_base(100000,1);


    int result = patronApprentissage.evaluer();

    double pourcentage = (result / (double)sc.DATA_SIZE_IRIS) * 100;
    cout << "le resultat de l'evaluation est de : " <<pourcentage  <<"%"  ;
    return patronApprentissage;
}



int main() {


    //PatronApprentissage  patronApprentissageIris = learnIris(80);
    PatronApprentissage  patronApprentissageImage = learnImage();




//Input * iris = new Iris(15);
//char res =  nn1->evaluation(iris);
//cout << "la pridiction est " <<res <<"\n";



//    Fonction_activation * fct =  new Sigmoide();
//    int i = 5.6;
//    int x = (*fct)(i);
//cout << x<<"\n";
//cout<<(*fct)(i);


return 0;
}
