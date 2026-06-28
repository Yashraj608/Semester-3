#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*right , *left;
int height;
Node(int value){
    this->data = value;
    right = left= nullptr;
    height =1 ;
}
};

int getHeight(Node*root){
    if(root == nullptr){
        return 0;
    }else{
        return root->height;
    }
}

int getBalance(Node*root){
    if(root == nullptr){
        return 0;
    }
    else{
        return getHeight(root->left) - getHeight(root->right);
    }
}


Node*rotateRight(Node*y){
    Node*x = y->left;
    Node*T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1+max(getHeight(y->left),getHeight(y->right));
    x->height = 1+max(getHeight(x->right),getHeight(x->left));
    return x;
}

Node*RotateLeft(Node*x){
    Node*y = x->right;
    Node*T2 = y->left;

    x->right = T2; 
    y->left = x;

    x->height = 1+max(getHeight(x->right),getHeight(x->left));
    y->height = 1+max(getHeight(y->left),getHeight(y->right));
    return y;
}

Node*insert(Node*root , int value){
    if(root == nullptr){
        return new Node(value);
    }

     if(root->data > value){
        root->left = insert(root->left, value);
     }else if(root->data < value){
        root->right = insert(root->right,value);
     }else{
        return root;
     }

     root->height = 1+ max(getHeight(root->left),getHeight(root->right));

     int balance = getBalance(root);

     if(balance > 1 && value < root->left->data){
        return rotateRight(root);
     }

     if(balance < -1 && value > root->right->data){
        return RotateLeft(root);
     }

     if(balance > 1 && value > root->left->data){
        root->left = RotateLeft(root->left);
        return rotateRight(root);
     }

     if(balance < -1 && value < root->right->data){
        root->right = rotateRight(root->right);
        return RotateLeft(root);
     }

     return root;
}

void Inorder(Node*root){
    if(root == nullptr){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void PreOrder(Node*root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

Node*FindMin(Node*root){
    if(root == nullptr){
        return nullptr;
    }
    else{
        while(root->left != nullptr){
            root= root->left;
        }
    }
    return root;
}

Node*deletion(Node*root , int value){
    if(root == nullptr){
        return nullptr;
    }
       if(root->data == value){
        delete root;
        return nullptr;
       }
    if(root->data < value){
    root->right = deletion(root->right , value);
    }else if(root->data > value){
        root->left = deletion(root->left,value);
    }else{
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            return nullptr;
        }else if(root->right == nullptr){
            Node*temp = root->left;
            delete root;
            return temp;
        }else if(root->left == nullptr){
            Node*temp = root->right;
            delete root;
            return temp;
        }else{
            Node*temp = FindMin(root->right);
            root->data = temp->data;
            root->right = deletion(root->right , temp->data);
        }
    }
    return root;
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    int balance = getBalance(root);

    if(balance > 1 && value < root->left->data){
        return rotateRight(root);
    }

    if(balance < -1 && value > root->right->data){
        return RotateLeft(root);
    }

    if(balance > 1 && value > root->left->data){
        root->left = RotateLeft(root->left);
        return rotateRight(root);
    }
    if(balance < -1 && value < root->right->data){
        root->right = rotateRight(root->right);
        return RotateLeft(root);
    }
}
int main(){
 Node*root = nullptr;
 root = insert(root, 22);
 root = insert(root, 28);
 root = insert(root, 21);
 root = insert(root, 23);
 root = insert(root, 3);
 root = insert(root, 9);
 root = insert(root, 10);
 root = insert(root, 12);
 root = insert(root, 13);
 root = insert(root, 15);


 cout<<"AVL Tree after insertion is : "<<endl;
 Inorder(root);

    return 0;
}