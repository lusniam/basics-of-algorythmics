#include <iostream>

using namespace std;

struct node{
    int key;
    node* parent;
    node* left;
    node* right;
};

node* make_node(int value){
    node* n=new node;
    n->key=value;
    n->left=nullptr;
    n->right=nullptr;
    n->parent=nullptr;
    return n;
}

void add_node(int value,node* &root){
    if(root==nullptr){
        root=make_node(value);
        return;
    }
    node* temp=root;
    while(true){
        if(value>=temp->key){
            if(temp->right==nullptr){
                temp->right=make_node(value);
                temp->right->parent=temp;
                return;
            }
            else{
                temp=temp->right;
            }
        }
        else{
            if(temp->left==nullptr){
                temp->left=make_node(value);
                temp->left->parent=temp;
                return;
            }
            else{
                temp=temp->left;
            }  
        }
    }
}

string preorder(node* root){
    if(root!=nullptr){
        return to_string(root->key)+","+preorder(root->left)+preorder(root->right);
    }
    return "";
}

string inorder(node* root){
    if(root!=nullptr){
        return inorder(root->left)+to_string(root->key)+","+inorder(root->right);
    }
    return "";
}

string postorder(node* root){
    if(root!=nullptr){
        return postorder(root->left)+postorder(root->right)+to_string(root->key)+",";
    }
    return "";
}

node* find_node(node* root,int value){
    while(root!=nullptr){
        if(root->key==value){
            return root;
        }
        if(value>root->key){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return nullptr;
}

node* find_successor(node* n){
    if(n->right!=nullptr){
        n=n->right;
        while(n->left!=nullptr){
            n=n->left;
        }
        return n;
    }
    node* temp=n->parent;
    while(temp!=nullptr&&temp->left!=n){
        n=temp;
        temp=temp->parent;
    }
    return temp;
}

void delete_node(node* &root,node* delete_node){
    node* temp1;
    node* temp2;
    if(delete_node->left==nullptr||delete_node->right==nullptr){
        temp1=delete_node;
    }
    else{
        temp1=find_successor(delete_node);
    }
    if(temp1->left!=nullptr){
        temp2=temp1->left;
    }
    else{
        temp2=temp1->right;
    }
    if(temp2!=nullptr){
        temp2->parent=temp1->parent;
    }
    if(temp1->parent==nullptr){
        root=temp2;
    }
    else if(temp1==temp1->parent->left){
        temp1->parent->left=temp2;
    }
    else{
        temp1->parent->right=temp2;
    }
    if(temp1!=delete_node){
        delete_node->key=temp1->key;
    }
    delete temp1;
}

int main(){
    int wybor=0;
    node* tree=nullptr;
    do{
        system("cls");
        cout<<"Menu:"<<endl;
        cout<<"1) sprawdzenie czy drzewo jest puste"<<endl;
        cout<<"2) dodanie nowego wezla do drzewa"<<endl;
        cout<<"3) sprawdzenie czy klucz o podanej wartosci wezla znajduje sie w drzewie"<<endl;
        cout<<"4) wyswietlenie liczby wystapien kluczy w drzewie"<<endl;
        cout<<"5) wyswietlenie drzewa - preorder"<<endl;
        cout<<"6) wyswietlenie drzewa - inorder"<<endl;
        cout<<"7) wyswietlenie drzewa - postorder"<<endl;
        cout<<"8) usuniecie wezla o podanej wartosci klucza przez uzytkownika"<<endl;
        cout<<"9) usuniecie calego drzewa"<<endl;
        cout<<"10) wyjscie z programu"<<endl;
        cin>>wybor;
        switch(wybor){
            case 1:{
                if(tree==nullptr){
                    cout<<"Drzewo jest puste"<<endl;
                }
                else{
                    cout<<"Drzewo nie jest puste"<<endl;
                }
                break;
            }
            case 2:{
                cout<<"Podaj wartosc jaka mam dodac do drzewa: ";
                int val;
                cin>>val;
                cout<<"Zawartosc drzewa przed dodaniem:"<<endl<<inorder(tree)<<endl;
                if(find_node(tree,val)!=nullptr){
                    cout<<"Podana wartosc znajduje sie juz w drzewie"<<endl;
                    break;
                }
                add_node(val,tree);
                cout<<"Zawartosc drzewa po dodaniu:"<<endl<<inorder(tree)<<endl;
                break;
            }
            case 3:{
                cout<<"Podaj wartosc jaka mam znalezc w drzewie: ";
                int val;
                cin>>val;
                if(find_node(tree,val)==nullptr){
                    cout<<"Podanej wartosci nie ma w drzewie"<<endl;
                }
                else{
                    cout<<"Podana wartosc znajduje sie w drzewie"<<endl;
                }
                break;
            }
            case 4:{
                node* seeked=tree;
                int count=0;
                if(seeked!=nullptr){
                    while(seeked->left!=nullptr){
                        seeked=seeked->left;
                    }
                    while(seeked!=nullptr){
                        cout<<seeked->key<<endl;
                        seeked=find_successor(seeked);
                        count++;
                    }
                }
                cout<<"W drzewie jest "<<count<<" kluczy"<<endl;
                break;
            }
            case 5:{
                cout<<"Zawartosc drzewa (preorder):"<<endl;
                if(tree==nullptr)
                    cout<<"Drzewo jest puste"<<endl;
                else
                    cout<<preorder(tree)<<endl;
                break;
            }
            case 6:{
                cout<<"Zawartosc drzewa (inorder):"<<endl;
                if(tree==nullptr)
                    cout<<"Drzewo jest puste"<<endl;
                else
                    cout<<inorder(tree)<<endl;
                break;
            }
            case 7:{
                cout<<"Zawartosc drzewa (postorder):"<<endl;
                if(tree==nullptr)
                    cout<<"Drzewo jest puste"<<endl;
                else
                    cout<<postorder(tree)<<endl;
                break;
            }
            case 8:{
                cout<<"Podaj wartosc jaka mam usunac z drzewa: ";
                int val;
                cin>>val;
                cout<<"Zawartosc drzewa przed usunieciem:"<<endl<<inorder(tree)<<endl;
                node* del_node=find_node(tree,val);
                if(del_node==nullptr){
                    cout<<"Podanej wartosci nie ma w drzewie"<<endl;
                    break;
                }
                delete_node(tree,del_node);
                cout<<"Zawartosc drzewa po usunieciu:"<<endl<<inorder(tree)<<endl;
                break;
            }
            case 9:{
                while(tree!=nullptr){
                    delete_node(tree,tree);
                }
                cout<<"Usunieto cale drzewo"<<endl;
                break;
            }
        }
        system("pause");
    }while(wybor!=10);
    return 0;
}