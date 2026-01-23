#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*right, *left;
Node(int data){
    this->data= data;
    right = left = nullptr;
}
};
Node*insert(Node*root, int value){
    if(root == nullptr){
        return new Node(value);
    }
    if(root->data > value){
    root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
    return root;
}


int height(Node*root){
    if(root == nullptr){
        return 0;
    }
    int rightHeight = height(root->right);
    int leftHeight = height(root->left);
    return 1+ max(rightHeight , leftHeight);
}
bool Search(Node*root, int key){
    if(root == nullptr){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data > key){
    return Search(root->left, key);
    }else if(root->data < key){
        return Search(root->right , key);
    }
    return false;
}


void Inorder(Node*root){
    if(root == nullptr){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


void Preorder(Node*root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void postOrder(Node*root){
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

Node*FindMin(Node*root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

Node*FindMax(Node*root){
    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}

Node*Deletion(Node*root, int value){
    if(root == nullptr){
        return nullptr;
    }

    if(value < root->data){
        root->left = Deletion(root->left, value);
    }else if(value > root->data){
        root->right = Deletion(root->right,value);
    }else{

        if(root->left == nullptr && root->right == nullptr){
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
            root->data  = temp->data;
            root->right = Deletion(root->right, value);
        }
    }
return root;

}
int main(){
Node*root = nullptr;
root = insert(root,30);
root = insert(root,29);
root = insert(root,21);
root = insert(root,24);
root = insert(root,26);
root = insert(root,20);
cout<<"Inorder Traversal is: "<<endl;
Inorder(root);
cout<<endl;
Node * deleted  = Deletion(root , 20);
cout<<"Deleted Node is: "<<deleted->data<<" "<<endl;
cout<<"After deletion : "<<endl;
Inorder(root);
cout<<endl;
Node*maxElement = FindMax(root);
cout<<"Max Element is: "<<maxElement->data<<endl;

Node*minElement = FindMin(root);
cout<<"Min Element is  : "<<minElement->data<<endl;

int heightTree = height(root);
cout<<"Height of the bst is : "<<heightTree<<endl;
return 0;
}