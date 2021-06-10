//
// Created by hamro on 05/06/2021.
//

#include "../../Libraries/Apprentissage.h"


template <class input_type_class, int exemplesNumberForInput,class NeuralNetwork>
Apprentissage<input_type_class,exemplesNumberForInput,NeuralNetwork> ::Apprentissage(NeuralNetwork * p_nn1) {
    neuralNetwork = p_nn1;
}

template <class input_type_class, int exemplesNumberForInput,class NeuralNetwork>
void Apprentissage<input_type_class,exemplesNumberForInput,NeuralNetwork>::apprendre_base(int k_iterations, double learningRate) {
    Service sc = Service();

    for(int i=0; i<k_iterations ;i++){
        int randomInt = sc.generateRandomInt(0,exemplesNumberForInput-1);
        Input * input = new input_type_class(randomInt);
        neuralNetwork->apprentissage(input, learningRate);

        if(i%1000 == 0 )
            cout <<"operation d'apprentissage en cours, apprentissage a : "<< i/1000<<"%\n";
    }
}

template <class input_type_class, int exemplesNumberForInput,class NeuralNetwork>
int Apprentissage<input_type_class,exemplesNumberForInput,NeuralNetwork>::evaluer() {
    int cpt = 0;
    char resultEvaluation;
    char labelInput;

    for(int i = 0; i<exemplesNumberForInput ; i++ ){

        Input *input= new input_type_class(i);
        resultEvaluation= neuralNetwork->evaluation(input);
        labelInput =  input->get_label();

        if(resultEvaluation == labelInput)
            cpt ++ ;
        }
    return cpt;
}
