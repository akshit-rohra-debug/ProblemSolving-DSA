/*
* A country consist of N cities connected by N - 1 roads. King of that country want to construct
* maximum number of roads such that the new country formed remains bipartite country.
* Bipartite country is a country, whose cities can be partitioned into 2 sets in such a way,
* that for each road (u, v) that belongs to the country, u and v belong to different sets. Also,
* there should be no multiple roads between two cities and no self loops.
* Return the maximum number of roads king can construct. Since the answer could be
* large return answer % 109 + 7.
* NOTE: All cities can be visited from any city.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Colored as 1
long long int m=0;
// Colored as 2
long long int n=0;

int getColor(int i) {
    if (!i) return 1;
    if (i==1) return 2;
    if (i==2) return 1;
    return 0;
}

void dfs(unordered_map<int, vector<int>> &adj_list, unordered_map<int, int> &visited, int node, int color) {
    // Process color
    visited[node] = color;
    if (color==1) m++;
    if (color==2) n++;
    if (adj_list.find(node)==adj_list.end()) return;
    for (int i=0;i<adj_list[node].size();i++) {
        if (!visited[adj_list[node][i]]) {
            dfs(adj_list, visited, adj_list[node][i], getColor(visited[node]));
        }
    }
}

int MaxEdges(int A, vector<vector<int>> &B) {
    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, int> visited;
    m = 0;
    n = 0;
    for (int i=1;i<=A;i++) {
        visited[i]=0;
    }
    // Create adj list
    for (int i=0;i<B.size();i++) {
        if (adj_list.find(B[i][0])==adj_list.end()) {
            adj_list[B[i][0]] = vector<int> {};
        }
        if (adj_list.find(B[i][1])==adj_list.end()) {
            adj_list[B[i][1]] = vector<int> {};
        }
        adj_list[B[i][0]].push_back(B[i][1]);
        adj_list[B[i][1]].push_back(B[i][0]);
    }
    for (int i=1;i<=A;i++) {
        if (!visited[i]) {
            dfs(adj_list, visited, i, getColor(0));
        }
    }
    if ((1ll*m*n)<1ll*(A-1)) return 0;
    long long int sum = ((1ll*(m*n))-(A-1))%1000000007;
    return sum;
}

int main() {
    int a = 5;
    vector<vector<int>> b;
    b.push_back(vector<int> {1,3});
    b.push_back(vector<int> {1,4});
    b.push_back(vector<int> {3,2});
    b.push_back(vector<int> {3,5});
    cout << MaxEdges(a,b) << endl;
    b.clear();
    a = 3;
    b.push_back(vector<int> {1,2});
    b.push_back(vector<int> {1,3});
    cout << MaxEdges(a,b) << endl;
    b.clear();
    a = 2;
    b.push_back(vector<int> {2,1});
    cout << MaxEdges(a,b) << endl;
    return 0;
}
