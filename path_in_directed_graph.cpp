/*
* Given an directed graph having A nodes labelled from 1 to A containing
* M edges given by matrix B of size M x 2such that there is a edge directed from node
* B[i][0] to node B[i][1].
* Find whether a path exists from node 1 to node A.
* Return 1 if path exists else return 0.
* NOTE:
*     There are no self-loops in the graph.
*     There are no multiple edges between two nodes.
*     The graph may or may not be connected.
*     Nodes are numbered from 1 to A.
*     Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int dfs(unordered_map<int, vector<int>> &adj_list, unordered_map<int, int> &visited, int node, int end_node) {
    // Mark node as visited
    visited[node]=1;
    if (node==end_node) return 1;
    if (adj_list.find(node)==adj_list.end()) return 0;
    for (int i=0;i<adj_list[node].size();i++) {
        if (visited.find(adj_list[node][i])==visited.end()) {
            if (dfs(adj_list, visited, adj_list[node][i], end_node)==1) {
                return 1;
            }
        }
    }
    return 0;
}

int PathExists(int A, vector<vector<int>> &B) {
    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, int> visited;
    // Create adj list
    for (int i=0;i<B.size();i++) {
        if (adj_list.find(B[i][0])==adj_list.end()) {
            adj_list[B[i][0]] = vector<int> {};
        }
        adj_list[B[i][0]].push_back(B[i][1]);
    }
    return dfs(adj_list, visited, 1, A);
}

int main() {
    int a = 5;
    vector<vector<int>> b;
    b.push_back(vector<int> {1,2});
    b.push_back(vector<int> {4,1});
    b.push_back(vector<int> {2,4});
    b.push_back(vector<int> {3,4});
    b.push_back(vector<int> {5,2});
    b.push_back(vector<int> {1,3});
    cout << PathExists(a,b) << endl;
    b.clear();
    b.push_back(vector<int> {1,2});
    b.push_back(vector<int> {2,3});
    b.push_back(vector<int> {3,4});
    b.push_back(vector<int> {4,5});
    cout << PathExists(a,b) << endl;
    return 0;
}
