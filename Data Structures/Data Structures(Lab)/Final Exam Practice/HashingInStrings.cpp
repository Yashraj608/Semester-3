#include<iostream>
using namespace std;
class LinearHashString{
public:
int size;
string *table;

LinearHashString(int size){
    this->size = size;
    table = new string[size];
    for(int i=0;i<size;i++){
        table[i] ="";
    }
}

int hashFunc(string key){
    int hash = 0;
    for(char c: key){
        hash = (hash *31 +int(c)) % size;
    }
    return hash;
}


void insert(string key){
    int index = hashFunc(key);
    int satrt = index;

    while(table[index] != ""){
        index = (index +1) % size;
        if(index == satrt){
            cout<<"Hash Table full !"<<endl;
            return;
        }
    }
    table[index] = key;
}


int search(string key){
    int index = hashFunc(key);
    int start = index;
    while(table[index] != key){
        if(table[index]==key){
            return index;
        }
        index = (index +1)%size;
        if(index == start){
            break;
        }
    }
    return -1;
}


void Display(){
    for(int i =0;i<size;i++){
        if(table[i] == ""){
            cout<<i<<" : -"<<endl;
        }else{
            cout<<i<<" : "<<table[i]<<endl;
        }
    }
}
};
int main(){
    int n;
    cout<<"Enter the size of hash table: "<<endl;
    cin>>n;

    LinearHashString ht(n);

    int keysCount;
    cout<<"Enter number of strings to insert : "<<endl;
    cin>>keysCount;

    cout<<"Enter strings: "<<endl;
    for(int i =0;i<keysCount;i++){
        string key;
        cin>>key;
        ht.insert(key);
    }


    cout<<"Hash Table: "<<endl;
    ht.Display();


    string keyToSearch;
    cout<<"Enter string to search: ";
    cin>>keyToSearch;

    int pos = ht.search(keyToSearch);
    if(pos != -1){
  cout<<"String : "<<keyToSearch<<" found at index : "<<pos<<endl;
    }else{
        cout<<"String not found "<<endl;
    }
    return 0;
}