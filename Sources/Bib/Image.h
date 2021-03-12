//
// Created by ahmed on 12/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_IMAGE_H
#define IMAGES_CLASSIFICATION_IA_IMAGE_H


class Image: public Input {

private:
    static const int tailleDePixel= 28 * 28;
    double pixels[tailleDePixel];
    char PATH[1000] = "/home/ahmed/CLionProjects/Images_classification_IA/Data/MNIST_training/training";

public:
    Image(int);
    ~Image();
    double & operator[](int);


};


#endif //IMAGES_CLASSIFICATION_IA_IMAGE_H
