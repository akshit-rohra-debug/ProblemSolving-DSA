/*
* Given two binary strings A and B, count how many cyclic
* permutations of B when taken XOR with A give 0.
* NOTE: If there is a string, S0, S1, ... Sn-1 , then it's
* cyclic permutation is of the form Sk, Sk+1, ... Sn-1, S0, S1,
* ... Sk-1 where k can be any integer from 0 to N-1.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> CreateZAlgo(string s) {
    int l=0,r=0;
    vector<int> z;
    int n=s.length();
    z.push_back(n);
    for (int i=1;i<n;i++) {
        // If i is outside the window
        if (i>r) {
            l=i;
            r=i;
            while(r<n && s[r]==s[r-l]) {
                r++;
            }
            z.push_back(r-l);
            r--;
        }
        // If i is inside any window
        else {
            // index of element we are making analogy with
            int j=i-l;
            if (z[j]<r-i+1) {
                z.push_back(z[j]);
            } else {
                l=i;
                while(r<n && s[r-l]==s[r]) {
                    r++;
                }
                z.push_back(r-l);
                r--;
            }
        }
    }
    return z;
}

int solve(string A, string B) {
    string n = A+"$"+B+B.substr(0,B.length()-1);
    vector<int> z = CreateZAlgo(n);
    int count=0;
    for (int i=1;i<z.size();i++) {
        if (z[i]>=A.length()) count++;
    }
    return count;
}

int main() {
    string s = "1001";
    string t = "0011";
    cout << solve(s,t) << endl;
    return 0;
}
