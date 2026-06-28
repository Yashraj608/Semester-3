#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*right , *left;
Node(int data){
    this->data = data;
    right = left = nullptr;
}
};
class BST{
public:
Node*root;
BST(){
    root = nullptr;
}
Node*insert(Node*node , int value){
    if(node == nullptr){
        return new Node(value);
    }

    if(node->data > value){
        node->left = insert(node->left,value);
    }else {
        node->right = insert(node->right,value);
    }
return node;
}


int height(Node*node){
    if(node == nullptr){
        return 0;
    }
    int right = height(node->right);
    int left = height(node->left);
    return max(right , left)+1;
}

void Inorder(Node*node){
    if(node == nullptr){
        return;
    }

    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}


void Preorder(Node*node){
    if(root == nullptr){
        return;
    }
    cout<<node->data<<" ";
    Preorder(node->left);
    Preorder(node->right);
}


bool Search(Node*node , int key){
    if(node == nullptr){
        return false;
    }

    if(node->data == key){
        return true;
    }
    else if(node->data > key){
        return Search(node->left,key);
    }else{
        return Search(node->right,key);
    }
return false;
}


bool Search(int value){
    return Search(root , value);
}

Node*FindMin(Node*node){
    if(node == nullptr){
        return nullptr;
    }
    else{
        while(node->left != nullptr){
            node = node->left;
        }
    }
    return node;
}

Node*Delete(Node*node , int value){
    if(node == nullptr){
        return nullptr;
    }
    if(value < node->data){
        node->left = Delete(node->left ,value);
    }else if(value > node->data){
        node->right = Delete(node->right,value);
    }else{
        if(node->right == nullptr && node->left == nullptr){
            delete node;
            return nullptr;
        }else if(node->right == nullptr){
            Node*temp = node->left;
            delete node;
            return temp;
        }else if(node->left == nullptr){
            Node*temp = node->right;
            delete node;
            return temp;
        }else{
            Node*temp  = FindMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right,temp->data);
        }
    }
}
void insert(int value){
    root = insert(root , value);
}

int height(){
    return height(root);
}

void Delete(int value){
    root = Delete(root , value);
}

void Inorder(){
    Inorder(root);
    cout<<endl;
}
};
int main(){
BST tree;
tree.insert(21);
tree.insert(32);
tree.insert(25);
tree.insert(32);
tree.insert(22);
tree.insert(20);
tree.insert(12);
cout<<"After Insertion Tree is: "<<endl;
tree.Inorder();
if(tree.Search(21)){
    cout<<"Found !"<<endl;
}

cout<<"Minimum Node Value is: "<<tree.FindMin(tree.root)->data<<endl;
    return 0;
}