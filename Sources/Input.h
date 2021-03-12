//
// Created by hamro on 12/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_INPUT_H
#define IMAGES_CLASSIFICATION_IA_INPUT_H


class Input {
private:
    char* label;
public:

    virtual double & operator [](int) = 0 ;
    char* get_label();
};


#endif //IMAGES_CLASSIFICATION_IA_INPUT_H
