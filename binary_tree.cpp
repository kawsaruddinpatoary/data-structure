#include<iostream>
#include <vector>
#include <queue>
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

int index = -1;
Node * buildTree(vector<int> preorder){
    index++;
    if(preorder[index] == -1){
        return NULL;
    }
    Node *root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root){
    queue<Node *> q;
    q.push(root);
    
    while(q.size()>0){
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout << endl;
}

int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

int count(Node *root){
    if(root==NULL){
        return 0;
    }
    int left = count(root->left);
    int right = count(root->right);

    return left+right+1;
}

int sum(Node *root){
    if(root==NULL){
        return 0;
    }
    int left = sum(root->left);
    int right = sum(root->right);
    return left + right + root->data;
}

int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);
    levelOrder(root);
    cout << sum(root) << endl;
}