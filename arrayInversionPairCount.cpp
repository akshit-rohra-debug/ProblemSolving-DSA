/*
* Given an array of integers A. If i < j and A[i] > A[j]
* then the pair (i, j) is called an inversion of A. Find
* the total number of inversions of A modulo (109 + 7).
*/

#include <iostream>
#include <vector>
using namespace std;

long long int result;

void merge(vector<int> &A, int start, int mid, int end) {
    int lSize = mid-start+1;
    int rSize = end-mid;
    vector<int> l;
    vector<int> r;
    //Get left and right
    for(int i=start;i<=mid;i++)
        l.push_back(A[i]);
    for(int i=mid+1;i<=end;i++)
        r.push_back(A[i]);
    //Merge
    int i=0,j=0;
    int x = start;
    while(i<lSize && j<rSize) {
        if (l[i]>r[j]) {
            A[x++] = r[j++];
            result += lSize-i;
        } else {
            A[x++] = l[i++];
        }
    }
    while(i<lSize) {
        A[x++] = l[i++];
    }
    while(j<rSize) {
        A[x++] = r[j++];
    }
}

void partition(vector<int> &A, int start, int end) {
    if (start>=end) {
        return;
    }
    int mid = start + (end-start)/2;
    partition(A, start, mid);
    partition(A, mid+1, end);
    merge(A, start, mid, end);
}

int solve(vector<int> &A) {
    result=0;
    partition(A,0,A.size()-1);
    return (int)(result%1000000007);
}

int main() {
    vector<int> A{10,6,7,1,8,19,12,15};
    cout << solve(A);
    return 0;
}