//
// Created by hamro on 05/06/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_PATRONAPPRENTISSAGE_H
#define IMAGES_CLASSIFICATION_IA_PATRONAPPRENTISSAGE_H

#include "NN1.h"
#include "../Libraries/Input.h"
#include "../Libraries/Image.h"
#include "../Libraries/Iris.h"
class PatronApprentissage {
private :
    NN1 * nn1;
    int exemplesNumberForInput;
    char * serviceNameInput ;
public :
    PatronApprentissage(char*, int, NN1 * );
   void apprendre_base(int k_iterations, double learningRate);
    int evaluer();

};


#endif //IMAGES_CLASSIFICATION_IA_PATRONAPPRENTISSAGE_H
