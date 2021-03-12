#include <iostream>
using namespace std;
#include "Tests/Point.h"
#include "Sources/Bib/Iris.h"

int main() {
    Point p1 = Point(0, 0);
    Iris ir = Iris('c');

    cout << ir[2];


    return 0;
}