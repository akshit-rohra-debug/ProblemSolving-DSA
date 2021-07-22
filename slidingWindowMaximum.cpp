/*
Given an array of integers A. There is a sliding window of size B which
is moving from the very left of the array to the very right. You can only see
the B numbers in the window. Each time the sliding window moves rightwards by
one position. You have to find the maximum for each window.
Return an array C, where C[i] is the maximum value in the array from A[i] to A[i+B-1].
Refer to the given example for clarity.
NOTE: If B > length of the array, return 1 element with the max of the array.

Input:	A = [3,1,-1,-3,5,3,6,7]
		B = 3
Output: 3 1 5 5 6 7
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

vector<int> solve(const vector<int> &A, int B) {
    vector<int> ans;
    deque<int> dq;
    // Prepare deque for B elements first
    for (int i=0;i<B;i++) {
        // If deque empty, add to deque
        if (dq.empty()) {
            dq.push_back(A[i]);
        } else {
            while(dq.back() < A[i]) {
                dq.pop_back();
                if (dq.empty()) {
                    break;
                }
            }
            dq.push_back(A[i]);
        }
    }
    ans.push_back(dq.front());
    for (int i=B;i<A.size();i++) {
        if (A[i-B]==dq.front()) {
            dq.pop_front();
        }
        if (dq.empty()) {
            dq.push_back(A[i]);
        } else {
            while(dq.back() < A[i]) {
                dq.pop_back();
                if (dq.empty()) break;
            }
            dq.push_back(A[i]);
        }
        ans.push_back(dq.front());
    }
    return ans;
}

int main() {
    vector<int> A{3,1,-1,-3,5,3,6,7};
    int B = 3;
    vector<int> ans = solve(A,B);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
