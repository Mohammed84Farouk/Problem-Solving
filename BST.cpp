//BST
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;

struct node{
private:
    node *left;
    node *right;
    int data;
public:
    node(int d) {
        left = NULL;
        right = NULL;
        data = d;
    }
    friend class BST;
};
class BST{
private:
    node* root;
public:
    node* search(node* root, int data){
        if(root==NULL || root->data == data) return root;
        if(root->data>data) return search(root->left, data);
        return search(root->right, data);
    }
    node* insert(node* root, int data){
        if(root==NULL) return new node(data);
        if(root->data<data) root->right=insert(root->right, data);
        else root->left=insert(root->left, data);
        return root;
    }
    void inOrder(node* root){
        if(root==NULL) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    int countLeaves(node* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        return countLeaves(root->right)+countLeaves(root->left);
    }
    int countNodes(node* root) {
        if (root == NULL) return 0;
        return countNodes(root->right) + countNodes(root->left) + 1;
    }
    BST(node* r){
        root=r;
    }
};
void TT() {
    node* head=new node(5);
    BST bst = *new BST(head);
    bst.insert(head, 55);
    bst.insert(head, 50);
    bst.insert(head, 60);
    bst.insert(head, 3);
    bst.insert(head, 4);
    bst.insert(head, 2);
    bst.inOrder(head);
    cout<<endl;
    cout<<bst.countLeaves(head)<<" "<<bst.countNodes(head)<<endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    FAST
    int testCases = 1;
//    cin >> testCases;
    while (testCases--) TT();
    return 0;
}
