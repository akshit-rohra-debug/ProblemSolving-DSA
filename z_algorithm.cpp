/*
* Z-Algorithm
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

int main() {
    string s = "aabxaabxcaabxaabxay";
    vector<int> z = CreateZAlgo(s);
    for (int i=0;i<z.size();i++) {
        cout << z[i] << " ";
    }
    cout << endl;
    return 0;
}
