cmake_minimum_required(VERSION 3.17)
project(Images_classification_IA)

set(CMAKE_CXX_STANDARD 14)

add_executable(Images_classification_IA main.cpp Sources/Inputs/Input.cpp Libraries/Input.h Sources/Inputs/Iris.cpp Libraries/Iris.h Sources/Inputs/Image.cpp Libraries/Image.h Sources/Services/Service.cpp Libraries/Service.h Sources/Fonction_activations/Fonction_activation.cpp Libraries/Fonction_activation.h Sources/Fonction_activations/Tanh.cpp Libraries/Tanh.h Sources/Fonction_activations/Sigmoide.cpp Libraries/Sigmoide.h Sources/IA/Perceptron.cpp Libraries/Perceptron.h Sources/IA/NN1.cpp Libraries/NN1.h Sources/IA/Apprentissage.cpp Libraries/Apprentissage.h Sources/Tests/Test.cpp Libraries/Test.h Sources/IA/Perceptron_hidden.cpp Libraries/Perceptron_hidden.h Sources/Inputs/Input_intermediaire.cpp Libraries/Input_intermediaire.h Sources/IA/NN2.cpp Libraries/NN2.h)