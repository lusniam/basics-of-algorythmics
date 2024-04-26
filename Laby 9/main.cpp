#include <iostream>
#include <fstream>

using namespace std;

struct element{
    int character;
    element* next;
};

struct queue{
    element* head;
    element* tail;
};

void push(queue *&q, int value){
    element* el = new element;
    el->character=value;
    el->next=nullptr;
    if(q->tail!=nullptr)    q->tail->next=el;
    else    q->head=el;
    q->tail=el;
}

int pop(queue *&q){
    element* temp = q->head;
    int value = temp->character;
    q->head=q->head->next;
    delete temp;
    if(q->head==nullptr)    q->tail=nullptr;
    return value;
}

bool isEmpty(queue *q){    return q->head==nullptr;    }

int first(queue *q){    return q->head->character;    }

void f6(queue *&q){
    ifstream plik("../znaki2.txt");
    while(true){
        char znak=plik.get();
        if(znak==EOF)   break;
        else if(znak>='A'&&znak<='Z'){
            push(q,znak);
        }
    }
    cout<<"Dodano litery z pliku do kolejki"<<endl;
}

int Zadanie1(queue* q){
    if(isEmpty(q))  return 0;
    int count=0;
    queue* temp=new queue;
    temp->head=nullptr;
    temp->tail=nullptr;
    while(!isEmpty(q))    push(temp,pop(q));
    while(!isEmpty(temp)){
        int val=pop(temp);
        if(val%3==0)    count++;
        push(q,val);
    }
    delete temp;
    return count;
}

int main() {
    srand(time(0));
    queue *q=new queue;
    q->head=nullptr;
    q->tail=nullptr;
    int wybor;
    do{
        system("cls");
        cout<<"Menu:\n1) sprawdzenie, czy kolejka jest pusta\n2) dodanie elementu do kolejki\n3) usuniecie elementu z kolejki"<<endl;
        cout<<"4) pobranie elementu z kolejki\n5) usuniecie wszystkich elementow z kolejki\n6) wczytanie liter z pliku 'znaki2.txt'\n7) wyjscie"<<endl;
        cin>>wybor;
        cout<<endl;
        switch(wybor){
            case 1: {
                cout<<"Kolejka ";
                if(!isEmpty(q)) cout<<"nie ";
                cout<<"jest pusta";
                break;
            }
            case 2: { 
                int val=rand()%60;
                push(q,val);
                cout<<"Dodano element "<<val<<" na poczatek kolejki"<<endl;
                break;
            }
            case 3: { 
                if(isEmpty(q))    cout<<"Kolejka jest pusta, nie da sie usunac elementu"<<endl;
                else{
                    cout<<"Usuwam element "<<first(q)<<" z kolejki"<<endl;
                    pop(q);
                }
                break;
            }
            case 4: {
                if(isEmpty(q))    cout<<"Kolejka jest pusta, nie ma elementu do wyswietlenia"<<endl;
                else    cout<<"Pierwszy element w kolejce to "<<first(q)<<endl;
                break;
            }
            case 5: {
                while(!isEmpty(q)){
                    cout<<"Usuwam element "<<first(q)<<" z kolejki"<<endl;
                    pop(q);
                }
                cout<<"Kolejka jest pusta"<<endl;
                break;
            }
            case 6: {f6(q); break;}
            case 7: {cout<<Zadanie1(q)<<endl; break;}
            default: break;
        }
        cout<<endl;
        system("pause");
    }while(wybor!=8);
    return 0;
}
