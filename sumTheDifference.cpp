/*
* Question:
* Given an integer array A of size N.
* You have to find all possible non-empty subsequence of the array of numbers and then,
* for each subsequence, find the difference between the largest and smallest numbers in
* that subsequence Then add up all the differences to get the number.
* As the number may be large, output the number modulo 1e9 + 7 (1000000007).
* NOTE: Subsequence can be non-contiguous.
*/

/*
* Approach:
* It can be seen that if elements are sorted then taking any two indexes,
* there will be fixed number of K elements in between then.
* So you can take any number of K elements which are in between those two elemets.
* So the difference of the values of those two indexes will contribute 2 to the power of K (subsets) to the answer.
* So we will take all possible pairs of elements.
* 
* Example:
* 1 2 3 4
* If we take indexes 0 and 3 ie elements 1 and 4. There are 2 elements between them (2, 3).
* So 1 and 4 are be in 4 subsets which are
* a) 1 4
* b) 1 2 4
* c) 1 3 4
* d) 1 2 3 4
* Which is 2 to the power of 2.
* The complexity if O(N^2)
* 
* If we take close look at the approach above,
* we can solve it in O(N) also.
* After sorting the array,
* Answer is {A[N-1]2^(N-1) +A[N-2]2^(N-2) +…..+A[0]2^0} - {A[0]2^(N-1) + A[1]2^(N-2) +……+ A[0]2^0}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

long long int power(int i) {
    long long int mod = 1000000007;
    long long int ans=1;
    while(i>0) {
        ans=(ans*2)%mod;
        i--;
    }
    return ans;
}

int solve(vector<int>& A) {
    long long int sum = 0;
    sort(A.begin(),A.end());
    long long int mod = 1000000007;
    for (int i=0;i<A.size()-1;i++) {
        for (int j=i+1;j<A.size();j++) {
            long long int temp = power(j-i-1);
            temp = (temp*(long long int)(A[j]-A[i]))%mod;
            sum = (sum+temp)%mod;
        }
    }
    return (int)sum;
}

int main() {
    vector<int> A{1,2};
    cout << solve(A) << endl;
    return 0;
}
