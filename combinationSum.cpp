/*
* Given a set of candidate numbers A and a target number B,
* find all unique combinations in A where the candidate numbers sums to B.
* The same repeated number may be chosen from A unlimited number of times.
* Note:
* 1) All numbers (including target) will be positive integers.
* 2) Elements in a combination (a1, a2, … , ak) must be in non-descending
*  order. (ie, a1 ≤ a2 ≤ … ≤ ak).
* 3) The combinations themselves must be sorted in ascending order.
* 4) CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2)
*  OR ... (a1 = b1 AND a2 = b2 AND ... ai = bi AND ai+1 > bi+1)
* 5) The solution set must not contain duplicate combinations.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;

void cSum(vector<int> &A, vector<int> &v, int sum, int B, int it) {
    if (sum==B) {
        result.push_back(v);
        return;
    } else if (sum>B) {
        return;
    }
    for (int i=it;i<A.size();i++) {
        v.push_back(A[i]);
        sum+=A[i];
        cSum(A,v,sum,B,i);
        v.pop_back();
        sum-=A[i];
    }
}

vector<vector<int>> solve(vector<int> &A, int B) {
    result.clear();
    sort(A.begin(), A.end());
    vector<int> AA;
    vector<int> v;
    AA.push_back(A[0]);
    int counter=0;
    for (int i=1;i<A.size();i++) {
        if(A[i]==AA[counter]) {
            continue;
        }
        AA.push_back(A[i]);
        counter++;
    }
    cSum(AA,v,0,B,0);
    return result;
}

int main() {
    vector<int> A{2,3,6,7};
    int B = 7;
    vector<vector<int>> result = solve(A,B);
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}