/*
* Given three positive integers A, B and C.
* Any positive integer is magical if it is divisible
* by either B or C. Return the Ath magical number. Since
* the answer may be very large, return it modulo 109 + 7.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (a==0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return ((a*b)/gcd(a,b));
}

int getPosition(long long int mid, int B, int C) {
    int n1 = mid/B;
    int n2 = mid/C;
    int c = mid/lcm(B,C);
    return (n1+n2-c);
}

int solve(int A, int B, int C) {
    long long int low = min(B,C);
    long long int high = low*A+1;
    long long int mid;
    while(low<high) {
        mid = low + (high-low)/2;
        int pos = getPosition(mid,B,C);
        //cout << "Low: " << low << endl;
        //cout << "Mid: " << mid << endl;
        //cout << "High: " << high << endl;
        //cout << "Pos: " << pos << endl;
        if (pos<A)
            low = mid+1;
        else
            high = mid;
    }
    return low%1000000007;
}

int main() {
    cout << solve(807414236,3788,38141) << endl;
    return 0;
}