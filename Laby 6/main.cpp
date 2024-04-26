#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int make_hash(char s,int off, int p, int exp){ return ((int)s-off)*pow(p,exp); }

int update_hash(int hash, char s_prev, char s_next,int off, int p, int exp){ return ((hash-((int)s_prev-off)*pow(p,exp))*p)+((int)s_next-off); }

string kr(string tekst, string wzorzec, int hashW, int p, int off, int dlW){
    string wynik="";
    int dlT=tekst.length();
    int hashT=0;
    for(int i=0;i<dlW;i++)
        hashT+=make_hash(tekst[i],off,p,dlW-i-1);

    int j=0;
    for(int i=dlW;i<=dlT;i++){
        if(hashW==hashT){
            int k=0;
            while(k<dlW && wzorzec[k]==tekst[j+k])
                k++;
            if(k==dlW)    
                wynik+=to_string(j)+", ";
        }
        if(i<dlT)
            hashT=update_hash(hashT,tekst[j],tekst[i],off,p,dlW-1);
        j++;
    }

    if(wynik.empty())    return "-1";
    return wynik;
}

int main()
{
    ifstream plik("tekst.txt");
    string wzorzec;
    plik>>wzorzec;
    
    int dlW=wzorzec.length();
    int p;
    {
        int tabp[255];
        for(int i=0;i<dlW;i++){
            tabp[wzorzec[i]]++;
        }
        for(int i=0;i<dlW;i++){
            if(tabp[i]>0)
                p++;
        }
    }
    int off=65;
    
    int hashW=0;
    for(int i=0;i<dlW;i++)  hashW+=make_hash(wzorzec[i],off,p,dlW-i-1);

    int linijka=1;
    while(plik.good()){
        string tekst;
        plik>>tekst;
        cout<<"Linijka "<<linijka<<": "<<kr(tekst,wzorzec,hashW,p,off,dlW)<<endl;
        linijka++;
    }
    plik.close();

    return 0;
}