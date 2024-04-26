#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};

void Zad1(student* & tab, int & n){
    ifstream plik;
    plik.open("studenci.csv");
    string linia;
    plik>>linia;
    n=stoi(linia.substr(0,linia.find(';')));
    tab = new student[n];
    for(int i=0;i<n;i++){
        plik>>linia;
        tab[i].imie=linia.substr(0,linia.find(';'));
        linia.erase(0,linia.find(';')+1);
        tab[i].nazwisko=linia.substr(0,linia.find(';'));
        linia.erase(0,linia.find(';')+1);
        tab[i].punkty=stoi(linia);
    }
    plik.close();
}

void wydruk(student* tab, int p, int k){
    for(int i=p;i<k;i++){
            cout<<tab[i].imie<<" "<<tab[i].nazwisko<<": "<<tab[i].punkty<<" punktow"<<endl;
    }
}

void Zad2(student* tab, int n){
    cout<<"\nZawartosc tabeli przed podzialem:"<<endl;
    wydruk(tab,0,n);
    int i=0,j=n-1;
    while(i<j){
        while(tab[i].punkty<=10 && i<j){
            i++;
        }
        while(tab[j].punkty>10 && i<j){
            j--;
        }
        if(i<j){
            student temp=tab[i];
            tab[i]=tab[j];
            tab[j]=temp;
            i++;
            j--;
        }
    }
    if(tab[i].punkty<=10){
        i++;
    }
    cout<<"\nStudenci, którzy otrzymali <=10 punktów:"<<endl;
    wydruk(tab,0,i);
    cout<<"\nStudenci, którzy otrzymali >10 punktów:"<<endl;
    wydruk(tab,i,n);
}

void Zad3(student * tab, int n){
    int i=-1,j=0,k=n;
    cout<<"\nZawartosc tabeli przed podzialem:"<<endl;
    wydruk(tab,0,n);
    while(j<k){
        if(tab[j].punkty%3==0){
            i++;
            student temp=tab[i];
            tab[i]=tab[j];
            tab[j]=temp;
            j++;
        }
        else{
            if(tab[j].punkty%3==2){
                k--;
                student temp=tab[k];
                tab[k]=tab[j];
                tab[j]=temp;
            }
            else{
                j++;
            }
        }
    }
    i++;
    cout<<"\nStudenci, którzy otrzymali liczbę punktów podzielnych przez 3:"<<endl;
    wydruk(tab,0,i);
    cout<<"\nStudenci, którzy otrzymali liczbę punktów podzielnych przez 3 z resztą 1:"<<endl;
    wydruk(tab,i,k);
    cout<<"\nStudenci, którzy otrzymali liczbę punktów podzielnych przez 3 z resztą 2:"<<endl;
    wydruk(tab,k,n);
}

int main(){
    student* tab;
    int n, wybor;
    do{
        cout<<"Podaj numer zadania (1-3), lub 0 aby zakonczyc program: ";
        cin>>wybor;
        switch(wybor){
            case 1: {Zad1(tab,n); break;}
            case 2: {Zad2(tab,n); break;}
            case 3: {Zad3(tab,n); break;}
            default: break;
        }
    }while(wybor!=0);
    delete [] tab;
    return EXIT_SUCCESS;
}