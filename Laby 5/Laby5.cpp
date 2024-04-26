#include <iostream>
#include <string>

using namespace std;

void wyswietl(string indeksy){
    if(indeksy.length()>0)
        cout<<"W podanym tekscie wzorzec wystepuje w indeksach "<<indeksy<<endl;
    else
        cout<<"W podanym tekscie nie odnaleziono wzorca"<<endl;
}

void Zad1(string & wzorzec, string & tekst){
    cout<<"Podaj tekst: ";
    getline(cin,tekst);
    getline(cin,tekst);
    cout<<"Podaj wzorzec: ";
    getline(cin,wzorzec);
}

void Zad2(string wzorzec, string tekst){
    int dlt=tekst.length();
    int dlw=wzorzec.length();
    string wynik="";
    for(int i=0;i<dlt-dlw+1;i++){
        int j=0;
        while(j<dlw && wzorzec[j]==tekst[i+j]){
            j++;
        }
        if(j==dlw){
            wynik+=to_string(i)+", ";
        }
    }
    wyswietl(wynik);
}

void Zad3(string wzorzec, string tekst){
    int dlt=tekst.length();
    int dlw=wzorzec.length();
    int p[dlw+1];
    p[0]=0;
    p[1]=0;
    int t=0;
    for(int i=1;i<dlw;i++){
        while(t>0 && wzorzec[t]!=wzorzec[i]){
            t=p[t];
        }
        if(wzorzec[t]==wzorzec[i]){
            t++;
        }
        p[i+1]=t;
    }

    int i=0;
    int j=0;
    string wynik="";
    while(i<dlt-dlw+1){
        while(j<dlw && wzorzec[j]==tekst[i+j]){
            j++;
        }
        if(j==dlw){
            wynik+=to_string(i)+", ";
        }
        i+=max(1,j-p[j]);
        j=p[j];
    }
    wyswietl(wynik);
}

void Zad4(string wzorzec, string tekst){
    int dlt=tekst.length();
    int dlw=wzorzec.length();
    int p[256];
    for(int i=0;i<256;i++){
        p[i]=-1;
    }
    for(int i=0;i<dlw;i++){
        p[wzorzec[i]]=i;
    }

    int i=0;
    string wynik="";
    while(i<=dlt-dlw){
        int j=dlw-1;
        while(j>-1 && wzorzec[j]==tekst[i+j]){
            j--;
        }
        if(j==-1){
            wynik+=to_string(i)+", ";
            i++;
        }
        else{
            i+=max(1,j-p[tekst[i+j]]);
        }
    }
    wyswietl(wynik);
}

int main(){
    int wybor;
    string wzorzec, tekst;
    do{
        cout<<"Wybierz numer zadania(1-4), lub 0 aby zakonczyc program: ";
        cin>>wybor;
        switch (wybor){
            case 1:{Zad1(wzorzec,tekst); break;}
            case 2:{Zad2(wzorzec,tekst); break;}
            case 3:{Zad3(wzorzec,tekst); break;}
            case 4:{Zad4(wzorzec,tekst); break;}
            default: break;
        }
    }while(wybor!=0);
    return EXIT_SUCCESS;
}