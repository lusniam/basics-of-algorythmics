struct element2k{
    int number;
    element2k* next;
    element2k* prev;
};

struct double_list{
    element2k* head;
    element2k* tail;
    int counter;
};


void add_tail(double_list &l, int value){
    element2k* el=new element2k;
    el->number=value;
    el->next=nullptr;
    el->prev=nullptr;
    if(l.tail!=nullptr){
        l.tail->next=el;
        el->prev=l.tail;
    }
    else{
        l.head=el;
    }
    l.tail=el;
    l.counter++;
}

void add_head(double_list &l, int value){
    element2k* el=new element2k;
    el->number=value;
    el->next=nullptr;
    el->prev=nullptr;
    if(l.head!=nullptr){
        l.head->prev=el;
        el->next=l.head;
    }
    else{
        l.tail=el;
    }
    l.head=el;
    l.counter++;
}

void add_position(double_list &l, int value, int position){
    element2k* temp=l.head;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    element2k* el = new element2k;
    el->number=value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;
    l.counter++;
}

void delete_tail(double_list &l){
    element2k* temp=l.tail;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        l.tail=l.tail->prev;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_head(double_list &l){
    element2k* temp=l.head;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        l.head=l.head->next;
        l.head->prev=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_position(double_list &l, int position){
    element2k* temp=l.head;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    element2k* temp_us=temp->next;
    temp->next=temp_us->next;
    temp->next->prev=temp;
    delete temp_us;
    l.counter--;
}

void show(double_list &l,bool reverse=0){
    if(l.counter==0){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element2k* temp;
    if(reverse)
        temp=l.tail;
    else
        temp=l.head;
    cout<<"Zawartosc listy:"<<endl;
    for(int i=0;i<l.counter;i++){
        cout<<temp->number<<", ";
        if(reverse)
            temp=temp->prev;
        else
            temp=temp->next;
    }
    cout<<endl;
}