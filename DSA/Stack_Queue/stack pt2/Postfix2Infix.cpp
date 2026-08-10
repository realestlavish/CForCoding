#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfix2infix(string s){
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
            st.push("("+op1+c+op2+")");
        }
    }
    return st.top();
}

int main(){
    string s= "ab+c*";
    cout<<"Infix expression is: "<<postfix2infix(s)<<endl;
    return 0;
}