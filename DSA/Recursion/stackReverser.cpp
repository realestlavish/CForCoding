#include <bits/stdc++.h>
using namespace std;

void stackReverser(stack<int> st){
    if (st.empty()) return;
    
    int elem=st.top();
    st.pop();

    stackReverser(st);
    stackReverserhelper(st,elem);
}

void stackReverserhelper(stack<int>st,int elem){
    if (st.empty()){
        st.push(elem);
        return;
    }
    int peeker=st.top();
    st.pop();
    stackReverserhelper(st,elem);
    st.push(peeker); 
}

int main(){
    stack<int>st;
    st.push(15);
    st.push(21);
    st.push(9);
    st.push(22);
    stackReverser(st);
}