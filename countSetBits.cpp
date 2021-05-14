/*
* Given a positive integer A, the task is to count the total number
* of set bits in the binary representation of all the numbers
* from 1 to A.
* Return the count modulo 109 + 7.
*/

#include <iostream>
using namespace std;

int solve(int A) {
    A++;
    int count = A/2;
    const int mod = 1e9+7;
    int powerOf2 = 2;
    while (powerOf2<A) {
        int getPairs = A/powerOf2;
        int ones = (getPairs/2)*powerOf2;
        count = (count+ones)%mod;
        ones = (getPairs & 1)?(A%powerOf2):0;
        count = (count+ones)%mod;
        powerOf2 = powerOf2<<1;
    }
    return count;
}

int main()
{
    cout << solve(5) << endl;
    return 0;
}