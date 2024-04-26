void Zad2(){
    double_list lista;
    lista.head=nullptr;
    lista.tail=nullptr;
    lista.counter=0;
    int wybor;
    do{
        cout<<"Menu listy dwukierunkowej:"<<endl;
        cout<<"1) Sprawdzenie czy pusta"<<endl;
        cout<<"2) Dodanie elementu na koniec listy"<<endl;
        cout<<"3) Dodanie elementu na poczatek listy"<<endl;
        cout<<"4) Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5) Usuniecie elementu z konca listy"<<endl;
        cout<<"6) Usuniecie elementu z poczatku listy"<<endl;
        cout<<"7) Usuniecie elementu z okreslonej pozycji"<<endl;
        cout<<"8) Wyswietlenie zawartosci calej listy od poczatku do konca"<<endl;
        cout<<"9) Wyswietlenie zawartosci calej listy od konca do poczatku"<<endl;
        cout<<"10) Znalezienie elementu minimalnego w liscie"<<endl;
        cout<<"11) Usuniecie listy i zwolnienie pamieci"<<endl;
        cout<<"12) Wyjscie"<<endl;
        cout<<endl;
        cin>>wybor;
        switch(wybor){
            case(1):{
                if(lista.counter)
                    cout<<"Lista nie jest pusta"<<endl;
                else
                    cout<<"Lista jest pusta"<<endl;
                break;
            }
            case(2):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_tail(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" na koniec listy"<<endl;
                cout<<"Po dodaniu:"<<endl;
                show(lista);
                break;
            }
            case(3):{
                cout<<"Przed dodaniem:"<<endl;
                show(lista);
                int wartosc=1+rand()%50;
                add_head(lista,wartosc);
                cout<<"Dodano liczbe "<<wartosc<<" na poczatek listy"<<endl;
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
                if(lista.counter==0)
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista.tail->number<<" z konca listy"<<endl;
                    delete_tail(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(6):{
                if(lista.counter==0)
                    cout<<"Lista jest pusta, nie ma elementu do usuniecia"<<endl;
                else{
                    cout<<"Przed usunieciem:"<<endl;
                    show(lista);
                    cout<<"Usunieto liczbe "<<lista.head->number<<" z poczatku listy"<<endl;
                    delete_head(lista);
                    cout<<"Po usunieciu:"<<endl;
                    show(lista);
                }
                break;
            }
            case(7):{
                if(lista.counter==0)
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
                show(lista,1);
                break;
            }
            case(10):{
                if(lista.counter==0)
                    break;
                element2k* temp=lista.head->next;
                int min_elem=lista.head->number,poz=1;
                for(int i=1;i<lista.counter;i++){
                    if(temp->number<min_elem){
                        min_elem=temp->number;
                        poz=i+1;
                    }
                    temp=temp->next;
                }
                cout<<"Najmniejsza liczba w tej liscie to liczba "<<min_elem<<" na pozycji "<<poz<<endl;
                break;
            }
            case(11):{
                while(lista.counter>0){
                    delete_head(lista);
                }
                cout<<"Usunieto zawartosc listy"<<endl;
                break;
            }
        }
        system("pause");
        system("cls");
    }while(wybor!=12);
}