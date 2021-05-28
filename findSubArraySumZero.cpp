/*
* Given an array of integers A, find and return whether
* the given array contains a non-empty subarray with a
* sum equal to 0. If the given array contains a sub-array
* with sum zero return 1 else return 0.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<long long int> getPrefixSum(vector<int> &a) {
    vector<long long int> ps;
    int size = a.size();
    long long int sum = 0;
    ps.push_back(sum);
    for (int i=0;i<size;i++) {
        sum += a[i];
        ps.push_back(sum);
    }
    return ps;
}

int solve(vector<int> &A) {
    vector<long long int> ps = getPrefixSum(A);
    int psize = ps.size();
    unordered_map<long long int, int> um;
    for(int i=0;i<psize;i++) {
        if (um.find(ps[i])==um.end()) {
            //does not exists
            um[ps[i]]=0;
        } else {
            return 1;
        }
    }
    return 0;
}

int main() {
    vector<int> a{1,2,3,4,5,-6};
    cout << solve(a) << endl;
    return 0;
}