#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct element{
    int number;
    element* next;
};

void push(element* &stack,int value){
    element* el=new element;
    el->number=value;
    el->next=stack;
    stack=el;
}

bool isEmpty(element* stack){    return stack==nullptr;    }

void pop(element* &stack){
    element* temp=stack;
    stack=stack->next;
    delete temp;
}

int top(element* stack){    return stack->number;   }

void funkcja1(element* &stack){
    if(isEmpty(stack))    cout<<"Stos jest pusty"<<endl;
    else    cout<<"Stos nie jest pusty"<<endl;
}

void funkcja2(element* &stack){
    push(stack,1+rand()%10);
    cout<<"Dodano liczbe "<<stack->number<<" na stos"<<endl;
}

void funkcja3(element* &stack){
    if(isEmpty(stack))    cout<<"Stos jest pusty"<<endl;
    else{
        cout<<"Usuwam liczbe "<<stack->number<<" ze stosu"<<endl;
        pop(stack);
    }
}

void funkcja4(element* &stack){
    if(isEmpty(stack))    cout<<"Stos jest pusty"<<endl;
    else    cout<<"Ostatni element ze stosu: "<<top(stack)<<endl;
}

void funkcja5(element* &stack){
    while(!isEmpty(stack))    pop(stack);
    cout<<"Oczyszczono stos"<<endl;
}

void Zad2(){
    ifstream plik("../znaki1.txt");
    ofstream wynik("../wynik.txt");
    string linia;
    element* stack=nullptr;
    while(plik.good()){
        getline(plik,linia);
        for(int i=0;i<linia.length();i++){
            push(stack,(int)linia[i]);
        }
        while(!isEmpty(stack)){
            wynik<<(char)top(stack);
            pop(stack);
        }
        wynik<<endl;
    }
    delete stack;
    plik.close();
    wynik.close();
}

int main() {
    srand(time(0));
    element* stack=nullptr;
    int wybor;
    do{
        system("cls");
        cout<<"Menu:\n1) sprawdzenie, czy stos jest pusty\n2) dodanie elementu na stos\n3) usuniecie elementu ze stosu"<<endl;
        cout<<"4) pobranie elementu ze stosu\n5) usuniecie wszystkich elementow ze stosu\n6) zadanie 9.2\n0) wyjscie"<<endl;
        cin>>wybor;
        cout<<endl;
        switch(wybor){
            case 1: {funkcja1(stack); break;}
            case 2: {funkcja2(stack); break;}
            case 3: {funkcja3(stack); break;}
            case 4: {funkcja4(stack); break;}
            case 5: {funkcja5(stack); break;}
            case 6: {Zad2(); break;}
            default: break;
        }
        cout<<endl;
        system("pause");
    }while(wybor!=0);
    delete stack;
    return EXIT_SUCCESS;
}
