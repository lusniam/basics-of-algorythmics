//Stos

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


// Kolejka
#include <iostream>
#include <fstream>

using namespace std;

struct element{
    char character;
    element* next;
};

struct queue{
    element* head;
    element* tail;
};

void push(queue &q, char value){
    element* el = new element;
    el->character=value;
    el->next=nullptr;
    if(q.tail!=nullptr)    q.tail->next=el;
    else    q.head=el;
    q.tail=el;
}

void pop(queue &q){
    element* temp = q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head==nullptr)    q.tail=nullptr;
}

bool isEmpty(queue q){    return q.head==nullptr;    }

char first(queue q){    return q.head->character;    }

void f6(queue &q){
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

int main() {
    srand(time(0));
    queue q;
    q.head=nullptr;
    q.tail=nullptr;
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
                char val=(char)(65+rand()%60);
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
            default: break;
        }
        cout<<endl;
        system("pause");
    }while(wybor!=7);
    return 0;
}

// Lista jednokierunkowa

struct element{
    int number;
    element* next;
};

struct single_list{
    element* head;
    element* tail;
    int counter;
};

void add_tail(single_list &l, int value){
    element* el=new element;
    el->number=value;
    el->next=nullptr;
    if(l.tail!=nullptr){
        l.tail->next=el;
    }
    else{
        l.head=el;
    }
    l.tail=el;
    l.counter++;
}

void add_head(single_list &l, int value){
    element* el=new element;
    el->number=value;
    el->next=l.head;
    l.head=el;
    if(l.tail==nullptr){
        l.tail=el;
    }
    l.counter++;
}

void add_position(single_list &l, int value, int position){
    element* el=new element;
    el->number=value;
    element* temp=l.head;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    el->next=temp->next;
    temp->next=el;
    l.counter++;
}

