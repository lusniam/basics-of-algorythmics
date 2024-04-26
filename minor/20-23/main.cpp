#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void Zad22(){
    int n;
    cout<<"Podaj n: ";
    cin>>n;
    int tab[n];
    for(int i=0;i<n;i++){
        cout<<"Podaj liczbe: ";
        cin>>tab[i];
    }
    int k;
    cout<<"Podaj k: ";
    cin>>k;
    if(k<0||k>(n-1)){
        cout<<"Nieprawidlowa liczba w"<<endl;
        return;
    }
    int suma=0;
    for(int i=0;i<k;i++){
        suma+=tab[i];
    }
    bool w=suma>tab[k];
    if(w){
        cout<<"w = true"<<endl;
    }
    else{
        cout<<"w = false"<<endl;
    }
}

void Zad20(){
    int a;
    cout<<"Podaj a: ";
    cin>>a;
    string str_a=to_string(a);
    for(int i=1;i<str_a.length();i++){
        if(str_a[i-1]!=str_a[i]){
            cout<<"cyfry rozne"<<endl;
            break;
        }
        if(i+1==str_a.length()){
            cout<<"cyfry jednakowe"<<endl;
        }
    }
    int suma=0,max=0,np=0,p=0;
    string lustro="";
    for(int i=0;i<str_a.length();i++){
        suma+=str_a[i]-'0';
        if(str_a[i]-'0'>max)
            max=str_a[i]-'0';
        if((str_a[i]-'0')%2==0)
            p++;
        else
            np++;
        lustro+=str_a[str_a.length()-1-i];
    }
    cout<<"Suma cyfr liczby a to "<<suma<<endl;
    cout<<"Najwieksza z cyfr liczby a to "<<max<<endl;
    if(p>np)
        cout<<"W tej liczbie jest wiecej liczb parzystych"<<endl;
    else if(p==np)
        cout<<"W tej liczbie jest tyle samo liczb parzystych co nieparzystych"<<endl;
    else
        cout<<"W tej liczbie jest wiecej liczb nieparzystych"<<endl;
    cout<<"Liczba lustro jest rowna "<<lustro<<endl;
    if(str_a.compare(lustro)==0)
        cout<<"Liczba ta jest palindromem"<<endl;
    else
        cout<<"Liczba ta nie jest palindromem"<<endl;
    cout<<"Liczba a binarnie to "<<bitset<32>(a)<<endl;
}

void Zad23(){
    int n;
    cout<<"Podaj n:";
    cin>>n;
    int t[n];
    for(int i=0;i<n;i++){
        cout<<"Podaj liczbe: ";
        cin>>t[i];
    }
    int wynik=1;
    bool zero=true;
    for(int i=0;i<n;i+=3){
        if(t[i]!=0){
            wynik*=t[i];
            zero=false;
        }
    }
    if(zero){
        wynik=0;
    }
    cout<<"Wartosc zmiennej wynik: "<<wynik<<endl;
}

int main(){
    //Zad20();
    //Zad22();
    Zad23();
}