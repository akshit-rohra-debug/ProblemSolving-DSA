/*
* Given an array of integers A .
* A represents a histogram i.e A[i] denotes height of
* the ith histogram's bar. Width of each bar is 1.
* Find the area of the largest rectangle formed by the histogram.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerOnLeft(vector<int> &a) {
    vector<int> result;
    stack<int> st;
    int size = a.size();
    int i=0;
    while(i<size) {
        if(st.size()==0) {
            result.push_back(-1);
            st.push(i);
            i++;
        } else {
            if (a[st.top()] < a[i]) {
                result.push_back(st.top());
                st.push(i);
                i++;
            } else {
                while(st.size()!=0) {
                    if (a[st.top()] >= a[i]) {
                        st.pop();
                        continue;
                    }
                    break;
                }
            }
        }
    }
    return result;
}

vector<int> nearestSmallerOnRight(vector<int> &a) {
    stack<int> st;
    int size = a.size();
    vector<int> result(size,-1);
    int i=size-1;
    while(i>-1) {
        if(st.size()==0) {
            result[i]=size;
            st.push(i);
            i--;
        } else {
            if (a[st.top()] < a[i]) {
                result[i]=st.top();
                st.push(i);
                i--;
            } else {
                while(st.size()!=0) {
                    if (a[st.top()] >= a[i]) {
                        st.pop();
                        continue;
                    }
                    break;
                }
            }
        }
    }
    return result;
}

int solve(vector<int>& A) {
    int sum = 0;
    vector<int> smallerLeft = nearestSmallerOnLeft(A);
    vector<int> smallerRight = nearestSmallerOnRight(A);
    for (int i=0;i<A.size();i++) {
        int temp = A[i]*(smallerRight[i]-smallerLeft[i]-1);
        if (temp>sum)
            sum = temp;
    }
    return sum;
}

int main() {
    vector<int> A{2,1,5,6,2,3};
    cout << solve(A) << endl;
    return 0;
}
