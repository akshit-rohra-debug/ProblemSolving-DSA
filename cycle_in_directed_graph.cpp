/*
* Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents
* the M edges such that there is a edge directed from node B[i][0] to node B[i][1].
* Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.
* NOTE:	
*     The cycle must contain atleast two nodes.
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

int dfs(unordered_map<int, vector<int>> &adj_list, unordered_map<int, bool> &visited, unordered_map<int, bool> &rec_stack, int node) {
    if (adj_list.find(node)==adj_list.end()) return 0;
    visited[node]=true;
    rec_stack[node]=true;
    for (int i=0;i<adj_list[node].size();i++) {
        if (!visited[adj_list[node][i]]) {
            if (dfs(adj_list, visited, rec_stack, adj_list[node][i])) {
                return 1;
            }
        } else if (rec_stack[adj_list[node][i]]) {
            return 1;
        }
    }
    rec_stack[node]=false;
    return 0;
}

int CycleExists(int A, vector<vector<int>> &B) {
    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> rec_stack;
    for (int i=1;i<=A;i++) {
        visited[i]=false;
        rec_stack[i]=false;
    }
    // Create adj list
    for (int i=0;i<B.size();i++) {
        if (adj_list.find(B[i][0])==adj_list.end()) {
            adj_list[B[i][0]] = vector<int> {};
        }
        adj_list[B[i][0]].push_back(B[i][1]);
    }
    for (int i=1;i<=A;i++) {
        if (!visited[i]) {
            if (dfs(adj_list, visited, rec_stack, i)) return 1;
        }
    }
    return 0;
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
    cout << CycleExists(a,b) << endl;
    b.clear();
    b.push_back(vector<int> {1,2});
    b.push_back(vector<int> {2,3});
    b.push_back(vector<int> {3,4});
    b.push_back(vector<int> {4,5});
    cout << CycleExists(a,b) << endl;
    b.clear();
    b.push_back(vector<int> {1,2});
    b.push_back(vector<int> {1,3});
    b.push_back(vector<int> {2,3});
    b.push_back(vector<int> {1,4});
    b.push_back(vector<int> {4,3});
    b.push_back(vector<int> {4,5});
    b.push_back(vector<int> {3,5});
    cout << CycleExists(a,b) << endl;
    b.clear();
    b.push_back(vector<int> {1,2});
    cout << CycleExists(a,b) << endl;
    return 0;
}
