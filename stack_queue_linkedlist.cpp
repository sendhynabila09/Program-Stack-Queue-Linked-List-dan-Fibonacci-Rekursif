#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;
Node* front = NULL;
Node* rear = NULL;

void push(int data){
    Node* baru = new Node();
    baru->data = data;
    baru->next = top;
    top = baru;

    cout << "Push: " << data << endl;
}

void pop(){
    if(top == NULL){
        cout << "Stack kosong\n";
    } else {
        Node* hapus = top;
        top = top->next;
        delete hapus;
    }
}

void enqueue(int data){
    Node* baru = new Node();
    baru->data = data;
    baru->next = NULL;

    if(front == NULL){
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Enqueue: " << data << endl;
}

void dequeue(){
    if(front == NULL){
        cout << "Queue kosong\n";
    } else {
        Node* hapus = front;
        front = front->next;
        delete hapus;
    }
}

void display() {

    Node* temp = top;
    cout << "Isi Stack: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    temp = front;
    cout << "Isi Queue: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main(){
    push(10);
    push(20);
    pop();
    display();

    enqueue(5);
    enqueue(7);
    dequeue();
    display();

    return 0;
}