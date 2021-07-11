/*
* Given two arrays of integers A and B of size N each, where each pair (A[i], B[i])
* for 0 <= i < N represents a unique point (x, y) in 2-D Cartesian plane.
* Find and return the number of unordered quadruplet (i, j, k, l) such that
* (A[i], B[i]), (A[j], B[j]), (A[k], B[k]) and (A[l], B[l]) form a rectangle with the
* rectangle having all the sides parallel to either x-axis or y-axis.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

unordered_map<int, unordered_map<int, int>> hmap;

bool findXY(int x, int y) {
    if (hmap.find(x) == hmap.end()) return false;
    if (hmap[x].find(y) == hmap[x].end()) return false;
    return true;
}

int solve(vector<int>& A, vector<int>& B) {
    hmap.clear();
    int count = 0;
    int size = A.size();
    // Create hashmap
    for (int i = 0; i < size; i++) {
        if (hmap.find(A[i]) == hmap.end()) {
            unordered_map<int, int> x;
            x[B[i]] = 1;
            hmap[A[i]] = x;
        }
        else {
            hmap[A[i]][B[i]] = 1;
        }
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (A[i] == A[j]) continue;
            if (B[i] == B[j]) continue;
            if (!findXY(A[i], B[j])) {
                continue;
            }
            if (!findXY(A[j], B[i])) {
                continue;
            }
            count++;
        }
    }
    return count / 2;
}

int main() {
    vector<int> A{ 1,1,2,2,3,3 };
    vector<int> B{ 1,2,1,2,1,2 };
    cout << solve(A, B) << endl;
    return 0;
}
