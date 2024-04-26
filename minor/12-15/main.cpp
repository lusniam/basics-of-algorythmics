#include <iostream>

using namespace std;

void Zad13(){
    int n;
    cout<<"Podaj liczbe n: ";
    cin>>n;
    for(int i=n-(n%2);i>0;i-=2)   cout<<i<<", ";
    cout<<endl;
}

void Zad14(){
    int a=0,l=0;
    do{
        cout<<"Podaj dodatnia liczbe a: ";
        cin>>a;
        if(a<=0) cout<<"Podano nieprawidlowa liczbe"<<endl;
        l++;
    }while(a<=0);
    cout<<"Podano poprawna liczbe "<<a<<" za "<<l<<" razem"<<endl;
}

int main(int, char**) {
    Zad13();
    Zad14();
    return 0;
}
