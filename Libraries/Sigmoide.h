//
// Created by hamro on 14/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_SIGMOIDE_H
#define IMAGES_CLASSIFICATION_IA_SIGMOIDE_H
#include "Fonction_activation.h"

class Sigmoide : public Fonction_activation{
public:
        Sigmoide();
        double  prim(double);
        double  operator ()(double);
        virtual ~Sigmoide();
};



#endif //IMAGES_CLASSIFICATION_IA_SIGMOIDE_H
