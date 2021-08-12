/*
* Given a undirected graph having A nodes. A matrix B of size M x 2 is
* given which represents the edges such that there is an edge between B[i][0] and B[i][1].
* Find whether the given graph is bipartite or not.
* A graph is bipartite if we can split it's set of nodes into two independent
* subsets A and B such that every edge in the graph has one node in A and another node in B
* Note:
* 	There are no self-loops in the graph.
* 	No multiple edges between two pair of vertices.
* 	The graph may or may not be connected.
* 	Nodes are Numbered from 0 to A-1.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int GetColor(int color) {
    if (color==1) return 2;
    if (color==2) return 1;
    return 1;
}

bool dfs(unordered_map<int, vector<int>> &adj_list, unordered_map<int, int> &visited, int node, int color) {
    visited[node]=color;
    // new color
    color = GetColor(color);
    if (adj_list.find(node)==adj_list.end()) return true;
    for (int i=0;i<adj_list[node].size();i++) {
        if (visited[adj_list[node][i]]==0) {
            if (!dfs(adj_list, visited, adj_list[node][i], color))
                return false;
        }
        if (visited[adj_list[node][i]]!=color) return false;
    }
    return true;
}

int IsBipartite(int A, vector<vector<int>> &B) {
    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, int> visited;
    // Create adj list
    for (int i=0;i<B.size();i++) {
        if (adj_list.find(B[i][0])==adj_list.end()) {
            adj_list[B[i][0]] = vector<int>{};
        }
        adj_list[B[i][0]].push_back(B[i][1]);
        visited[B[i][0]]=0;
        if (adj_list.find(B[i][1])==adj_list.end()) {
            adj_list[B[i][1]] = vector<int> {};
        }
        adj_list[B[i][1]].push_back(B[i][0]);
        visited[B[i][1]]=0;
    }
    for (auto x : adj_list) {
        if (visited[x.first]==0) {
            if (!dfs(adj_list, visited, x.first, GetColor(0))) return 0;
        }
    }
    return 1;
}

int main() {
    vector<vector<int>> A;
    int B = 3;
    A.push_back(vector<int>{0,1});
    A.push_back(vector<int>{0,2});
    A.push_back(vector<int>{1,2});
    cout << IsBipartite(B, A) << endl;
    A.clear();
    B = 2;
    A.push_back(vector<int>{0,1});
    cout << IsBipartite(B, A) << endl;
    return 0;
}
