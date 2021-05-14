/*
* Given a sorted array of integers A where every element appears twice 
* except for one element which appears once, find and return this single
* element that appears only once.
*/

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A) {
    int answer=-1;
    int start = 0;
    int end = A.size()-1;
    int mid;
    while (start<=end) {
        mid = start + (end-start)/2;
        //cout << "start: " << start << endl;
        //cout << "mid: " << mid << endl;
        //cout << "end: " << end << endl;
        if (mid == 0) {
            if (A[mid] < A[mid+1]) {
                return A[mid];
            }
        } else if (mid == (A.size()-1)) {
            if (A[mid-1] < A[mid]) {
                return A[mid];
            }
        } else if ((A[mid-1] < A[mid]) && (A[mid] < A[mid+1])) {
            return A[mid];
        } else {
            if (A[mid-1]==A[mid]) {
                //first occurence is mid-1
                if ((mid-1)&1) {
                    //odd
                    end = mid-2;
                    continue;
                } else {
                    //even
                    start = mid+1;
                    continue;
                }
            } else {
                //first occurence is mid
                if (mid&1) {
                    //odd
                    end = mid - 1;
                    continue;
                } else {
                    //even
                    start = mid + 2;
                    continue;
                }
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> A{1,1,2,2,3};
    cout << solve(A) << endl;
    vector<int> B{1,1,2,3,3,4,4,5,5};
    cout << solve(B) << endl;
    vector<int> C{1,2,2,3,3,4,4};
    cout << solve(C) << endl;
    return 0;
}