#include<iostream>
using namespace std;
class LinearHash{
public:
int size;
int *table;
LinearHash(int size){
    this->size = size;
    table = new int[size];
    for(int i =0;i<size;i++){
        table[i] = -1;
    }
}


int HashFun(int key){
    return key % size;
}


void Insert(int key){
    int index = HashFun(key);
    int start = index;

    while(table[index] != -1){
        index = (index + 1)% size;
        if(index == start ){
            cout<<"Hash Table is Full and Cannot insert"<<endl;
            return;
        }
    }
    table[index] = key;
}


int Search(int key){
    int index = HashFun(key);
    int start = index;
    while(table[index] != -1){
        if(table[index] == key){
            return index;
        }
        index = (index +1)% size;
            if(index == start ){
                break;
            }
        }
        return -1;
    }



    void display(){
        for(int i =0;i<size;i++){
            cout<<i<<" : "<<table[i]<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter the size of hash table: "<<endl;
    cin>>n;

    LinearHash h(n);


    int keyCount;
    cout<<"Enter the number of keys to insert: "<<endl;
    cin>>keyCount;

    cout<<"Enter the keys: "<<endl;
    for(int i =0;i<keyCount;i++){
        int keys;
        cin>>keys;
        h.Insert(keys);
    }

    cout<<"Hash Tables: "<<endl;
    h.display();

    int keysToSearch;
    cout<<"Enter key to search"<<endl;
    cin>>keysToSearch;

    int pos = h.Search(keysToSearch);
    if(pos != -1){
        cout<<"Key "<<keysToSearch<<" found at index "<<pos<<endl;
    }else{
        cout<<"Keys not found !"<<endl;
    }
    return 0;
}