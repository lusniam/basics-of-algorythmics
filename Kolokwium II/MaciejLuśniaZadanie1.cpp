int Zadanie1(queue* q){
    if(isEmpty(q))
        return 0;
    int count=0;
    queue* temp=new queue;
    temp->head=nullptr;
    temp->tail=nullptr;
    while(!isEmpty(q))    push(temp,pop(q));
    while(!isEmpty(temp)){
        int val=pop(temp);
        if(val%3==0)    count++;
        push(q,val);
    }
    delete temp;
    return count;
}