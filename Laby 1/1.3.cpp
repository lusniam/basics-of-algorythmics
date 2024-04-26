#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));

    int n;
    cout<<"Podaj rozmiar tablicy: ";
    cin>>n;
    int tab[n];
    for(int i=0;i<n;i++)
        tab[i]=rand()%10;
    int wystap[10]={};
    for(int i=0;i<n;i++)
        wystap[tab[i]]++;
    cout<<"Wystepowanie liczb w tablicy:"<<endl;
    for(int i=0;i<10;i++){
        cout<<"Cyfra "<<i+1<<" - "<<wystap[i]<<" razy"<<endl;
    }
    system("pause");
    return 0;
}