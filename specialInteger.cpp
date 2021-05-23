/*
* Given an array of integers A and an integer B,
* find and return the maximum value K such that
* there is no subarray in A of size K with sum of
* elements greater than B.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &A, int B, int mid) {
    int counter = 0;
    vector<int>::iterator i,j;
    i = A.begin();
    j = A.begin();
    int sum = 0;
    while(counter<mid) {
        sum+=(*i);
        counter++;
        i++;
        if(sum>B) return false;
    }
    while(i!=A.end()) {
        sum += (*i) - (*j);
        if (sum>B) return false;
        i++;
        j++;
    }
    return true;
}
 
int solve(vector<int> &A, int B) {
    int low = 0;
    int high = A.size();
    int answer = -1;
    int mid;
    while(low<=high) {
        mid = low + (high-low)/2;
        if (isPossible(A, B, mid)) {
            //cout << "Mid: " << mid << endl;
            //cout << "True" << endl;
            answer = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return answer;
}

int main() {
    vector<int> A{5,17,100,11};
    int B=130;
    cout << solve(A,B) << endl;
    return 0;
}