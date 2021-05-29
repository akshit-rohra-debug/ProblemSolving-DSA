/*
* Given a string A, partition A such that every string of
* the partition is a palindrome. Return all possible
* palindrome partitioning of A.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> result;

bool isPalindrome(string str, int i, int j) {
    while(i<=j) {
        if (str[i++]!=str[j--])
            return false;
    }
    return true;
}

void partition(string str, int i, int j, vector<string> &v) {
    if (i>j) {
        result.push_back(v);
        return;
    }
    for (int x=i;x<=j;x++) {
        if (isPalindrome(str,i,x)) {
            v.push_back(str.substr(i, x-i+1));
            partition(str,x+1,j,v);
            v.pop_back();
        }
    }
}

int main() {
    vector<string> v;
    partition("aab",0,2,v);
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}