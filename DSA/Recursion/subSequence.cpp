
#include <bits/stdc++.h>
using namespace std;

void recurse(string arr, int n, int index, string current)
{
    if (index == n)
    {
        cout << current << endl;
        return;
    }
    // Pick the current element
    recurse(arr, n, index + 1, current + arr[index]);
    // Do not pick the current element
    recurse(arr, n, index + 1, current);
}

int main(){
    int n = 3;
    string arr = "abc";
    int index = 0;
    string current = "";
    recurse(arr, n, index, current);
    return 0;
}