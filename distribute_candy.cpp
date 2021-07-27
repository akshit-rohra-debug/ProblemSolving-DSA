/*
* There are N children standing in a line. Each child is assigned a rating value.
* You are giving candies to these children subjected to the following requirements:
*     Each child must have at least one candy.
*     Children with a higher rating get more candies than their neighbors.
* What is the minimum candies you must give?
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(const vector<int> &A) {
    int size = A.size();
    vector<int> res(size,1);
    int result = 0;
    // right pass
    for (int i=1;i<size;i++) {
        if (A[i]>A[i-1]) {
            res[i]=max(res[i],res[i-1]+1);
        }
    }
    // left pass
    for (int i=size-2;i>-1;i--) {
        if (A[i]>A[i+1]) {
            res[i]=max(res[i],res[i+1]+1);
        }
    }
    for (int i=0;i<size;i++) {
        result+=res[i];
    }
    return result;
}

int main() {
    vector<int> A{1,5,2,1};
    cout << solve(A) << endl;
    return 0;
}
