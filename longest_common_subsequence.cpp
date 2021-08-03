/*
* Given two strings A and B. Find the longest common subsequence
* ( A sequence which does not need to be contiguous),
* which is common in both the strings.
* You need to return the length of such longest common subsequence.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int LongestCommonSubsequence(string A, string B) {
    int n = A.length();
    int m = B.length();
    int dp[n+1][m+1]={0};
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (i==0 || j==0)
                dp[i][j]=0;
            else {
                if (A[i-1]==B[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    return dp[n][m];
}

int main() {
    string A = "abbcdgf";
    string B = "bbadcgf";
    cout << LongestCommonSubsequence(A,B) << endl;
    return 0;
}
