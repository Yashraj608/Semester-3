#include <iostream>
#include <vector>
#include<string>
using namespace std;


void buildLPS(const string &pat, vector<int> &lps) {
        int n = pat.length();
        int length = 0;
        lps[0] = 0;

        int i =1;
        while(i < n){
            if(pat[i]==pat[length]){
                length++;
             lps[i]  = length;
                i++;
            }else if(length != 0){
                length = lps[length-1];
            }else{
                lps[i] =0;
                i++;
            }
        }
}

void KMP(const string &text, const string &pat) {
    int n = text.length();
    int m = pat.length();
    vector<int>lps(m);
    buildLPS(pat,lps);

    int i =0;
    int j =0;
    while(i < n){
        if(pat[j]==text[i]){
            i++;
            j++;
        }

        if(j == m ){
            cout<<"Pattern found at : "<<(i-j)<<endl;
            j = lps[j-1];
        }else if(i <n && text[i] != pat[j]){
               if(j != 0){
                j = lps[j-1];
               }else{
                i++;
               }
        }
    }
}

int main(){
    string text , pattern;
    cout<<"Enter the text : "<<endl;
    getline(cin , text);

    cout<<"Enter the pattern : "<<endl;
    getline(cin, pattern);

    KMP(text,pattern);
}
