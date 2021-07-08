/*
* You are given a matrix A which represent operations of size N x 2.
* Assume initially you have a stack-like data structure you have
* to perform operations on it.
* 
* Operations are of two types:
* 
* 1 x: push an integer x onto the stack and return -1
* 
* 2 0: remove and return the most frequent element in the stack.
* 
* If there is a tie for the most frequent element, the element closest
* to the top of the stack is removed and returned.
* 
* A[i][0] describes the type of operation to be performed. A[i][1]
* describe the element x or 0 corresponding to the operation performed.
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> st;
vector<int> mfs;
unordered_map<int, int> hmap;

void deleteFunc(int val) {
    stack<int> temp;
    while(st[st.size()-1]!=val) {
        temp.push(st[st.size()-1]);
        st.pop_back();
    }
    st.pop_back();
    while(!temp.empty()) {
        st.push_back(temp.top());
        temp.pop();
    }
}

void push(int val) {
    if (st.size()==0) {
        st.push_back(val);
        mfs.push_back(val);
        hmap[val]=1;
    } else {
        st.push_back(val);
        if (hmap.find(val)==hmap.end()) {
            hmap[val]=1;
        } else {
            hmap[val]++;
        }
        if (hmap[mfs[mfs.size()-1]] <= hmap[val]) {
            mfs.push_back(val);
        }
    }
}

int pop() {
    int temp = mfs[mfs.size()-1];
    if (temp == st[st.size()-1]) {
        mfs.pop_back();
        st.pop_back();
        hmap[temp]--;
        return temp;
    }
    if (hmap[temp] > hmap[st[st.size()-1]]) {
        mfs.pop_back();
        deleteFunc(temp);
        hmap[temp]--;
        return temp;
    } else {
        int t = st[st.size()-1];
        st.pop_back();
        hmap[t]--;
        return t;
    }
}

vector<int> solve(vector<vector<int>> &A) {
    vector<int> answer;
    st.clear();
    mfs.clear();
    hmap.clear();
    for (int i=0;i<A.size();i++) {
        switch(A[i][0]) {
            case 1:
                push(A[i][1]);
                answer.push_back(-1);
                for (int i=0;i<st.size();i++) {
                    cout << st[i] << " ";
                }
                cout << endl;
                for (int i=0;i<mfs.size();i++) {
                    cout << mfs[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                answer.push_back(pop());
                for (int i=0;i<st.size();i++) {
                    cout << st[i] << " ";
                }
                cout << endl;
                for (int i=0;i<mfs.size();i++) {
                    cout << mfs[i] << " ";
                }
                cout << endl;
                break;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> ques{};
    ques.push_back(vector<int>{1,5});
    ques.push_back(vector<int>{1,7});
    ques.push_back(vector<int>{1,5});
    ques.push_back(vector<int>{1,7});
    ques.push_back(vector<int>{1,4});
    ques.push_back(vector<int>{1,5});
    ques.push_back(vector<int>{2,0});
    ques.push_back(vector<int>{2,0});
    ques.push_back(vector<int>{2,0});
    ques.push_back(vector<int>{2,0});
    vector<int> ans = solve(ques);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " " << endl;
    }
    return 0;
}
