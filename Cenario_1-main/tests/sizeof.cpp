#include "..\lib\dataTypes.h"

unsigned int divider(unsigned int size){
    return size / 1024;
}

int main(void){
    // function sizeof() returns value in bytes

    unsigned int tamanho = sizeof(Registro);
    tamanho *= 1000000;

    cout<< "Tamanho: " << tamanho << " em bytes\n";

    tamanho = divider(tamanho);
    cout<< "Tamanho: " << tamanho << " em kilobytes\n";

    tamanho = divider(tamanho);
    cout<< "Tamanho: " << tamanho << " em megabytes\n";

    tamanho = divider(tamanho);
    cout<< "Tamanho: " << tamanho << " em gigabytes\n";
}