#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

// ------------------------------------------------------------
// Lib made to be compatable with the C++ language
// Implementation of the Double Linked List data structure
// Implementation is meant to be simple and close to C lang.
// but, with the use of some aspects of C++
#include <iostream>

// ------------------------------------------------------------

struct List {
    struct Node* first;
    struct Node* last;
};

struct Node {
    int data;
   
    struct Node* next;
    struct Node* prev;
};

// ------------------------------------------------------------

int isEmpty(List l){
    return (l.first == l.last);
}

void start(List &l){
    l.first = new Node;
    l.last = l.first;
    l.first->next = 0;
    l.first->prev = 0;
}

void insert(List &l, int num){
    Node* aux = l.last;
    l.last->next = new Node;

    l.last = l.last->next;
    l.last->data = num;
    l.last->next = 0;
    l.last->prev = aux;
}

void watch(List l){
    Node* aux = l.first->next;
    int i = 0;
    while(aux != 0){
        printf("%d\t%d\n", i, aux->data);
        aux = aux->next;
        i++;
    }
}

void restart(List &l){
    // auto temp = l.first;

    // while (l.first != NULL){
    //     temp = l.first;
    //     l.first = l.first->next;
    //     l.first->prev = 0;
    //     delete temp;
    // }

    // start(l);

    Node* aux = l.first->next;
    Node* pro = 0;

    while(aux != 0){
        pro = aux->next;

        delete aux;
        aux = pro;
    }
    l.first = 0;
    l.last = 0;
    start(l);
}

void ListToArray(List l, int *arr){
    Node *aux = l.first->next, *delAux = 0;
    int i = 0;

    l.first = 0;
    l.last = 0;

    while(aux != 0){
        arr[i] = aux->data;
        i++;

        delAux = aux;
        delAux->prev = 0;
        delAux->next = 0;
        delAux->data = 0;
        aux = aux->next;
        free(delAux);
    }

    start(l);
}

Node* index(List l, int num){
    Node* aux = l.first->next;

    if(num == 0)
        return aux;
    
    int cont = 0;
    while(aux != 0){
        aux = aux->next;
        cont++;

        if(cont == num)
            return aux;
    }
    return 0;
}

void copy(List &l, Node* aux){
    int num; // data structure to be copied

    num = aux->data;

    insert(l, num);
}

void swapItem(List &l, List &f, int ind1, int ind2){
    Node* aux1;
    Node* aux2;

    aux1 = index(l, ind1);
    aux2 = index(f, ind2);

    int temp = aux1->data;
    aux1->data = aux2->data;
    aux2->data = temp;
}

#endif