# Réseaux de neuronnes en C++
> ## Objectif :
Le projet consiste à implémenter un réseau de neurones capable d’apprendre à classifier des images en fonction de leurs contenus.
</br>
On a deux types d'images :
</br>1 - des images qui contiennent des dessins de chiffres
</br>2 - des fichiers qui contiennent des caractéristiques de la fleur Iris. 

> ## Données :
- 60000 images de chiffres.
- 150 fichiers de caractéristiques de la fleur Iris

> ## Solutions :
Nous utilisons l'algorithme Perceptron afin de classifier les images selon les types d'images. Ensuite nous comparons les 2 algorithmes d'apprentissage
qui sont : 
- Perceptron  sans couche cachée
- Perceptron  avec une couche cachée

> ## Résultats :
Les algorithmes tournent correctement et les résultats sont cohérents.
1. Première solution (NN1) Perceptrons  sans couche cachée :
	- Pour la classe Iris, le taux de réussite est de 100% 
	- Pour la classe Image, un taux de réussite est de 78%
2. Seconde solution Perceptron multicouches avec une couche cachée (NN2) :
	- Pour la classe Iris,le taux de réussite est de 100%.
	- Pour la classe Image, un taux de réussite est de 91%

> ## Utilisation :

>## Utilisation 2 : 
Telecharger le projet dans un éditeur C++ (Clion pâr exemple) et executer la class Test avec cos propres parametres.
