#include <iostream>

using namespace std;

struct pracownik{
    int nrStan;
    int m1;
    int m2;
    int m3;
    float pensja;
    float premia;
};

void wczytaj(pracownik* &pracownicy,int &w){
    cout<<"Podaj liczbe pracownikow: ";
    cin>>w;
    pracownicy=new pracownik [w];
    for(int i=0;i<w;i++){
        cout<<"nr stan: ";
        cin>>pracownicy[i].nrStan;
        cout<<"m1: ";
        cin>>pracownicy[i].m1;
        cout<<"m2: ";
        cin>>pracownicy[i].m2;
        cout<<"m3: ";
        cin>>pracownicy[i].m3;
        cout<<"pensja: ";
        cin>>pracownicy[i].pensja;
        if(pracownicy[i].m1>=95&&pracownicy[i].m2>=95&&pracownicy[i].m3>=95){
            pracownicy[i].premia=(((float)(pracownicy[i].m1+pracownicy[i].m2+pracownicy[i].m3)/300)-0.95)*pracownicy[i].pensja;
        }
        else
            pracownicy[i].premia=0;
    }
}

void fun1(pracownik* &pracownicy,int w){
    for(int i=w-1;i>0;i--){
        int ind=0;
        for(int j=1;j<=i;j++){
            if(pracownicy[j].premia>pracownicy[ind].premia)
                ind=j;
        }
        pracownik temp=pracownicy[i];
        pracownicy[i]=pracownicy[ind];
        pracownicy[ind]=temp;
    }
}

void fun2(pracownik* pracownicy,int w){
    cout<<"lista pracownikow: "<<endl;
    for(int i=0;i<w;i++){
        cout<<pracownicy[i].nrStan<<": pensja = "<<pracownicy[i].pensja<<", premia = "<<pracownicy[i].premia<<endl;
    }
}

int main()
{
    int w;
    pracownik* pracownicy;
    wczytaj(pracownicy,w);
    fun1(pracownicy,w);
    fun2(pracownicy,w);
    return 0;
}
