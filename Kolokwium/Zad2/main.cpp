#include <iostream>
#include <string>

using namespace std;

void bSort(string* &tab,int s){
    for(int i=s-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(tab[j]>tab[j+1]){
                string temp=tab[j+1];
                tab[j+1]=tab[j];
                tab[j]=temp;
            }
        }
    }
}

string fun(string* tab,int s,char znak){
    int lewy=0;
    int prawy=s-1;
    while(lewy<=prawy){
        int srodek=(int)(lewy+prawy)/2;
        if(tab[srodek][0]==znak)
            return tab[srodek];
        else if(znak<tab[srodek][0])
            prawy=srodek-1;
        else
            lewy=srodek+1;
    }
    return "W tablicy nie ma napisu rozpoczynajacego sie na podany znak";
}

void wczytaj(string* &tab, int &s,char &znak){
    cout<<"s: ";
    cin>>s;
    tab=new string [s];
    for(int i=0;i<s;i++){
        cout<<"podaj napis: ";
        cin>>tab[i];
    }
    cout<<"znak: ";
    cin>>znak;
}

int main()
{
    string* tab;
    int s;
    char znak;
    wczytaj(tab,s,znak);
    bSort(tab,s);
    cout<<"znaleziony napis: "<<fun(tab,s,znak)<<endl;
    return 0;
}
