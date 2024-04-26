void Zad4(){
    element2kc* lista=nullptr;
    int wybor;
    do{
        cout<<"Menu listy dwukierunkowej:"<<endl;
        cout<<"1) Sprawdzenie czy pusta"<<endl;
        cout<<"2) Dodanie elementu po elemencie biezacym"<<endl;
        cout<<"3) Dodanie elementu przed elementem biezacym"<<endl;
        cout<<"4) Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5) Usuniecie elementu po elemencie biezacym"<<endl;
        cout<<"6) Usuniecie elementu przed elementem biezacym"<<endl;
        cout<<"7) Usuniecie elementu z okreslonej pozycji"<<endl;
        cout<<"8) Wyswietlenie zawartosci calej listy od poczatku do konca"<<endl;
        cout<<"9) Wyswietlenie zawartosci calej listy od konca do poczatku"<<endl;
        cout<<"10) Wyswietlenie liczby elementow znajdujacych sie w liscie"<<endl;
        cout<<"11) Znalezienie elementu minimalnego w liscie"<<endl;
        cout<<"12) Usuniecie listy i zwolnienie pamieci"<<endl;
        cout<<"13) Wyjscie"<<endl;
        cout<<endl;
        cin>>wybor;
        switch(wybor){
            case(1):{
                if(isEmpty(lista))
                    cout<<"Lista jest pusta"<<endl;
                else
                    cout<<"Lista nie jest pusta"<<endl;
                break;
            }
            case(2):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_tail(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" po elemencie biezacym"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(3):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_head(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" przed elementem biezacym"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(4):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50,pozycja;
                cout<<"Na jaka pozycje wstawic liczbe "<<wartosc<<"?: ";
                cin>>pozycja;
                add_position(lista,wartosc,pozycja);
                cout<<"Dodano liczbe "<<wartosc<<" na pozycji "<<pozycja<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(5):{
                if(isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista->next->number<<" po elemencie biezacym"<<endl;
                    delete_tail(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(6):{
                if(isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista->prev->number<<" przed elementem biezacym"<<endl;
                    delete_head(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(7):{
                if(isEmpty(lista))
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    int pozycja;
                    cout<<"Z jakiej pozycji usunac liczbe?: ";
                    cin>>pozycja;
                    cout<<"Usunieto liczbe z pozycji "<<pozycja<<endl;
                    delete_position(lista,pozycja);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(8):{
                show(lista);
                break;
            }
            case(9):{
                bool czypusta;
                cout<<Zadanie2(lista,czypusta)<<"\t"<<czypusta<<endl;
                
                break;
            }
            case(10):{
                cout<<"Liczba elementow listy: "<<count(lista)<<endl;
                break;
            }
            case(11):{
                if(isEmpty(lista)){
                    cout<<"Lista jest pusta"<<endl;
                    break;
                }
                element2kc* temp=lista->next;
                int min_elem=lista->number,poz=1,n=count(lista);
                for(int i=1;i<n;i++){
                    if(temp->number<min_elem){
                        min_elem=temp->number;
                        poz=i+1;
                    }
                    temp=temp->next;
                }
                cout<<"Najmniejsza liczba w tej liscie to liczba "<<min_elem<<" na pozycji "<<poz<<endl;
                break;
            }
            case(12):{
                if(isEmpty(lista)){
                    cout<<"Lista jest pusta"<<endl;
                }
                while(!isEmpty(lista)){
                    delete_tail(lista);
                }
                cout<<"Usunieto zawartosc listy"<<endl;
                break;
            }
        }
        system("pause");
        system("cls");
    }while(wybor!=13);
}