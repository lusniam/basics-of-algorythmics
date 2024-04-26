struct element2kc{
    int number;
    element2kc* next;
    element2kc* prev;
};

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