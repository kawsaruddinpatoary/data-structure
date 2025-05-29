#include<iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node * insert(Node *root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildTree(vector<int> arr){
    Node *root = NULL;
    for(int val: arr){
        root = insert(root, val);
    }
    return root;
}

void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

bool search(Node *root, int key){
    if(root==NULL){
        return false;
    }else if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
}

Node *inOrderSuccessor(Node *root){
    while(root!=NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }else{
            Node *successor = inOrderSuccessor(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }

    return root;
}


int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildTree(arr);
    inOrder(root);
    cout << endl;

    deleteNode(root, 2);
    inOrder(root);
    
}