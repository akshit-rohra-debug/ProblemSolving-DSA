/*
* Given an array A of N integers, find three integers
* in A such that the sum is closest to a given number
* B. Return the sum of those three integers.
* 
* Assume that there will only be one solution.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int solve(vector<int>& A, int B) {
    int sum = 0;
    sort(A.begin(), A.end());
    long long int diff = -1+(long long int)(pow(2,63));
    int size = A.size();
    for (int i=0;i<size;i++) {
        int j=i+1, k=size-1;
        while(j<k) {
            long long int temp = A[i] + A[j] + A[k];
            cout << "Temp: " << temp << endl;
            cout << "Diff: " << abs(temp-B) << endl;
            if (abs(temp-B) < diff) {
                sum = (int)temp;
                diff = abs(temp-B);
                cout << "Sum: " << sum << endl;
            }
            if (temp<B) {
                j++;
            } else if (temp>B) {
                k--;
            } else {
                return sum;
            }
        }
    }
    return sum;
}

int main() {
    vector<int> A{5,-2,-1,-10,10};
    int B=5;
    cout << solve(A,B) << endl;
    return 0;
}