#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};

Node* root;

Node* findParent(Node* current, Node* child){
    if(!current || current==child) return NULL;

    queue<Node*> q;
    q.push(current);

    while(!q.empty()){
        Node* f=q.front();
        q.pop();

        if (f->left==child || f->right==child) return f;

        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
    }
    return NULL;
}

void exchange(Node* child) {
    if(!child) return;

    Node* parent=findParent(root, child);
    while (parent && child->val > parent->val) {
        swap(child->val, parent->val);
        child=parent;
        parent=findParent(root, child);
    }
}

Node* insertNode(Node* root, int value) {
    Node* newNode=new Node(value);
    if (!root) return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* f=q.front();
        q.pop();

        if (!f->left) {
            f->left=newNode;
            exchange(newNode);
            break;
        } else {
            q.push(f->left);
        }

        if (!f->right) {
            f->right=newNode;
            exchange(newNode);
            break;
        } else {
            q.push(f->right);
        }
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (!root) return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    root=NULL;

    root = insertNode(root, 40);
    root = insertNode(root, 62);
    root = insertNode(root, 64);
    root = insertNode(root, 34);
    root = insertNode(root, 38);
    root = insertNode(root, 33);


    cout<<"In Order Traversal: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"Pre Order Traversal: ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"Post Order Traversal: ";
    postOrderTraversal(root);
    cout<<endl;

    return 0;
}

