/*
* Given an integer A pairs of parentheses, write a function
* to generate all combinations of well-formed parentheses of
* length 2*A.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> result;

void build(string str, int o, int c) {
    if (o==0 && c==0) {
        result.push_back(str);
        //cout << str << " - Final" << endl;
        return;
    }
    if (o>0) {
        //cout << str+"(" << endl;
        build(str+"(", o-1, c);
    }
    if (c>0 && c>o) {
        //cout << str+")" << endl;
        build(str+")", o, c-1);
    }
}

int main() {
    int n = 3;
    build("",n,n);
    for (int i=0;i<result.size();i++) {
        cout << result[i] << endl;
    }
    return 0;
}