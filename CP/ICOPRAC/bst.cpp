#include <bits/stdc++.h>
using namespace std;
int a[] = {1,2,3,4,5,6,7,8,9,10};
int n = 10;

class node{
public:
    node* p = NULL;
    node* r = NULL;
    node* l = NULL;
    int val = 0;
    node(int v){
        val = v;
    }
};

void traverse(node* root){
    if(root = NULL){
        return;
    }
    else{
        traverse(root->l);
        printf("%d ", root->val);
        traverse(root->r);
    }
}
node* bst(node* root, int l, int r){
    if(l==r){
        cout << l ;
        node* n = new node(a[l]);n->p = root;
        return n;
    }
    else{
        int m = (int)(l+r)/2;
        //cout << m;
        node* n = new node(a[m]);n->p = root;
        n->r = bst(n, m+1, r);n->l = bst(n, l, m-1);
        return n;
    }
}

int main(){
    //Driver program for a bst
    int l = 0, r = n-1;
    int m = (int) r/2;
    node root = node(a[m]);root.r = bst(&root, m+1, r);root.l = bst(&root, l, m-1);
    traverse(&root);
}

