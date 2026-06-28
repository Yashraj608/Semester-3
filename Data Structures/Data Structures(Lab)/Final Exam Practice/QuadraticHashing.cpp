#include<iostream>
using namespace std;
class QuadHashing{
public:
int size;
int *table;

QuadHashing(int size){
    this->size = size;
    table = new int[size];
    for(int i =0;i<size;i++){
        table[i] = -1;
    }
}

int HashFun(int key){
    return key % size;
}
void insert(int key){
    int index = HashFun(key);
    int i =0;

    while(table[(index + i*i)%size] != -1){
        i++;
        if(i == size){
            cout<<"Hash Table Full"<<endl;
            return ;
        }
    }
    table[(index + i*i)%size] = key;
}


int Search(int key){
    int index = HashFun(key);
    int i =0;

    while(table[(index + i*i) % size] != -1){
        if(table[(index + i*i)% size] == key){
            return (index +i*i) %size;
            i++;
            if(i == size){
                break;
            }
        }
          
    }
    return -1;
}



void display(){
    for(int i =0;i<size;i++){
        if(table[i]==-1){
            cout<<i<<" : "<<endl;
        }else{
            cout<<i<<" : "<<table[i]<<endl;
        }
    }
}
};
int main(){
  int n ;
  cout<<"Enter the size of hash table : "<<endl;
  cin>>n;
  
  QuadHashing q(n);

  int keysCount;
  cout<<"Enter the number of keys to insert: "<<endl;
  cin>>keysCount;

  cout<<"Enter the keys : "<<endl;
  for(int i =0;i < keysCount;i++){
    int keys;
    cin>>keys;
    q.insert(keys);
  }

cout<<"Quadratic HashTable is: "<<endl;
  q.display();



  int keyToSearch;
  cout<<"Enter key to Search : "<<endl;
  cin>>keysCount;

  int pos = q.Search(keyToSearch);
  if(pos != -1){
    cout<<"Key : "<<keyToSearch<<" found at index : "<<pos<<endl; 
  }else{
    cout<<"Keys Not Found ! "<<endl;
  }
    return 0;
}