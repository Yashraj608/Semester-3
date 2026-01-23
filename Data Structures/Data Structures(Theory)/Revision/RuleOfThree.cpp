#include<iostream>
#include<cstring>
using namespace std;
class book{
public:
int numberOfPages;
char*name;
book(){
    cout<<"Constructor called !"<<endl;
}
book(const char*n, int numberOfPages){
    name = new char[strlen(n)+1];
    strcpy(name,n);
    this->numberOfPages = numberOfPages;
}

book (const book&other){   //deep copy constructor//
  name = new char[strlen(other.name)+1];
  strcpy(name,other.name);
  numberOfPages = other.numberOfPages;
}

book & operator = (book const& other){   //Assignment Operator//
    if(this != &other){
        delete name;
        name = new char[strlen(other.name)+1];
        strcpy(name,other.name);

        numberOfPages = other.numberOfPages;
    }
    return *this;
}

~book(){
    delete[]name;
}

void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Number of pages: "<<numberOfPages<<endl;
}
};
int main(){

    book b1("C++ basic",200);
    book b2 = b1;
    b1.display();
    b2.display();

    cout<<b1.name<<" "<<b1.numberOfPages<<endl;

    book b3("Python Programming",300);
    b1 = b3;
    b1.display();
    b3.display();

    return 0;
}