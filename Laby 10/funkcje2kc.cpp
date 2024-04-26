struct element2kc{
    int number;
    element2kc* next;
    element2kc* prev;
};

bool isEmpty(element2kc* l){
    return l==nullptr;
}

int count(element2kc* l){
    int n=0;
    if(isEmpty(l)){
        return n;
    }
    element2kc* temp=l;
    do{
        n++;
        temp=temp->next;
    }while(temp!=l);
    return n;
}

void add_tail(element2kc* &l, int value){
    element2kc* el=new element2kc;
    if(l==nullptr){
        el->number=value;
        el->next=el;
        el->prev=el;
        l=el;
        return;
    }
    el->number=value;
    el->prev=l;
    el->next=l->next;
    l->next->prev=el;
    l->next=el;
}

void add_head(element2kc* &l, int value){
    element2kc* el=new element2kc;
    if(l==nullptr){
        el->number=value;
        el->next=el;
        el->prev=el;
        l=el;
        return;
    }
    el->number=value;
    el->next=l;
    el->prev=l->prev;
    l->prev->next=el;
    l->prev=el;
}

void add_position(element2kc* &l, int value, int position){
    element2kc* temp=l;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
        if(temp->next==l){
            break;
        }
    }
    element2kc* el=new element2kc;
    el->number=value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;
}

void delete_tail(element2kc* &l){
    element2kc* temp;
    if(l->next==l){
        temp=l;
        l=nullptr;
    }
    else{
        temp=l->next;
        temp->next->prev=temp->prev;
        l->next=temp->next;
    }
    delete temp;
}

void delete_head(element2kc* &l){
    element2kc* temp;
    if(l->prev==l){
        temp=l;
        l=nullptr;
    }
    else{
        temp=l->prev;
        l->prev=temp->prev;
        temp->prev->next=temp->next;
    }
    delete temp;
}

void delete_position(element2kc* &l, int position){
    element2kc* temp=l;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
        if(temp->next==l){
            temp=temp->prev;
            break;
        }
    }
    element2kc* temp_us=temp->next;
    temp->next=temp_us->next;
    temp->next->prev=temp;
    delete temp_us;
}

void show(element2kc* l,bool reverse=0){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element2kc* temp=l;
    cout<<"Zawartosc listy:"<<endl;
    int n=count(l);
    for(int i=0;i<n;i++){
        cout<<temp->number<<", ";
        if(reverse)
            temp=temp->prev;
        else
            temp=temp->next;
    }
    cout<<endl;
}

int Zadanie2(element2kc* l, bool & czypusta){
    czypusta=(l==nullptr);
    if(czypusta)
        return 0;
    int min=l->number;
    element2kc* temp=l->next;
    while(temp!=l){
        if(temp->number<min)
            min=temp->number;
        temp=temp->next;
    }
    return min;
}