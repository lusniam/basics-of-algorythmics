struct element1kc{
    int number;
    element1kc* next;
};

bool isEmpty(element1kc* lista){
    return lista==nullptr;
}

int count(element1kc* lista){
    int n=0;
    if(isEmpty(lista)){
        return n;
    }
    element1kc *temp=lista;
    do{
        n++;
        temp=temp->next;
    }while(temp!=lista);
    return n;
}

void add_tail(element1kc* &l, int value){
    element1kc* el=new element1kc;
    if(l==nullptr){
        el->number=value;
        el->next=el;
        l=el;
        return;
    }
    el->number=value;
    el->next=l->next;
    l->next=el;
}

void add_head(element1kc* &l, int value){
    element1kc* el=new element1kc;
    if(l==nullptr){
        el->number=value;
        el->next=el;
        l=el;
        return;
    }
    el->number=value;
    el->next=l;
    element1kc* temp=l;
    while(temp->next!=l){
        temp=temp->next;
    }
    temp->next=el;
}

void add_position(element1kc* &l, int value, int position){
    element1kc* temp=l;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
        if(temp->next==l){
            break;
        }
    }
    element1kc* el=new element1kc;
    el->number=value;
    el->next=temp->next;
    temp->next=el;
}

void delete_tail(element1kc* &l){
    element1kc* temp;
    if(l->next==l){
        temp=l;
        l=nullptr;
    }
    else{
        temp=l->next;
        l->next=temp->next;
    }
    delete temp;
}

void delete_head(element1kc* &l){
    element1kc* temp;
    if(l->next==l){
        temp=l;
        l=nullptr;
    }
    else{
        while(temp->next->next!=l){
            temp=temp->next;
        }
        element1kc* temp2=temp;
        temp=temp->next;
        temp2->next=l;
    }
    delete temp;
}

void delete_position(element1kc* &l, int position){
    element1kc* temp=l;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
        if(temp->next->next==l){
            break;
        }
    }
    element1kc* temp_us=temp->next;
    temp->next=temp_us->next;
    delete temp_us;
}

void show(element1kc* l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element1kc* temp=l;
    cout<<"Zawartosc listy:"<<endl;
    while(temp->next!=l){
        cout<<temp->number<<", ";
        temp=temp->next;
    }
    cout<<endl;
}