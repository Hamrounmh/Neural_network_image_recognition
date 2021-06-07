//
// Created by hamro on 05/06/2021.
//

#include "../../Libraries/Apprentissage.h"


template <class input_type_class, int exemplesNumberForInput>
Apprentissage<input_type_class,exemplesNumberForInput> ::Apprentissage(NN1 * p_nn1) {
nn1 = p_nn1;
}

template <class input_type_class, int exemplesNumberForInput>
void Apprentissage<input_type_class,exemplesNumberForInput>::apprendre_base(int k_iterations, double learningRate) {
    Service sc = Service();

for(int i=0; i<k_iterations ;i++){
    int randomInt = sc.generateRandomInt(0,exemplesNumberForInput-1);
    Input * input = new input_type_class(randomInt);
    nn1->apprentissage(input,learningRate);

}

}

template <class input_type_class, int exemplesNumberForInput>
int Apprentissage<input_type_class,exemplesNumberForInput>::evaluer() {
    int cpt = 0;
    char resultEvaluation;
    Service sc = Service();
    char labelInput;

    for(int i = 0; i<exemplesNumberForInput ; i++ ){

    Input *input= new input_type_class(i);
    resultEvaluation= nn1->evaluation(input);
    labelInput =  input->get_label();

    if(resultEvaluation == labelInput)
        cpt ++ ;
    }
    return cpt;
}
