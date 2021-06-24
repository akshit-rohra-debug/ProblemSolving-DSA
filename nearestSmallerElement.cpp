/*
* Given an array A, find the nearest smaller element G[i] for every element
* A[i] in the array such that the element has an index smaller than i.
* 
* More formally,
* G[i] for an element A[i] = an element A[j] such that
* j is maximum possible AND
* j < i AND
* A[j] < A[i]
* 
* Elements for which no smaller element exist, consider next smaller element as -1.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> result;
    stack<int> st;
    int size = A.size();
    int i=0;
    while(i<size) {
        if(st.size()==0) {
            result.push_back(-1);
            st.push(A[i]);
            i++;
        } else {
            if (st.top() < A[i]) {
                result.push_back(st.top());
                st.push(A[i]);
                i++;
            } else {
                while(st.size()!=0) {
                    if (st.top() >= A[i]) {
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

int main() {
    vector<int> A{34, 35, 27, 42, 5, 28, 39, 20, 28};
    vector<int> answer = solve(A);
    for (int i=0;i<answer.size();i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}