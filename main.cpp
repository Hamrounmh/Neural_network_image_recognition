#include <iostream>
using namespace std;
#include "Tests/Point.h"
#include "Sources/Bib/Iris.h"

int main() {

    //test de l'ouverture de toute les iris:
    for(int i=0;i<150;i++){
        Iris ir = Iris(i);
        cout<< ir.get_label()<<"---->" << '['<<ir[0]<<',' <<ir[1]<<',' << ir[2]<<',' << ir[3]<<']'<< "---->"<<i <<"\n";
    }


    return 0;
}