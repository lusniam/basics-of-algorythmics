#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));
    int n;
    cout<<"Podaj rozmiar tablicy nxn: ";
    cin>>n;
    int tab[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            tab[i][j]=7+rand()%116;
    int nad=0,pod=0,ile_nad=0,ile_pod=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                nad+=tab[i][j];
                ile_nad++;
            }
            else if(i>j){
                pod+=tab[i][j];
                ile_pod++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<tab[i][j]<<",";
        }
        cout<<endl;
    }

    cout<<"Srednia liczb nad przekatna: "<<(float)nad/ile_nad<<endl;
    cout<<"Srednia liczb pod przekatna: "<<(float)pod/ile_pod<<endl;
    
    system("pause");
    return 0;
}