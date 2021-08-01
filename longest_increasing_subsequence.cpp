/*
* Find the longest increasing subsequence of a given array of integers, A.
* In other words, find a subsequence of array in which the subsequence's
* elements are in strictly increasing order, and in which the subsequence
* is as long as possible.
* In this case, return the length of the longest increasing subsequence.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LongestIncreasingSubsequence(const vector<int> &A) {
    // DP state
    // dp[i] = LIS ending at i
    // final answer is max element of dp array
    // dp[i] = max of (for j = 0 to i-1, if A[j]<A[i], add 1)
    vector<int> dp{1};
    for (int i=1;i<A.size();i++) {
        int max = 1;
        for (int j=0;j<i;j++) {
            if (A[i]>A[j] && (dp[j]+1)>max) {
                max = dp[j]+1;
            }
        }
        dp.push_back(max);
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> A{0,8,4,12,2,10,6,14,1,9,5,13};
    cout << LongestIncreasingSubsequence(A) << endl;
    return 0;
}
