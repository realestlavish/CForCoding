#include <iostream>
#include <stack>
#include <string>
using namespace std;

string prefix2postfix(string s){
    stack<string> st;
    int n=s.length();
    string res="";
    for(int i= n-1 ;i>=0 ;i--){
        char c=s[i];
        if(isalnum(c)){
            st.push(string(1, c));
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            res=op1+op2+c;
            st.push(res);
        }
    }
    return st.top();
}

int main(){
    string s= "*+ab-cd";
    cout<<"Postfix expression is: "<<prefix2postfix(s)<<endl;
    return 0;
}
