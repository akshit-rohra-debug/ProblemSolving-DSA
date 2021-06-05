/*
* Shaggy has an array A consisting of N elements.
* We call a pair of distinct indices in that array as a
* special pair if elements at that index in the array are equal.
* Shaggy wants you to find a special pair such that distance
* between that pair is minimum. Distance between two indices is
* defined as |i-j|. If there is no special pair in the array then return -1.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

int solve(vector<int> &A) {
    int size = A.size();
    int min = size;
    unordered_map<int, int> f;
    unordered_map<int, int> s;
    //Create hash of all number, first occurence
    //Create hash of all number, second occurence
    for (int i=0;i<size;i++) {
        if (f.find(A[i])==f.end()) {
            //not found
            f[A[i]] = i;
        } else {
            //found
            if (s.find(A[i])==s.end()) {
                //not found
                s[A[i]] = i;
                int temp = abs(s[A[i]]-f[A[i]]);
                if (temp < min) {
                    min = temp;
                }
            }
        }
    }
    if (s.size()==0) return -1;
    return min;
}

int main() {
    vector<int> A{7,1,3,4,1,7};
    cout << solve(A) << endl;
    return 0;
}