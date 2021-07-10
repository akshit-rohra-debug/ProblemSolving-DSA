/*
* There are N jobs to be done but you can do only one job at a time.
* Given an array A denoting the start time of the jobs and an 
* array B denoting the finish time of the jobs.
* Your aim is to select jobs in such a way so that you can finish
* maximum number of jobs. Return the maximum number of jobs you can finish.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    int count=0;
    vector<int> cb = B;
    unordered_map<int, vector<int>> hmap;
    for (int i=0;i<B.size();i++) {
        if (hmap.find(B[i])==hmap.end()) {
            // add it
            hmap[B[i]]=vector<int>{A[i]};
        } else {
            hmap[B[i]].push_back(A[i]);
        }
    }
    int currTime=0;
    sort(cb.begin(), cb.end());
    for (int i=0;i<cb.size();i++) {
        if (currTime==0) {
            currTime=cb[i];
            count++;
        } else {
            int m = *max_element(hmap[cb[i]].begin(), hmap[cb[i]].end());
            if (currTime<=m) {
                currTime=cb[i];
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> A{4, 4, 8, 15, 6};
    vector<int> B{9, 5, 15, 16, 7};
    cout << solve(A, B) << endl;
    return 0;
}