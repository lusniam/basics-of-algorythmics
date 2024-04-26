struct element{
    int number;
    element* next;
};

struct single_list{
    element* head;
    element* tail;
    int counter;
};

void add_tail(single_list &l, int value){
    element* el=new element;
    el->number=value;
    el->next=nullptr;
    if(l.tail!=nullptr){
        l.tail->next=el;
    }
    else{
        l.head=el;
    }
    l.tail=el;
    l.counter++;
}

void add_head(single_list &l, int value){
    element* el=new element;
    el->number=value;
    el->next=l.head;
    l.head=el;
    if(l.tail==nullptr){
        l.tail=el;
    }
    l.counter++;
}

void add_position(single_list &l, int value, int position){
    element* el=new element;
    el->number=value;
    element* temp=l.head;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    el->next=temp->next;
    temp->next=el;
    l.counter++;
}

void delete_tail(single_list &l){
    element* temp=l.tail;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        element* bef_temp=l.head;
        for(int i=1;i<l.counter-1;i++){
            bef_temp=bef_temp->next;
        }
        l.tail=bef_temp;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_head(single_list &l){
    element* temp=l.head;
    l.head=l.head->next;
    if(l.counter==1){
        l.tail=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_position(single_list &l, int position){
    element* prev=l.head;
    for(int i=1;i<position-1;i++){
        prev=prev->next;
    }
    element* temp=prev->next;
    prev->next=temp->next;
    delete temp;
    l.counter--;
}

void show(single_list &l){
    if(l.counter==0){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element* temp=l.head;
    cout<<"Zawartosc listy:"<<endl;
    for(int i=0;i<l.counter;i++){
        cout<<temp->number<<", ";
        temp=temp->next;
    }
    cout<<endl;
}