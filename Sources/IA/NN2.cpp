//
// Created by HAO1DY2 on 09/06/2021.
//

#include <unistd.h>
#include "../../Libraries/NN2.h"
#include "../../Libraries/Input_intermediaire.h"



NN2::NN2(int inputSize, int outLayerSize_CategoriesNumber, int hiddenLayerSize, Fonction_activation *fct) {

    for(int i = 0 ; i< outLayerSize_CategoriesNumber ; i++) {
        outLayerPerceptron.push_back(new Perceptron(inputSize,fct ,'0' + i));
        //ici le sleep est a cause du random qui utilise le chrono
        sleep(0.1);
    }

    for(int i = 0 ; i< hiddenLayerSize ; i++) {
        hiddenLayerPerceptrons.push_back(new Perceptron_hidden(inputSize,fct ,'0' + i, outLayerPerceptron));
        //ici le sleep est a cause du random qui utilise le chrono
        sleep(0.1);
    }

}

char NN2::evaluation(Input *input) {

    Input_intermediaire * input_intermediaire = new Input_intermediaire(input->get_label()) ;
    for(int i = 0 ; i<hiddenLayerPerceptrons.size() ; i++){
            double valueInput_a = hiddenLayerPerceptrons[i]->forward(input);
            input_intermediaire->add(valueInput_a);
        }
    double valueFirstEvaluation  = outLayerPerceptron[0]->forward(input_intermediaire);
    char labelFirstEvaluation  = outLayerPerceptron[0]->getLabel();

    for(int i = 0 ; i<outLayerPerceptron.size() ; i++){
            double nextValuePerceptron = outLayerPerceptron[i]->forward(input_intermediaire);
            if(nextValuePerceptron > valueFirstEvaluation){
                labelFirstEvaluation = outLayerPerceptron[i]->getLabel();
                valueFirstEvaluation=nextValuePerceptron;
            }
        }
    return labelFirstEvaluation;
}

void NN2::apprentissage(Input *input, double learningrate) {
    Input_intermediaire * input_intermediaire = new Input_intermediaire(input->get_label()) ;
    for(int i = 0 ; i<hiddenLayerPerceptrons.size() ; i++){
        double valueInput_a = hiddenLayerPerceptrons[i]->forward(input);
        input_intermediaire->add(valueInput_a);
    }
    for(int i = 0; i<outLayerPerceptron.size();i++)
        outLayerPerceptron[i]->calcul_delta(input_intermediaire);

    for(int i = 0; i<hiddenLayerPerceptrons.size();i++)
        hiddenLayerPerceptrons[i]->calcul_delta(input);


    for(int i = 0; i<hiddenLayerPerceptrons.size();i++)
        hiddenLayerPerceptrons[i]->backprop(input,learningrate);

    for(int i = 0; i<outLayerPerceptron.size();i++)
        outLayerPerceptron[i]->backprop(input_intermediaire,learningrate);


}
