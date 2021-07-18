/*
* Given an array of integers A.
* value of a array = max(array) - min(array).
* Calculate and return the sum of values of all possible subarrays of A % 109+7.
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

vector<int> nearestLargerOnLeft(vector<int> &a) {
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
            if (a[st.top()] > a[i]) {
                result.push_back(st.top());
                st.push(i);
                i++;
            } else {
                while(st.size()!=0) {
                    if (a[st.top()] <= a[i]) {
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

vector<int> nearestLargerOnRight(vector<int>& a) {
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
            if (a[st.top()] > a[i]) {
                result[i]=st.top();
                st.push(i);
                i--;
            } else {
                while(st.size()!=0) {
                    if (a[st.top()] <= a[i]) {
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
    vector<int> smallerLeft = nearestSmallerOnLeft(A);
    vector<int> smallerRight = nearestSmallerOnRight(A);
    vector<int> largerLeft = nearestLargerOnLeft(A);
    vector<int> largerRight = nearestLargerOnRight(A);

    long long int sum = 0;
    long long int mod = 1000000007;
    // Get min occurences
    vector<long long int> minOcc(A.size(),0);
    for (int j=0;j<A.size();j++) {
        // Left index
        int i = smallerLeft[j];
        // Right index
        int k = smallerRight[j];
        // Total occurences
        minOcc[j] = 1ll * (j-i) * (k-j);
    }
    // Get max occurences
    vector<long long int> maxOcc(A.size(), 0);
    for (int j=0;j<A.size();j++) {
        // Left index
        int i = largerLeft[j];
        // Right index
        int k = largerRight[j];
        // Total occurences
        maxOcc[j] = 1ll * (j-i) * (k-j);
    }
    // Get sum
    for (int i=0;i<A.size();i++) {
        sum += (1ll*A[i])*(maxOcc[i]-minOcc[i]);
        sum = ((sum % mod) + mod)%mod;
    }
    return (int)sum;
}

int main() {
    vector<int> A{4,7,3,8};
    int s = -1;
    cout << solve(A) << endl;
    return 0;
}