void delete_tail(single_list &l){
    element* temp=l.tail;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        element* bef_temp=l.head;
        for(int i=1;i<l.counter-1;i++){
            bef_temp=bef_temp->next;
        }
        l.tail=bef_temp;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_head(single_list &l){
    element* temp=l.head;
    l.head=l.head->next;
    if(l.counter==1){
        l.tail=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_position(single_list &l, int position){
    element* prev=l.head;
    for(int i=1;i<position-1;i++){
        prev=prev->next;
    }
    element* temp=prev->next;
    prev->next=temp->next;
    delete temp;
    l.counter--;
}

void show(single_list &l){
    if(l.counter==0){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element* temp=l.head;
    cout<<"Zawartosc listy:"<<endl;
    for(int i=0;i<l.counter;i++){
        cout<<temp->number<<", ";
        temp=temp->next;
    }
    cout<<endl;
}

void Zad1(){
    single_list lista;
    lista.head=nullptr;
    lista.tail=nullptr;
    lista.counter=0;
    int wybor;
    do{
        cout<<"Menu listy jednokierunkowej:"<<endl;
        cout<<"1) Sprawdzenie czy pusta"<<endl;
        cout<<"2) Dodanie elementu na koniec listy"<<endl;
        cout<<"3) Dodanie elementu na poczatek listy"<<endl;
        cout<<"4) Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5) Usuniecie elementu z konca listy"<<endl;
        cout<<"6) Usuniecie elementu z poczatku listy"<<endl;
        cout<<"7) Usuniecie elementu z okreslonej pozycji"<<endl;
        cout<<"8) Pobranie pierwszego elementu z listy"<<endl;
        cout<<"9) Pobranie ostatniego elementu z listy"<<endl;
        cout<<"10) Obliczenie sredniej arytmetycznej elementow z listy"<<endl;
        cout<<"11) Znalezienie elementu maksymalnego w liscie"<<endl;
        cout<<"12) Wyswietlenie zawartosci calej listy"<<endl;
        cout<<"13) Usuniecie listy i zwolnienie pamieci"<<endl;
        cout<<"14) Wyjscie"<<endl;
        cout<<endl;
        cin>>wybor;
        switch(wybor){
            case(1):{
                if(lista.counter)
                    cout<<"Lista nie jest pusta"<<endl;
                else
                    cout<<"Lista jest pusta"<<endl;
                break;
            }
            case(2):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_tail(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" na koniec listy"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(3):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_head(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" na poczatek listy"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(4):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50,pozycja;
                cout<<"Na jaka pozycje wstawic liczbe "<<wartosc<<"?: ";
                cin>>pozycja;
                add_position(lista,wartosc,pozycja);
                cout<<"Dodano liczbe "<<wartosc<<" na pozycji "<<pozycja<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(5):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista.tail->number<<" z konca listy"<<endl;
                    delete_tail(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(6):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista.head->number<<" z poczatku listy"<<endl;
                    delete_head(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(7):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    int pozycja;
                    cout<<"Z jakiej pozycji usunac liczbe?: ";
                    cin>>pozycja;
                    cout<<"Usunieto liczbe z pozycji "<<pozycja<<endl;
                    delete_position(lista,pozycja);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(8):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta"<<endl;
                else if(lista.head==nullptr)
                    cout<<"Pierwsza liczba z listy to "<<lista.tail->number<<endl;
                else
                    cout<<"Pierwsza liczba z listy to "<<lista.head->number<<endl;
                break;
            }
            case(9):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta"<<endl;
                else if(lista.tail==nullptr)
                    cout<<"Ostatnia liczba z listy to "<<lista.head->number<<endl;
                else
                    cout<<"Ostatnia liczba z listy to "<<lista.tail->number<<endl;
                break;
            }
            case(10):{
                if(lista.counter==0)
                    break;
                element* temp=lista.head;
                int suma;
                for(int i=0;i<lista.counter;i++){
                    suma+=temp->number;
                    temp=temp->next;
                }
                cout<<"Srednia liczb w tej liscie jest rowna "<<(float)suma/lista.counter<<endl;
                break;
            }
            case(11):{
                if(lista.counter==0)
                    break;
                element* temp=lista.head->next;
                int max_elem=lista.head->number,poz=1;
                for(int i=1;i<lista.counter;i++){
                    if(temp->number>max_elem){
                        max_elem=temp->number;
                        poz=i+1;
                    }
                    temp=temp->next;
                }
                cout<<"Najwieksza liczba w tej liscie to liczba "<<max_elem<<" na pozycji "<<poz<<endl;
                break;
            }
            case(12):{
                show(lista);
                break;
            }
            case(13):{
                while(lista.counter>0){
                    delete_head(lista);
                }
                cout<<"Usunieto zawartosc listy"<<endl;
                break;
            }
        }
        system("pause");
        system("cls");
    }while(wybor!=14);
}

// Lista dwukierunkowa

struct element2k{
    int number;
    element2k* next;
    element2k* prev;
};

struct double_list{
    element2k* head;
    element2k* tail;
    int counter;
};


void add_tail(double_list &l, int value){
    element2k* el=new element2k;
    el->number=value;
    el->next=nullptr;
    el->prev=nullptr;
    if(l.tail!=nullptr){
        l.tail->next=el;
        el->prev=l.tail;
    }
    else{
        l.head=el;
    }
    l.tail=el;
    l.counter++;
}

void add_head(double_list &l, int value){
    element2k* el=new element2k;
    el->number=value;
    el->next=nullptr;
    el->prev=nullptr;
    if(l.head!=nullptr){
        l.head->prev=el;
        el->next=l.head;
    }
    else{
        l.tail=el;
    }
    l.head=el;
    l.counter++;
}

void add_position(double_list &l, int value, int position){
    element2k* temp=l.head;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    element2k* el = new element2k;
    el->number=value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;
    l.counter++;
}

void delete_tail(double_list &l){
    element2k* temp=l.tail;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        l.tail=l.tail->prev;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_head(double_list &l){
    element2k* temp=l.head;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        l.head=l.head->next;
        l.head->prev=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_position(double_list &l, int position){
    element2k* temp=l.head;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    element2k* temp_us=temp->next;
    temp->next=temp_us->next;
    temp->next->prev=temp;
    delete temp_us;
    l.counter--;
}

void show(double_list &l,bool reverse=0){
    if(l.counter==0){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element2k* temp;
    if(reverse)
        temp=l.tail;
    else
        temp=l.head;
    cout<<"Zawartosc listy:"<<endl;
    for(int i=0;i<l.counter;i++){
        cout<<temp->number<<", ";
        if(reverse)
            temp=temp->prev;
        else
            temp=temp->next;
    }
    cout<<endl;
}

void Zad2(){
    double_list lista;
    lista.head=nullptr;
    lista.tail=nullptr;
    lista.counter=0;
    int wybor;
    do{
        cout<<"Menu listy dwukierunkowej:"<<endl;
        cout<<"1) Sprawdzenie czy pusta"<<endl;
        cout<<"2) Dodanie elementu na koniec listy"<<endl;
        cout<<"3) Dodanie elementu na poczatek listy"<<endl;
        cout<<"4) Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5) Usuniecie elementu z konca listy"<<endl;
        cout<<"6) Usuniecie elementu z poczatku listy"<<endl;
        cout<<"7) Usuniecie elementu z okreslonej pozycji"<<endl;
        cout<<"8) Wyswietlenie zawartosci calej listy od poczatku do konca"<<endl;
        cout<<"9) Wyswietlenie zawartosci calej listy od konca do poczatku"<<endl;
        cout<<"10) Znalezienie elementu minimalnego w liscie"<<endl;
        cout<<"11) Usuniecie listy i zwolnienie pamieci"<<endl;
        cout<<"12) Wyjscie"<<endl;
        cout<<endl;
        cin>>wybor;
        switch(wybor){
            case(1):{
                if(lista.counter)
                    cout<<"Lista nie jest pusta"<<endl;
                else
                    cout<<"Lista jest pusta"<<endl;
                break;
            }
            case(2):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_tail(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" na koniec listy"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(3):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_head(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" na poczatek listy"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(4):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50,pozycja;
                cout<<"Na jaka pozycje wstawic liczbe "<<wartosc<<"?: ";
                cin>>pozycja;
                add_position(lista,wartosc,pozycja);
                cout<<"Dodano liczbe "<<wartosc<<" na pozycji "<<pozycja<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(5):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista.tail->number<<" z konca listy"<<endl;
                    delete_tail(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(6):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista.head->number<<" z poczatku listy"<<endl;
                    delete_head(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(7):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    int pozycja;
                    cout<<"Z jakiej pozycji usunac liczbe?: ";
                    cin>>pozycja;
                    cout<<"Usunieto liczbe z pozycji "<<pozycja<<endl;
                    delete_position(lista,pozycja);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(8):{
                show(lista);
                break;
            }
            case(9):{
                show(lista,1);
                break;
            }
            case(10):{
                if(lista.counter==0)
                    break;
                element2k* temp=lista.head->next;
                int min_elem=lista.head->number,poz=1;
                for(int i=1;i<lista.counter;i++){
                    if(temp->number<min_elem){
                        min_elem=temp->number;
                        poz=i+1;
                    }
                    temp=temp->next;
                }
                cout<<"Najmniejsza liczba w tej liscie to liczba "<<min_elem<<" na pozycji "<<poz<<endl;
                break;
            }
            case(11):{
                while(lista.counter>0){
                    delete_head(lista);
                }
                cout<<"Usunieto zawartosc listy"<<endl;
                break;
            }
        }
        system("pause");
        system("cls");
    }while(wybor!=12);
}

//Lista jednokierunkowa cykliczna
struct element1kc{
    int number;
    element1kc* next;
};

bool isEmpty(element1kc* lista){
    return lista==nullptr;
}

int count(element1kc* lista){
    int n=0;
    if(isEmpty(lista)){
        return n;
    }
    element1kc *temp=lista;
    do{
        n++;
        temp=temp->next;
    }while(temp!=lista);
    return n;
}

void add_tail(element1kc* &l, int value){
    element1kc* el=new element1kc;
    if(l==nullptr){
        el->number=value;
        el->next=el;
        l=el;
        return;
    }
    el->number=value;
    el->next=l->next;
    l->next=el;
}

void add_head(element1kc* &l, int value){
    element1kc* el=new element1kc;
    if(l==nullptr){
        el->number=value;
        el->next=el;
        l=el;
        return;
    }
    el->number=value;
    el->next=l;
    element1kc* temp=l;
    while(temp->next!=l){
        temp=temp->next;
    }
    temp->next=el;
}

void add_position(element1kc* &l, int value, int position){
    element1kc* temp=l;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
        if(temp->next==l){
            break;
        }
    }
    element1kc* el=new element1kc;
    el->number=value;
    el->next=temp->next;
    temp->next=el;
}

void delete_tail(element1kc* &l){
    element1kc* temp;
    if(l->next==l){
        temp=l;
        l=nullptr;
    }
    else{
        temp=l->next;
        l->next=temp->next;
    }
    delete temp;
}

void delete_head(element1kc* &l){
    element1kc* temp;
    if(l->next==l){
        temp=l;
        l=nullptr;
    }
    else{
        while(temp->next->next!=l){
            temp=temp->next;
        }
        element1kc* temp2=temp;
        temp=temp->next;
        temp2->next=l;
    }
    delete temp;
}

void delete_position(element1kc* &l, int position){
    element1kc* temp=l;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
        if(temp->next->next==l){
            break;
        }
    }
    element1kc* temp_us=temp->next;
    temp->next=temp_us->next;
    delete temp_us;
}

void show(element1kc* l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element1kc* temp=l;
    cout<<"Zawartosc listy:"<<endl;
    while(temp->next!=l){
        cout<<temp->number<<", ";
        temp=temp->next;
    }
    cout<<endl;
}

void Zad3(){
    element1kc* lista=nullptr;
    int wybor;
    do{
        cout<<"Menu listy jednokierunkowej:"<<endl;
        cout<<"1) Sprawdzenie czy pusta"<<endl;
        cout<<"2) Dodanie elementu na koniec listy"<<endl;
        cout<<"3) Dodanie elementu na poczatek listy"<<endl;
        cout<<"4) Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5) Usuniecie elementu z konca listy"<<endl;
        cout<<"6) Usuniecie elementu z poczatku listy"<<endl;
        cout<<"7) Usuniecie elementu z okreslonej pozycji"<<endl;
        cout<<"8) Pobranie pierwszego elementu z listy"<<endl;
        cout<<"9) Pobranie ostatniego elementu z listy"<<endl;
        cout<<"10) Obliczenie sredniej arytmetycznej elementow z listy"<<endl;
        cout<<"11) Znalezienie elementu maksymalnego w liscie"<<endl;
        cout<<"12) Wyswietlenie zawartosci calej listy"<<endl;
        cout<<"13) Usuniecie listy i zwolnienie pamieci"<<endl;
        cout<<"14) Wyjscie"<<endl;
        cout<<endl;
        cin>>wybor;
        switch(wybor){
            case(1):{
                if(!isEmpty(lista))
                    cout<<"Lista nie jest pusta"<<endl;
                else
                    cout<<"Lista jest pusta"<<endl;
                break;
            }
            case(2):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_tail(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" na koniec listy"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(3):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_head(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" na poczatek listy"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(4):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50,pozycja;
                cout<<"Na jaka pozycje wstawic liczbe "<<wartosc<<"?: ";
                cin>>pozycja;
                add_position(lista,wartosc,pozycja);
                cout<<"Dodano liczbe "<<wartosc<<" na pozycji "<<pozycja<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(5):{
                if(!isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista.tail->number<<" z konca listy"<<endl;
                    delete_tail(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(6):{
                if(!isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista->number<<" z poczatku listy"<<endl;
                    delete_head(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(7):{
                if(!isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    int pozycja;
                    cout<<"Z jakiej pozycji usunac liczbe?: ";
                    cin>>pozycja;
                    cout<<"Usunieto liczbe z pozycji "<<pozycja<<endl;
                    delete_position(lista,pozycja);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(8):{
                if(!isEmpty(lista))
                    cout<<"Lista jest pusta"<<endl;
                else
                    cout<<"Pierwsza liczba z listy to "<<lista->number<<endl;
                break;
            }
            case(9):{
                if(!isEmpty(lista))
                    cout<<"Lista jest pusta"<<endl;
                else if(lista.tail==nullptr)
                    cout<<"Ostatnia liczba z listy to "<<lista.head->number<<endl;
                else
                    cout<<"Ostatnia liczba z listy to "<<lista.tail->number<<endl;
                break;
            }
            case(10):{
                if(!isEmpty(lista))
                    break;
                element* temp=lista.head;
                int suma;
                for(int i=0;i<lista.counter;i++){
                    suma+=temp->number;
                    temp=temp->next;
                }
                cout<<"Srednia liczb w tej liscie jest rowna "<<(float)suma/lista.counter<<endl;
                break;
            }
            case(11):{
                if(lista.counter==0)
                    break;
                element* temp=lista.head->next;
                int max_elem=lista.head->number,poz=1;
                for(int i=1;i<lista.counter;i++){
                    if(temp->number>max_elem){
                        max_elem=temp->number;
                        poz=i+1;
                    }
                    temp=temp->next;
                }
                cout<<"Najwieksza liczba w tej liscie to liczba "<<max_elem<<" na pozycji "<<poz<<endl;
                break;
            }
            case(12):{
                show(lista);
                break;
            }
            case(13):{
                while(!isEmpty(lista)){
                    delete_head(lista);
                }
                cout<<"Usunieto zawartosc listy"<<endl;
                break;
            }
        }
        system("pause");
        system("cls");
    }while(wybor!=14);
}

//Lista dwukierunkowa cykliczna
struct element2kc{
    int number;
    element2kc* next;
    element2kc* prev;
};

bool isEmpty(element2kc* l){
    return l==nullptr;
}

int count(element2kc* l){
    int n=0;
    if(isEmpty(l)){
        return n;
    }
    element2kc* temp=l;
    do{
        n++;
        temp=temp->next;
    }while(temp!=l);
    return n;
}

void add_tail(element2kc* &l, int value){
    element2kc* el=new element2kc;
    if(l==nullptr){
        el->number=value;
        el->next=el;
        el->prev=el;
        l=el;
        return;
    }
    el->number=value;
    el->prev=l;
    el->next=l->next;
    l->next->prev=el;
    l->next=el;
}

void add_head(element2kc* &l, int value){
    element2kc* el=new element2kc;
    if(l==nullptr){
        el->number=value;
        el->next=el;
        el->prev=el;
        l=el;
        return;
    }
    el->number=value;
    el->next=l;
    el->prev=l->prev;
    l->prev->next=el;
    l->prev=el;
}

void add_position(element2kc* &l, int value, int position){
    element2kc* temp=l;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
        if(temp->next==l){
            break;
        }
    }
    element2kc* el=new element2kc;
    el->number=value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;
}

void delete_tail(element2kc* &l){
    element2kc* temp;
    if(l->next==l){
        temp=l;
        l=nullptr;
    }
    else{
        temp=l->next;
        temp->next->prev=temp->prev;
        l->next=temp->next;
    }
    delete temp;
}

void delete_head(element2kc* &l){
    element2kc* temp;
    if(l->prev==l){
        temp=l;
        l=nullptr;
    }
    else{
        temp=l->prev;
        l->prev=temp->prev;
        temp->prev->next=temp->next;
    }
    delete temp;
}

void delete_position(element2kc* &l, int position){
    element2kc* temp=l;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
        if(temp->next==l){
            temp=temp->prev;
            break;
        }
    }
    element2kc* temp_us=temp->next;
    temp->next=temp_us->next;
    temp->next->prev=temp;
    delete temp_us;
}

void show(element2kc* l,bool reverse=0){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element2kc* temp=l;
    cout<<"Zawartosc listy:"<<endl;
    int n=count(l);
    for(int i=0;i<n;i++){
        cout<<temp->number<<", ";
        if(reverse)
            temp=temp->prev;
        else
            temp=temp->next;
    }
    cout<<endl;
}

void Zad4(){
    element2kc* lista=nullptr;
    int wybor;
    do{
        cout<<"Menu listy dwukierunkowej:"<<endl;
        cout<<"1) Sprawdzenie czy pusta"<<endl;
        cout<<"2) Dodanie elementu po elemencie biezacym"<<endl;
        cout<<"3) Dodanie elementu przed elementem biezacym"<<endl;
        cout<<"4) Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5) Usuniecie elementu po elemencie biezacym"<<endl;
        cout<<"6) Usuniecie elementu przed elementem biezacym"<<endl;
        cout<<"7) Usuniecie elementu z okreslonej pozycji"<<endl;
        cout<<"8) Wyswietlenie zawartosci calej listy od poczatku do konca"<<endl;
        cout<<"9) Wyswietlenie zawartosci calej listy od konca do poczatku"<<endl;
        cout<<"10) Wyswietlenie liczby elementow znajdujacych sie w liscie"<<endl;
        cout<<"11) Znalezienie elementu minimalnego w liscie"<<endl;
        cout<<"12) Usuniecie listy i zwolnienie pamieci"<<endl;
        cout<<"13) Wyjscie"<<endl;
        cout<<endl;
        cin>>wybor;
        switch(wybor){
            case(1):{
                if(isEmpty(lista))
                    cout<<"Lista jest pusta"<<endl;
                else
                    cout<<"Lista nie jest pusta"<<endl;
                break;
            }
            case(2):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_tail(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" po elemencie biezacym"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(3):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_head(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" przed elementem biezacym"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(4):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50,pozycja;
                cout<<"Na jaka pozycje wstawic liczbe "<<wartosc<<"?: ";
                cin>>pozycja;
                add_position(lista,wartosc,pozycja);
                cout<<"Dodano liczbe "<<wartosc<<" na pozycji "<<pozycja<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(5):{
                if(isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista->next->number<<" po elemencie biezacym"<<endl;
                    delete_tail(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(6):{
                if(isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista->prev->number<<" przed elementem biezacym"<<endl;
                    delete_head(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(7):{
                if(isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    int pozycja;
                    cout<<"Z jakiej pozycji usunac liczbe?: ";
                    cin>>pozycja;
                    cout<<"Usunieto liczbe z pozycji "<<pozycja<<endl;
                    delete_position(lista,pozycja);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(8):{
                show(lista);
                break;
            }
            case(9):{
                show(lista,1);
                break;
            }
            case(10):{
                cout<<"Liczba elementow listy: "<<count(lista)<<endl;
                break;
            }
            case(11):{
                if(isEmpty(lista)){
                    cout<<"Lista jest pusta"<<endl;
                    break;
                }
                element2kc* temp=lista->next;
                int min_elem=lista->number,poz=1,n=count(lista);
                for(int i=1;i<n;i++){
                    if(temp->number<min_elem){
                        min_elem=temp->number;
                        poz=i+1;
                    }
                    temp=temp->next;
                }
                cout<<"Najmniejsza liczba w tej liscie to liczba "<<min_elem<<" na pozycji "<<poz<<endl;
                break;
            }
            case(12):{
                if(isEmpty(lista)){
                    cout<<"Lista jest pusta"<<endl;
                }
                while(!isEmpty(lista)){
                    delete_tail(lista);
                }
                cout<<"Usunieto zawartosc listy"<<endl;
                break;
            }
        }
        system("pause");
        system("cls");
    }while(wybor!=13);
}

//main listy
#include <iostream>

using namespace std;

#include "funkcje1k.cpp"
#include "funkcje2k.cpp"
#include "funkcje1kc.cpp"
#include "funkcje2kc.cpp"
#include "zad1.cpp"
#include "zad2.cpp"
#include "zad3.cpp"
#include "zad4.cpp"

int main(){
    srand(time(0));
    int wybor;
    do{
        system("cls");
        cout<<"Podaj numer zadania (1-4) lub 5 aby wyjsc: ";
        cin>>wybor;
        switch(wybor){
            case(1):{
                Zad1();
                break;
            }
            case(2):{
                Zad2();
                break;
            }
            case(3):{
                Zad3();
                break;
            }
            case(4):{
                Zad4();
                break;
            }
        }
    }while(wybor!=5);
    return 0;
}