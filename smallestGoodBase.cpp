/*
* Given an integer A, we call k >= 2 a good base of A, if all digits of A
* base k are 1. Now given a string representing A, you should return the
* smallest good base of A in string format.
* 
* let x be the good base of num
* => 1 + x + x^2 + x^3 + ... + x^(m-1) = num
* => x^m - 1 = num
* the max value of m will be 61
* explanation : 
* for m to be maximum, num will be 10^18 and x be 2
* 2^m - 1 = 10^18 => 2^m = 10^18+1 ~ 10^18
* taking log both sides
* log(2^m) = log(10^18) => m*log2 = 18 => m = (18 / 0.3) => m = 61 (approx).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long int getValue(int length, long long int base) {
    long long int sum = 0;
    for (int i=0;i<length;i++) {
        sum += pow(base,i);
    }
    return sum;
}

string solve(string A) {
    long long int num = stoll(A);
    long long int x = 1;
    for(int length=62;length>2;length--) {
        //Should we check for this length
        //If 2^length > num, any base with power length will be greater than num
        //So we won't find a case where base^length == num
        //So why check for it.
        if ((x<<length)>num) continue;
        long long int min=2;
        //for max, base=10^18 will create overflow
        //Therefore, we find maximum possible base for num
        //base^length-1 + base^length-2 + ... + 1 = num
        //base^length-1 < num
        //base < num^1/(length-1)
        //For max value for base
        //base = num^1/(length-1), we can also take num^1/(length)
        long long int max=pow(num,(float)1/(length-1));
        long long int mid;
        //cout << "Length: " << length << endl;
        while(min<=max) {
            mid = min + (max-min)/2;
            long long int val = getValue(length, mid);
            //cout << "Mid: " << mid << endl;
            //cout << "Val: " << val << endl;
            if (val==num) return to_string(mid);
            else if (val>num) max = mid-1;
            else min = mid+1;
        }
    }
    return to_string(num-1);
}

int main() {
    cout << solve("4681") << endl;
    return 0;
}