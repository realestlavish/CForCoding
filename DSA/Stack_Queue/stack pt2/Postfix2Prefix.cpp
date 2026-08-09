#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfix2prefix(string s){
    stack<string> st;
    int n=s.length();
    for(int i=0;i<n;i++){
        char c=s[i];
        if(isalnum(c)){
            st.push(string(1, c));
        }
        else{
            string op2=st.top();
            st.pop();
            string op1=st.top();
            st.pop();
            st.push(c+op1+op2);
        }
    }
    return st.top();
}

int main(){
    string s= "ab+cd-*";
    cout<<"Prefix expression is: "<<postfix2prefix(s)<<endl;
    return 0;
}