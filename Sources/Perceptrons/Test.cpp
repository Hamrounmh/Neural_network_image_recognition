//
// Created by hamro on 05/06/2021.
//

#include "../Libraries/Test.h"
#include "../Libraries/PatronApprentissage.h"

int main() {

Service sc = Service();
NN1 *nn1 = new NN1(4,  3);

PatronApprentissage patronApprentissage = PatronApprentissage("iris", 150, nn1);
patronApprentissage.apprendre_base(15000,0.1);


int result = patronApprentissage.evaluer();


cout << "le resultat de l'evaluation est de : " << result ;
return 0;
}