//
// Created by ahmed on 12/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_IMAGE_H
#define IMAGES_CLASSIFICATION_IA_IMAGE_H


class Image: public Input {

private:
    static const int tailleDePixel= 28 * 28;
    char pixels[tailleDePixel];
    char PATH[1000] = "../Data/MNIST_training/training";

public:
    Image(int);
    ~Image();
    double & operator[](int);


};


#endif //IMAGES_CLASSIFICATION_IA_IMAGE_H
