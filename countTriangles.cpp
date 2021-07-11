/*
* Given two arrays of integers A and B of size N each, where each pair (A[i], B[i])
* for 0 <= i < N represents a unique point (x, y) in 2D Cartesian plane.
* Find and return the number of unordered triplets (i, j, k) such that
* (A[i], B[i]), (A[j], B[j]) and (A[k], B[k]) form a right angled triangle with
* the triangle having one side parallel to the x-axis and one side parallel to the y-axis.
* NOTE: The answer may be large so return the answer modulo (10^9 + 7).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

unordered_map<int, int> xmap;
unordered_map<int, int> ymap;

int solve(vector<int>& A, vector<int>& B) {
    xmap.clear();
    ymap.clear();
    int count = 0;
    int size = A.size();
    // Create hashmap
    for (int i = 0; i < size; i++) {
        if (xmap.find(A[i]) == xmap.end()) {
            xmap[A[i]] = 0;
        }
        else {
            xmap[A[i]]++;
        }
        if (ymap.find(B[i]) == ymap.end()) {
            ymap[B[i]] = 0;
        }
        else {
            ymap[B[i]]++;
        }
    }
    for (int i = 0; i < size; i++) {
        cout << A[i] << "," << B[i] << endl;
        int temp = xmap[A[i]] * ymap[B[i]];
        cout << "Temp: " << temp << endl;
        count += temp;
    }
    return count%1000000007;
}

int main() {
    vector<int> A{ 1,1,2,3,3 };
    vector<int> B{ 1,2,1,2,1 };
    cout << solve(A, B) << endl;
    return 0;
}
