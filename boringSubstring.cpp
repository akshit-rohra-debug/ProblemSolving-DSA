/*
* Given a string A of lowercase English alphabets. Rearrange the characters
* of the given string A such that there is no boring substring in A.
* A boring substring has the following properties:
* 	Its length is 2.
* 	Both the characters are consecutive, for example - "ab", "cd", "dc", "zy" etc.
* 	(If the first character is C then the next character can be either (C+1) or (C-1)).
* Return 1 if it possible to rearrange the letters of A such that
* there are no boring substring in A, else return 0.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

bool isBoring(string x) {
    if (x.length()==0) return false;
    for (int i=0;i<x.length()-1;i++) {
        if (abs(x[i]-x[i+1])==1) return true;
    }
    return false;
}

int solve(string A) {
    string odd;
    string even;
    for (int i=0;i<A.length();i++) {
        if (A[i]%2==0)
            odd += A[i];
        else
            even += A[i];
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    if (isBoring(odd+even) && isBoring(even+odd)) return 0;
    return 1;
}

int main() {
    string A = "abcd";
    cout << solve(A) << endl;
    return 0;
}
