// https://www.hackerrank.com/challenges/self-balancing-tree/problem

//avl.cpp

#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;


node* insert_hidden(node*, int);
node* Delete(node*, int);
void  preorder_hidden(node*);
void  inorder_hidden(node*);
int   ht_hidden(node*);
node* rotate_right_hidden(node*);
node* rotate_left_hidden(node*);
node* RR_hidden(node*);
node* LL_hidden(node*);
node* LR_hidden(node*);
node* RL_hidden(node*);
int BF_hidden(node*);

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */


int height(node* root) {
    if (root == nullptr) {
        return -1;
    }
    return root->ht;
}

int getBalance(node* root) {
    if (root == nullptr) {
        return 0;
    }

    return height(root->left) - height(root->right);
}

node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->ht = 1 + max(height(y->left), height(y->right));
    x->ht = 1 + max(height(x->left), height(x->right));

    return x;
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->ht = 1 + max(height(x->left), height(x->right));
    y->ht = 1 + max(height(y->left), height(y->right));

    return y;
}

node* insert(node* root, int val) {
    if (root == nullptr) {
        node* temp = new node;
        temp->val = val;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->ht = 0;
        return temp;
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    else {
        return root;
    }

    root->ht = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && val < root->left->val) {
        return rightRotate(root);
    }

    if (balance < -1 && val > root->right->val) {
        return leftRotate(root);
    }

    if (balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

