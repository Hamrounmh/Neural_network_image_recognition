//
// Created by ahmed on 12/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_IMAGE_H
#define IMAGES_CLASSIFICATION_IA_IMAGE_H


class Image: public Input {

private:
    static const int tailleDePixel= 28 * 28;
    char pixels[tailleDePixel];

public:
    Image(int);
    ~Image();
    static void get_description(int i);
    double  operator[](int);

};


#endif //IMAGES_CLASSIFICATION_IA_IMAGE_H
