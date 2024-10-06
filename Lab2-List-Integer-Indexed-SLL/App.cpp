#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main(){
    testAll();
    cout<<"Finished Short LI Tests!"<<endl;
    testAllExtended();
    cout<<"Finished LI Tests!"<<endl;
}
