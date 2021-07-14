/*
* Given an integer A. Return minimum count of numbers,
* sum of whose squares is equal to A.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(int A) {
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    for (int i=3;i<=A;i++) {
        int minimum = i;
        for (int j=1;j*j<=i;j++) {
            minimum = min(minimum, arr[i-(j*j)]+1);
        }
        arr.push_back(minimum);
    }
    return arr[A];
}

int main() {
    cout << solve(13) << endl;
    return 0;
}
