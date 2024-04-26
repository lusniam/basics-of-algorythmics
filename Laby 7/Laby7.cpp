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

void sortowanieQuickSort(student* & tab,int prawy,int lewy=0,int tryb=1){
    int srodek=(int)(lewy+prawy)/2;
    student piwot=tab[srodek];
    tab[srodek]=tab[prawy];
    int granica=lewy;
    for(int i=lewy;i<prawy;i++){
        if(tab[i].punkty*tryb<piwot.punkty*tryb){
            student temp=tab[i];
            tab[i]=tab[granica];
            tab[granica]=temp;
            granica++;
        }
    }
    tab[prawy]=tab[granica];
    tab[granica]=piwot;
    if(lewy<granica-1)
        sortowanieQuickSort(tab,granica-1,lewy,tryb);
    if(granica+1<prawy)
        sortowanieQuickSort(tab,prawy,granica+1,tryb);
}

void wydruk(student* tab, int p, int k){
    for(int i=p;i<k;i++){
            cout<<tab[i].imie<<" "<<tab[i].nazwisko<<": "<<tab[i].punkty<<" punktow"<<endl;
    }
}

void Zad2(student* tab, int n){
    bool czy_pusty=true;
    int wczytane;
    cout<<"Podaj liczbe punktow do wyszukania: ";
    cin>>wczytane;
    for(int i=0;i<n;i++){
        if(tab[i].punkty==wczytane){
            czy_pusty=false;
            wydruk(tab,i,i+1);
        }
    }
    if(czy_pusty)   cout<<"Zaden student nie osiagnal podanej liczby punktow."<<endl;
}

int wBisekcyjne(student* tab,int l,int p,int wartosc){
    int srodek=(int)(l+p)/2;
    if(l>p) return -1;
    if(tab[srodek].punkty==wartosc) return srodek;
    if(wartosc<tab[srodek].punkty) return wBisekcyjne(tab,l,srodek-1,wartosc);
    else return wBisekcyjne(tab,srodek+1,p,wartosc);
}

void Zad3(student *tab, int n){
    int wczytane;
    cout<<"Podaj liczbe punktow do wyszukania: ";
    cin>>wczytane;
    sortowanieQuickSort(tab,n-1);
    int lStudentow=0;
    string wynik="";
    student* temptab;
    temptab=new student [n];
    for(int i=0;i<n;i++){
        temptab[i]=tab[i];
    }
    int tempn=n;
    int szukanie=wBisekcyjne(temptab,0,tempn,wczytane);
    while(szukanie!=-1){
        lStudentow++;
        wynik+=temptab[szukanie].imie+';'+temptab[szukanie].nazwisko+';'+to_string(temptab[szukanie].punkty)+'\n';
        tempn--;
        for(int i=szukanie;i<tempn;i++){
            temptab[i]=temptab[i+1];
        }
        copy(temptab,temptab+tempn,temptab);
        szukanie=wBisekcyjne(temptab,0,tempn,wczytane);
    }
    ofstream plik("wyniki.csv");
    plik<<lStudentow<<";;\n";
    plik<<wynik;
    plik.close();
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