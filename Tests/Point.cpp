//
// Created by hamro on 12/03/2021.
//

#include "Point.h"
int Point::nbr = 0 ;
Point :: Point(int abs , int ord ){
    x = abs;
    y=ord;
    nbr=nbr+1;
}
Point::~Point() {
    nbr -- ;
}