#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*right , *left;
int height;
Node(int data){
    this->data = data;
    right = left = nullptr;
     height = 1;
}
};
int height(Node*root){
    if(root == nullptr){
        return 0;
    }
    return root->height;
}

Node*FindMin(Node*root){
    if(root == nullptr){
        return nullptr;
    }

    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}


Node*RightRotate(Node*y){
    Node*x = y->left;
    Node*T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height =  max(height(x->left),height(x->right)) +1;
    y->height = max(height(y->left),height(y->right)) +1;

    return x;
}

Node*LeftRotation(Node*x){
    Node*y = x->right;
    Node*T2 = y->left;

    x->right = T2;
    y->left = x;

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}

int getBalFactor(Node*root){
    return height(root->left) - height(root->right);
}

Node*insert(Node*root , int value){
if(root == nullptr){
    return new Node(value);
}
if(root->data < value){
    root->right = insert(root->right,value);
}else if(root->data > value){
    root->left = insert(root->left,value);
}else{
return root;
}


root->height  = 1 + max(height(root->left),height(root->right));

int balance = getBalFactor(root);

if(balance > 1 && value < root->left->data){
      return RightRotate(root);
}

if(balance < -1 && value >root->right->data){
    return LeftRotation(root);
}

if(balance > 1 && value >root->left->data){
    root->left = LeftRotation(root->left);
    return RightRotate(root);
}

if(balance < -1 && value < root->right->data){
    root->right = RightRotate(root->right);
    return LeftRotation(root);
}

return root;
}


Node*Deletion(Node*root, int value){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data < value){
        root->right = Deletion(root->right , value);
    }else if(root->data > value){
        root->left = Deletion(root->left,value);
    }else{
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            return nullptr;
        }else if(root->left == nullptr){
            Node*temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            Node*temp = root->left;
            delete root;
            return temp;
        }else{
            Node*temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Deletion(root->right , temp->data);
        }
    }
    
    if(root == nullptr){
        return nullptr;
    }
root->height  = 1 + max(height(root->left),height(root->right));

int balance = getBalFactor(root);

if(balance > 1 && value < root->left->data){
      return RightRotate(root);
}

if(balance < -1 && value >root->right->data){
    return LeftRotation(root);
}

if(balance > 1 && value >root->left->data){
    root->left = LeftRotation(root->left);
    return RightRotate(root);
}

if(balance < -1 && value < root->right->data){
    root->right = RightRotate(root->right);
    return LeftRotation(root);
}

return root;
}

bool Search(Node*root, int val){
    if(root == nullptr){
        return false;
    }
    if(root->data == val){
        return true;
    }

    if(root->data > val){
        return Search(root->left,val);
    }else{
        return Search(root->right, val);
    }
    return false;
}


void InOrder(Node*root){
    if(root == nullptr){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}


int main(){
    Node * root = nullptr;
    root = insert(root,20);
    root = insert(root,27);
    root = insert(root,23);
    root = insert(root,22);
    root = insert(root,24);
    root = insert(root,19);
    root = insert(root,17);
    root = insert(root,10);

    cout<<"After inserting : "<<endl;
    InOrder(root);
    root= Deletion(root, 10);
    cout<<endl;
    cout<<"After Deleting : "<<endl;
    InOrder(root);

return 0;
}