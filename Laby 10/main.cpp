#include <iostream>

using namespace std;

#include "funkcje1k.cpp"
#include "funkcje2k.cpp"
#include "funkcje1kc.cpp"
#include "funkcje2kc.cpp"
#include "zad1.cpp"
#include "zad2.cpp"
//#include "zad3.cpp"
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
                //Zad3();
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