/*
* Given a sorted array of integers (not necessarily distinct)
* A and an integer B, find and return how many pair of
* integers ( A[i], A[j] ) such that i != j have sum equal to B.
* 
* Since the number of such pairs can be very large,
* return number of such pairs modulo (109 + 7).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

int solve(vector<int>& A, int B) {
    //sort(A.begin(), A.end());
    unordered_map<long long int, long long int> hmap;
    vector<int> unique;
    long long int result=0;
    int size = A.size();
    long long int mod=1000000007;
    for (int i=0;i<size;i++) {
        if (hmap.find(A[i])==hmap.end()) {
            hmap[A[i]]=1;
            unique.push_back(A[i]);
        } else {
            hmap[A[i]]++;
        }
    }
    size = unique.size();
    int i = 0, j = size-1;
    while(i<j) {
        int temp = unique[i] + unique[j];
        //cout << unique[i] << ", " << unique[j] << ", " << temp << endl;
        if (temp==B) {
            long long int count = hmap[unique[i]]*hmap[unique[j]];
            //cout << "temp==B" << endl;
            result = (result+count)%mod;
        }
        if (temp<B) {
            i++;
        } else {
            j--;
        }
    }
    for (int i=0;i<size;i++) {
        if ((unique[i]*2)==B && hmap[unique[i]]>1) {
                long long int count = (hmap[unique[i]]*(hmap[unique[i]]-1))/2;
                //cout << "i*2" << endl;
                result = (result+count)%mod;
            }
    }
    return (int)result;
}

int main() {
    vector<int> A{1, 1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    int B = 2;
    cout << solve(A, B) << endl;
    return 0;
}
