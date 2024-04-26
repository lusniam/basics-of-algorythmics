#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
    srand(time(0));
    int a,b,m,n;
    cout<<"Podaj rozmiar tablicy m x n, oraz przedzial <a,b>";
    cin>>m>>n>>a>>b;
    int tab[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            tab[i][j]=rand()%(b-a+1)+a;
    int max=tab[0][0];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(tab[i][j]>max)
                max=tab[i][j];
    string szukana=to_string(max);
    int suma=0;
    for(int i=0;i<szukana.length();i++){
        suma+=szukana[i]-'0';
    }
    cout<<"Najwieksza wylosowana liczba z przedzialu <"<<a<<","<<b<<"> jest rowna "<<max<<",\nktorej suma cyfr wynosi "<<suma<<endl;
    system("pause");
    return 0;
}