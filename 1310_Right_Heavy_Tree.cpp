
// Problem#: 1310
// Submission#: 1841320
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

class tree{
    public:
    void intial(){
        head = NULL;
    }
    struct node{
        node *l;
        node *r;
        int key;
        node(node *left ,node * right,int k):l(left),r(right),key(k){

        }
    };
    node *head;
    tree(){
        head = NULL;
    }
    void insert(int k){
        insert(head,k);
    }
    void insert(node *&T,int k){
        if(T == NULL){
            T =new node(NULL,NULL,k);
            return;
        }
        if(k > T -> key){
            insert(T -> r,k);
        }
        else insert(T -> l,k);
    }
    void inorder(){
        cout << "Inorder:";
        inorder(head);
        cout << endl;
    }
    void inorder(const node * T){
        if(T == NULL)return;
        else {
            inorder(T -> l);
            cout << " " << T ->key;
            inorder(T -> r);
        }
    }
    void preorder(){
        cout << "Preorder:";
        preorder(head);
        cout << endl;
    }
    void preorder(const node * T){
        if(T == NULL)return;
        else {
            cout << " " << T -> key;
            preorder(T -> l);
            preorder(T -> r);
        }
    }
    void postorder(){
        cout << "Postorder:";
        postorder(head);
        cout << endl;
    }
    void postorder(const node * T){
        if(T == NULL)return;
        else {
            postorder(T -> l);
            postorder(T -> r);
            cout << " " << T -> key;
        }
    }
};
tree k;
int main(){
    int n;
    bool first = false;
    
    while(cin >> n){
        k.intial();
        if(first ++)cout << endl;
        for(int i = 0;i < n;i ++){
            int tmp;
            cin >> tmp;
            k.insert(tmp);
        }
        k.inorder();
        k.preorder();
        k.postorder();
    }
    return 0;
}                                 