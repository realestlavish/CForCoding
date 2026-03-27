#include <bits/stdc++.h>
using namespace std;

void stacksorter(stack<int> st){
    if (st.empty()) return;
    int elem=st.top();
    st.pop();
    stacksorterhelper(st,elem);
}

void stacksorterhelper(stack<int>st,int elem){
    if (st.empty()||st.top()>elem){
        st.push(elem);
        return;
    }
    int peeker=st.top();
    st.pop();
    stacksorterhelper(st,elem);
    st.push(peeker); 
}

int main(){
    stack<int>st;
    st.push(15);
    st.push(21);
    st.push(9);
    st.push(22);
    stacksorter(st);
}