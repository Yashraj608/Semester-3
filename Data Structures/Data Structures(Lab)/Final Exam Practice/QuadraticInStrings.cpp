#include<iostream>
using namespace std;
class Quadratic{
public:
int size;
string *table;
Quadratic(int size){
    this->size = size;
    table = new string[size];
    for(int i =0 ;i<size;i++){
      table[i] = "";
    }
}



int hashFun(string key){
    int hash =0;
    for(char c : key){
      hash = (hash * 31 + int(c)) % size;
    }
    return hash;
}



void Insert(string key){
    int index = hashFun(key);
    int i =0;
    while(table[(index + i *i) % size] != ""){
        i++;
        if(i == size){
            cout<<"Hash Table Full "<<endl;
            return;
        }
    }
    table[(index + i*i)% size] = key;
}




int Search(string key){
    int index = hashFun(key);
    int i = 0;

    while(table[(index + i*i) % size] != ""){
        if(table[(index + i*i) % size] == key){
            return (index + i*i) % size;
        }

        i++; 
        if(i == size) break; 
    }
    return -1; 
}



void Display(){
    for(int i =0;i<size;i++){
        if(table[i]==""){
            cout<<i<<" :- "<<endl;
        }else{
            cout<<i<<" : "<<table[i]<<endl;
        }
    }
}
};





int main(){
    int n;
    cout<<"Enter the size of HashTable: "<<endl;
    cin>>n;

    Quadratic q(n);

    int keysCount;
    cout<<"Enter the number of hash elements : "<<endl;
    cin>>keysCount;

    cout<<"Enter Strings: "<<endl;
    for(int i =0;i<keysCount;i++){
        string key;
        cin>>key;
        q.Insert(key);
    }


    cout<<"Quadratic Hash Table : "<<endl;
    q.Display();
    
    
    string KeyToSearch;
    cout<<"Enter the string to search: "<<endl;
    cin>>KeyToSearch;

    int pos = q.Search(KeyToSearch);
    if(pos != -1){
        cout<<"String :"<<KeyToSearch<<" found at index : "<<pos<<endl;
    }else{
        cout<<"Not Found !"<<endl;
    }
    return 0;
}