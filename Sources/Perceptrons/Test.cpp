//
// Created by hamro on 05/06/2021.
//

#include "../Libraries/Test.h"
#include "../Libraries/PatronApprentissage.h"
#include "../Libraries/Sigmoide.h"

int main() {

Service sc = Service();
NN1 *nn1 = new NN1(4,  3);

PatronApprentissage patronApprentissage = PatronApprentissage("iris", 150, nn1);
patronApprentissage.apprendre_base(15000,0.1);


int result = patronApprentissage.evaluer();

//Input * iris = new Iris(15);
//char res =  nn1->evaluation(iris);
//cout << "la pridiction est " <<res <<"\n";

double pourcentage = (result / 150.) * 100;
cout << "le resultat de l'evaluation est de : " <<pourcentage  <<"%"  ;

//    Fonction_activation * fct =  new Sigmoide();
//    int i = 5.6;
//    int x = (*fct)(i);
//cout << x<<"\n";
//cout<<(*fct)(i);


return 0;
}