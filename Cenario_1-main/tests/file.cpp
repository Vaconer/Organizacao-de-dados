#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream Arquivo("output.txt");

    int i;

    Arquivo << "test\n";

    for(i=0; i<10;i++)
        Arquivo << i;
}