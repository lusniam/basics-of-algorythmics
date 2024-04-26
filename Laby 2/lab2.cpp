#include <iostream>
#include <cstdlib>

using namespace std;

void sortowanieBabelkowe(int* tab, int n, int tryb){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if (tryb*tab[j]>tryb*tab[j+1]){
                int temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

void sortowaniePrzezWybor(int* tab, int n, int tryb){
    for(int i=n-1;i>0;i--){
        int ind=0;
        for(int j=1;j<=i;j++){
            if (tryb*tab[j]>tryb*tab[ind]){
                ind=j;
            }
        }
        int temp=tab[ind];
        tab[ind]=tab[i];
        tab[i]=temp;
    }
}

void sortowaniePrzezWstawianie(int* tab,int n, int tryb){
    for(int i=n-2;i>=0;i--){
        int j=i;
        int temp=tab[j];
        while (tryb*temp>tryb*tab[j+1]&&j<n-1){
            tab[j]=tab[j+1];
            j++;
        }
        tab[j]=temp;
    }
}

void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol){
    for(int i=w-1;i>0;i--){
        for(int j=0;j>i;j++){
            if (tryb*tab[j][0]>tryb*tab[j+1][0]){
                int *temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

void Zad2(){
    int a,b,n,tryb=0;
    cout<<"Podaj n:";
    cin>>n;
    int *tab=new int[n];
    cout<<"Wypelnie tablice liczbami z przedzialu <a,b>\nPodaj a:";
    cin>>a;
    cout<<"Podaj b:";
    cin>>b;
    for(int i=0;i<n;i++)
        tab[i]=rand()%(b-a+1)+a;
    cout<<"Powstala taka tablica:\n[";
    for(int i=0;i<n;i++){
        cout<<tab[i];
        if(i!=n-1)
            cout<<',';
    }
    cout<<"]\nJak mam posortowac tablice? (1 - rosnaco,-1 - malejaco):";
    while (tryb!=1&&tryb!=-1)
        cin>>tryb;
    sortowanieBabelkowe(tab,n,tryb);
    cout<<"Tablica po sortowaniu:\n[";
    for(int i=0;i<n;i++){
        cout<<tab[i];
        if(i!=n-1)
            cout<<',';
    }
    cout<<"]"<<endl;
    system("pause");
}

void Zad3(){
    int a,b,n,tryb=0;
    cout<<"Podaj n:";
    cin>>n;
    int *tab=new int[n];
    cout<<"Wypelnie tablice liczbami z przedzialu <a,b>\nPodaj a:";
    cin>>a;
    cout<<"Podaj b:";
    cin>>b;
    for(int i=0;i<n;i++)
        tab[i]=rand()%(b-a+1)+a;
    cout<<"Powstala taka tablica:\n[";
    for(int i=0;i<n;i++){
        cout<<tab[i];
        if(i!=n-1)
            cout<<',';
    }
    cout<<"]\nJak mam posortowac tablice? (1 - rosnaco,-1 - malejaco):";
    while (tryb!=1&&tryb!=-1)
        cin>>tryb;
    sortowaniePrzezWybor(tab,n,tryb);
    cout<<"Tablica po sortowaniu:\n[";
    for(int i=0;i<n;i++){
        cout<<tab[i];
        if(i!=n-1)
            cout<<',';
    }
    cout<<"]"<<endl;
    system("pause");
}

void Zad4(){
    int a,b,n,tryb=0;
    cout<<"Podaj n:";
    cin>>n;
    int *tab=new int[n];
    cout<<"Wypelnie tablice liczbami z przedzialu <a,b>\nPodaj a:";
    cin>>a;
    cout<<"Podaj b:";
    cin>>b;
    for(int i=0;i<n;i++)
        tab[i]=rand()%(b-a+1)+a;
    cout<<"Powstala taka tablica:\n[";
    for(int i=0;i<n;i++){
        cout<<tab[i];
        if(i!=n-1)
            cout<<',';
    }
    cout<<"]\nJak mam posortowac tablice? (1 - rosnaco,-1 - malejaco):";
    while (tryb!=1&&tryb!=-1)
        cin>>tryb;
    sortowaniePrzezWstawianie(tab,n,tryb);
    cout<<"Tablica po sortowaniu:\n[";
    for(int i=0;i<n;i++){
        cout<<tab[i];
        if(i!=n-1)
            cout<<',';
    }
    cout<<"]"<<endl;
    system("pause");
}

void Zad5(){
    int a,b,w,k,tryb=0,nr_k;
    cout<<"Podaj ilosc wierszy:";
    cin>>w;
    cout<<"Podaj ilosc kolumn:";
    cin>>k;
    int **tab=new int*[w];
    for(int i=0;i<k;i++){
        tab[i]=new int[k];
    }
    cout<<"Wypelnie tablice liczbami z przedzialu <a,b>\nPodaj a:";
    cin>>a;
    cout<<"Podaj b:";
    cin>>b;
    for(int i=0;i<w;i++){
        for(int j=0;j<k;j++){
            tab[i][j]=rand()%(b-a+1)+a;
        }
    }
    cout<<"Powstala taka tablica:\n[";
    for(int i=0;i<w;i++){
        for(int j=0;j<k;j++){
            cout<<tab[i][j];
            if(i!=k-1)
                cout<<',';
        }
        cout<<"]"<<endl;
    }
    cout<<"Jak mam posortowac tablice? (1 - rosnaco,-1 - malejaco):";
    while (tryb!=1&&tryb!=-1)
        cin>>tryb;
    sortowanieBabelkowe2D(tab,w,k,tryb,0);
    cout<<"Tablica po sortowaniu:\n[";
    for(int i=0;i<w;i++){
        for(int j=0;j<k;j++){
            cout<<tab[i][j];
            if(i!=k-1)
                cout<<',';
        }
        cout<<"]"<<endl;
    }
    system("pause");
}

int main(){
    srand(time(0));
    int wybor=0;
    while(wybor!=5){
        cout<<"Wpisz numer opcji:\n1) 2.2 Sortowanie babelkowe"<<endl;
        cout<<"2) 2.3 Sortowanie przez wybor\n3) 2.4 Sortowanie przez wstawianie"<<endl;
        cout<<"4) 2.5 Sortowanie tablicy dwuwymiarowej\n5) Wyjscie z programu"<<endl;
        cin>>wybor;
        switch(wybor){
            case 1: {Zad2(); break;}
            case 2: {Zad3(); break;}
            case 3: {Zad4(); break;}
            case 4: {Zad5(); break;}
            default: break;
        }
        system("cls");
    }
    return EXIT_SUCCESS;
}