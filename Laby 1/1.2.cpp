#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    srand(time(0));

    int n,a,b;
    cout<<"Podaj rozmiar tablicy oraz liczby z przedzialu <a,b>:"<<endl;
    cin>>n>>a>>b;
    int tab[n];

    for(int i=0;i<n;i++){
        tab[i]=(rand() % (b-a+1)) + a;
    }
    int min=tab[0];
    for(int i=1;i<n;i++){
        if(tab[i]<min){
            min=tab[i];
        }
    }

    bool pierwsza=false;
    if(min>1){
        for(int i=2;i<=sqrt(min);i++){
            if(min%i==0)
                break;
            if(i+1>sqrt(min))
                pierwsza=true;
        }
    }
    if(min==2||min==3)
        pierwsza=true;
    
    cout<<"Najmniejsza liczba w tablicy to "<<min<<", ktora ";
    if (!pierwsza)
        cout<<"nie ";
    cout<<"jest pierwsza"<<endl;

    system("pause");
    return 0;
}