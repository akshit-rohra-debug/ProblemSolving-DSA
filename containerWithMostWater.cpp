/*
* Given n non-negative integers A[0], A[1], ..., A[n-1] ,
* where each represents a point at coordinate (i, A[i]).
* 
* N vertical lines are drawn such that the two endpoints
* of line i is at (i, A[i]) and (i, 0).
* 
* Find two lines, which together with x-axis forms a container,
* such that the container contains the most water.
* 
* Note: You may not slant the container.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int solve(vector<int>& A) {
    int result=0;
    int i=0,j=A.size()-1;
    while(i<j) {
        int temp = (j-i)*min(A[i],A[j]);
        if (temp>result) {
            result = temp;
        }
        if (A[i]==min(A[i],A[j])) {
            i++;
        } else {
            j--;
        }
    }
    return result;
}

int main() {
    vector<int> A{1};
    cout << solve(A) << endl;
    return 0;
}