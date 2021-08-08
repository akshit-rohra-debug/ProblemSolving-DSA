/*
* You are given N towns (1 to N). All towns are connected via unique directed path as mentioned in the input.
* Given 2 towns find whether you can reach the first town from the second without repeating any edge.
* B C : query to find whether B is reachable from C.
* Input contains an integer array A of size N and 2 integers B and C ( 1 <= B, C <= N ).
* There exist a directed edge from A[i] to i+1 for every 1 <= i < N. Also, it's guaranteed that A[i] <= i.
* NOTE: Array A is 0-indexed.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

bool dfs(unordered_map<int, vector<int>> &adj_list, int source, int dest) {
    if (source==dest) return true;
    if (adj_list.find(source)==adj_list.end()) return false;
    for (int i=0;i<adj_list[source].size();i++) {
        if (source!=adj_list[source][i]) {
            if (dfs(adj_list, adj_list[source][i], dest)) return true;
        }
    }
    return false;
}

int FindPath(vector<int> &A, const int B, const int C) {
    unordered_map<int, vector<int>> adj_list;
    // Create adj list
    for (int i=0;i<A.size();i++) {
        if (adj_list.find(A[i])==adj_list.end()) {
            adj_list[A[i]] = vector<int> {};
        }
        adj_list[A[i]].push_back(i+1);
    }
    if (dfs(adj_list, C, B)) return 1;
    return 0;
}

int main() {
    vector<int> A{1,1,2};
    int B = 1;
    int C = 2;
    cout << FindPath(A,B,C) << endl;
    B = 2;
    C = 1;
    cout << FindPath(A,B,C) << endl;
    return 0;
}
