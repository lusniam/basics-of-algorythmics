#include <iostream>
#include <cmath>

using namespace std;

void Zad16(){
    int n;
    cout<<"Podaj n:";
    cin>>n;
    cout<<"Dzielniki liczby n: ";
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i)
                cout<<i<<", ";
            else
                cout<<i<<", "<<n/i<<", ";
        }
    }
    cout<<endl;
}

void Zad17(){
    int n;
    cout<<"Podaj n: ";
    cin>>n;
    do{
        int suma=0;
        int temp=n;
        while(temp>0){
            suma+=temp%10;
            temp/=10;
        }
        cout<<"Suma cyfr liczby "<<n<<" wynosi "<<suma<<endl;
        n=suma;
    }while(n>9);
}

void Zad18(){
    int n;
    cout<<"Podaj n: ";
    cin>>n;
    if(n<1) return;
    int tab[n];
    for(int i=0;i<n;i++){
        cout<<"Podaj "<<i<<" liczbe: ";
        cin>>tab[i];
    }
    int min=tab[0],max=tab[0];
    int ilemin=1, ilemax=1;
    int indexmin=0,indexmax=0;
    for(int i=1;i<n;i++){
        if(min>tab[i]){
            min=tab[i];
            ilemin=1;
            indexmin=i;
        }
        else if(min==tab[i])
            ilemin++;
        if(max<tab[i]){
            max=tab[i];
            ilemax=1;
            indexmax=i;
        }
        else if(max==tab[i])
            ilemax++;
    }
    cout<<"Liczba minimalna to "<<min<<endl;
    cout<<"Jej pierwsze wystapienie w tablicy jest w indeksie "<<indexmin<<endl;
    cout<<"Liczba ta wystepuje w tablicy "<<ilemin<<" razy"<<endl<<endl;
    cout<<"Liczba maksymalna to "<<max<<endl;
    cout<<"Jej pierwsze wystapienie w tablicy jest w indeksie "<<indexmax<<endl;
    cout<<"Liczba ta wystepuje w tablicy "<<ilemax<<" razy"<<endl;
}

void Zad19(){
    int n,a;
    cout<<"Podaj n: ";
    cin>>n;
    int tab[n];
    cout<<"Podaj a: ";
    cin>>a;
    for(int i=0;i<n;i++){
        cout<<"Podaj liczbe: ";
        cin>>tab[i];
    }
    int liczba_a=0;
    for(int i=0;i<n;i++){
        if(tab[i]==a){
            liczba_a++;
        }
    }
    if(liczba_a){
        int indeksy[liczba_a];
        int j=0;
        for(int i=0;i<n;i++){
            if(tab[i]==a){
                indeksy[j]=i;
                j++;
            }
        }
        cout<<"Liczba a wystepuje w tabeli "<<liczba_a<<" razy\nWystepuje ona w indeksach"<<endl;
        for(int i=0;i<liczba_a;i++){
            cout<<indeksy[i]<<", ";
        }
        cout<<endl;
    }
    else{
        cout<<"W tabeli nie wystepuje liczba a"<<endl;
    }
}

int main(){
    Zad16();
    //Zad17();
    //Zad18();
    Zad19();
}
