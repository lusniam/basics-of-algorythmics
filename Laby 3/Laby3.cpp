#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};

void sortowanieQuickSort(student* & tab,int tryb,int prawy,int lewy=0){
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
        sortowanieQuickSort(tab,tryb,granica-1,lewy);
    if(granica+1<prawy)
        sortowanieQuickSort(tab,tryb,prawy,granica+1);
}

void wczytajStudentow(student* & tab, int & n){
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

void wyswietlStudentow(student* tab, int n){
    cout<<"Oto lista studentow i otrzymane przez nich punkty:"<<endl;
    for(int i=0;i<n;i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<": "<<tab[i].punkty<<" punktow"<<endl;
    }
}

void usunTabliceStudentow(student* & tab){delete [] tab;}

int main(){
    student* tab;
    int n,tryb;
    wczytajStudentow(tab,n);
    cout<<"Przed sortowaniem:"<<endl;
    wyswietlStudentow(tab,n);
    do{
        cout<<"Jak chcesz posortowac tablice?(1 - rosnaco, -1 - malejaco): ";
        cin>>tryb;
    }while(tryb!=1&&tryb!=-1);
    sortowanieQuickSort(tab,tryb,n-1);
    cout<<"\nPo sortowaniu:"<<endl;
    wyswietlStudentow(tab,n);
    usunTabliceStudentow(tab);
    return EXIT_SUCCESS;
}