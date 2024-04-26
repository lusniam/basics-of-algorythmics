#include <iostream>
#include <string>

using namespace std;

void Zad8(){
    int a,b;
    cout<<"Podaj a: ";
    cin>>a;
    cout<<"Podaj b: ";
    cin>>b;
    bool czy_wielokrotnosc = a%b==0 || b%a==0;
    cout<<"Wartosc zmiennej czy wielokrotnosc: "<<czy_wielokrotnosc<<endl;
}

void Zad9(){
    int d,m,r;
    cout<<"Podaj dzien: ";
    cin>>d;
    cout<<"Podaj miesiac: ";
    cin>>m;
    cout<<"Podaj rok: ";
    cin>>r;
    cout<<"Podana data: "<<d<<'.'<<m<<','<<r<<endl;
    bool poprawna_data=
    (d<=31&&m<=12&&r>=1900&&r<=2023)&&(
    (m%2==1&&m<8)||
    (m%2==0&&m>7)||
    (m!=2&&d<=30)||
    (m==2&&(d<=29&&(r%4==0&&r!=1900)||d<=28)
    ));
    if(poprawna_data) cout<<poprawna_data<<endl;
    else cout<<"Dane niepoprawne"<<endl;
}

void Zad10(){
    int liczby[10];
    for(int i=0;i<10;i++){
        cout<<"Podaj "<<i+1<<" liczbe: ";
        cin>>liczby[i];
    }
    int suma=0,parzyste=0;
    float sNiepar=0,srednia=0;
    for(int i=0;i<10;i++){
        suma+=liczby[i];
        if(liczby[i]%2==0)    parzyste++;
        else    sNiepar+=liczby[i];
    }
    srednia/=10;
    cout<<"Suma podanych liczb wynosi "<<suma<<endl;
    cout<<"Srednia podanych liczb wynosi "<<srednia<<endl;
    cout<<"Jest "<<parzyste<<" liczb parzystych"<<endl;
    if(parzyste==10)    cout<<"Nie ma liczb nieparzystych do policzenia sredniej";
    else{
        sNiepar/=(10-parzyste);
        cout<<"Srednia liczb nieparzystych jest rowna "<<sNiepar<<endl;
    }
}

void Zad11(){
    int liczby[12];
    int suma=0;
    for(int i=0;i<12;i++){
        cout<<"Podaj "<<i+1<<" liczbe: ";
        cin>>liczby[i];
        suma+=liczby[i];
    }
    float srednia=(float)suma/12;
    
    int szukanaSumy=liczby[0],szukanaSredniej=liczby[0];
    float odSumy=abs(szukanaSumy-suma);
    float odSredniej=abs(szukanaSredniej-srednia);
    for(int i=1;i<12;i++){
        if(abs(liczby[i]-suma)>odSumy){
            szukanaSumy=liczby[i];
            odSumy=abs(szukanaSumy-suma);
        }
        if(abs(liczby[i]-srednia)<odSredniej){
            szukanaSredniej=liczby[i];
            odSredniej=abs(szukanaSredniej-srednia);
        }
    }
    cout<<"Liczba najblizsza sredniej to "<<szukanaSredniej<<endl;
    cout<<"Liczba najbardziej oddalona od sumy to "<<szukanaSumy<<endl;
}

int main() {
    int wybor;
    do{
        cout<<"Wybierz numer zadania(1-4), lub 0 aby zakonczyc program: ";
        cin>>wybor;
        switch (wybor){
            case 8:{Zad8(); break;}
            case 9:{Zad9(); break;}
            case 10:{Zad10(); break;}
            case 11:{Zad11(); break;}
            default: break;
        }
    }while(wybor!=0);
    return EXIT_SUCCESS;
}
