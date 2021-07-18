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
            st.push(a[i]);
            i++;
        } else {
            if (st.top() < a[i]) {
                result.push_back(st.top());
                st.push(a[i]);
                i++;
            } else {
                while(st.size()!=0) {
                    if (st.top() >= a[i]) {
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
            st.push(a[i]);
            i++;
        } else {
            if (st.top() > a[i]) {
                result.push_back(st.top());
                st.push(a[i]);
                i++;
            } else {
                while(st.size()!=0) {
                    if (st.top() <= a[i]) {
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
            result[i]=-1;
            st.push(a[i]);
            i--;
        } else {
            if (st.top() < a[i]) {
                result[i]=st.top();
                st.push(a[i]);
                i--;
            } else {
                while(st.size()!=0) {
                    if (st.top() >= a[i]) {
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
            result[i]=-1;
            st.push(a[i]);
            i--;
        } else {
            if (st.top() > a[i]) {
                result[i]=st.top();
                st.push(a[i]);
                i--;
            } else {
                while(st.size()!=0) {
                    if (st.top() <= a[i]) {
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
    vector<int> A{4,7,3,8};
    vector<int> ans = nearestSmallerOnLeft(A);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    ans = nearestLargerOnLeft(A);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    ans = nearestSmallerOnRight(A);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    ans = nearestLargerOnRight(A);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
