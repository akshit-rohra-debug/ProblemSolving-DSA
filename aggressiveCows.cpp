#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canBeSettled(int mid, int B, vector<int> &A, int n) {
    B--;
    vector<int>::iterator it = A.begin();
    int last = (*it);
    //cout << "Cow at " << *it << endl;
    it++;
    while(B>0 && it!=A.end()) {
        if (((*it)-last)>=mid) {
            B--;
            last = (*it);
            //cout << "Cow at " << *it << endl;
        }
        it++;
    }
    return (B==0);
}

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int min = 0;
    int mid;
    int answer = -1;
    vector<int>::iterator it = A.end();
    it--;
    int max = (*it);
    
    while(min<=max) {
        mid = min + (max-min)/2;
        //cout << "Min: " << min << endl;
        //cout << "Max: " << max << endl;
        //cout << "Mid: " << mid << endl;
        bool flag = canBeSettled(mid, B, A, A.size());
        if (flag) {
            //cout << "True" << endl;
            answer = mid;
            min = mid+1;
        }
        else {
            //cout << "False" << endl;
            max=mid-1;    
        }
    }
    return answer;
}

int main() {
    vector<int> v{5,17,100,11};
    int noOfCows = 2;
    cout << solve(v,noOfCows) << endl;
    return 0;
}