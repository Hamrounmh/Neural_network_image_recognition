//
// Created by hamro on 05/06/2021.
//


#include "../Libraries/PatronApprentissage.h"


PatronApprentissage::PatronApprentissage(char * p_serviceNameInput, int p_exemplesNumberForInput, NN1 * p_nn1) {
nn1 = p_nn1;
    serviceNameInput= p_serviceNameInput;
    exemplesNumberForInput=p_exemplesNumberForInput;
}

void PatronApprentissage::apprendre_base(int k_iterations, double learningRate) {
    Service sc = Service();
    Input *input;

for(int i=0; i<k_iterations ;i++){
    int randomInt = sc.generateRandomInt(0,exemplesNumberForInput);
    if(strcmp(serviceNameInput,"image") == 0){
        input= new Image(randomInt);
    }else{
        input= new Iris(randomInt);
    }

    nn1->apprentissage(input,learningRate);
}

}

int PatronApprentissage::evaluer() {
    int cpt = 0;
    char resultEvaluation;
    Input *input;
    Service sc = Service();

    for(int i = 0; i<exemplesNumberForInput ; i++ ){
        if(strcmp(serviceNameInput,"image") == 0){
            input= new Image(i);
        }else{
            input= new Iris(i);
        }

        resultEvaluation= nn1->evaluation(input);
        char labelInput =  input->get_label();


        if(resultEvaluation == labelInput)
            cpt ++ ;
    }
    return cpt;
}
