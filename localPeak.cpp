#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A) {
    int start = 0;
    int size = A.size();
    int end = size-1;
    int mid;
    while(start<=end) {
        mid = start + (end-start)/2;
        if (mid==0 && A[mid]>A[mid+1]) {
            return A[mid];
        }
        if (mid==size-1 && A[mid-1]<A[mid]) {
            return A[mid];
        }
        if (A[mid-1]<=A[mid] && A[mid+1]<=A[mid]) {
            return A[mid];
        }
        if (A[mid-1]>A[mid]) {
            //go left
            end = mid-1;
            continue;
        } else {
            //go right
            start = mid+1;
            continue;
        }
    }
}

int main() {
    vector<int> a{5, 17, 100, 10};
    cout << solve(a) << endl;
    return 0;
}