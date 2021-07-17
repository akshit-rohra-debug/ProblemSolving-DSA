/*
* You are given a set of coins A. In how many ways can you make
* sum B assuming you have infinite amount of each coin in the set.
* NOTE:
* 	Coins in set A will be unique. Expected space complexity of this problem is O(B).
* 	The answer can overflow. So, return the answer % (106 + 7).
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(vector<int>& A, int B) {
    vector<long long int> dp;
    dp.push_back(1);
    for (int i=1;i<=B;i++) dp.push_back(0);
    sort(A.begin(),A.end());
    for (int i=0;i<A.size();i++) {
        for (int j=1;j<=B;j++) {
            if (j>=A[i]) {
                dp[j] += dp[j-A[i]];
                dp[j] = dp[j]%1000007;
            }
        }
    }
    return dp[B];
}

int main() {
    vector<int> A{1,3,4};
    int B=5;
    cout << solve(A,B) << endl;
    return 0;
}
