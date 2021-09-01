/*
* A students applied for admission in IB Academy. An array of integers B is given representing
* the strengths of A people i.e. B[i] represents the strength of ith student.
* 
* Among the A students some of them knew each other. A matrix C of size M x 2 is given
* which represents relations where ith relations depicts that C[i][0] and C[i][1] knew each other.
* 
* All students who know each other are placed in one batch.
* 
* Strength of a batch is equal to sum of the strength of all the students in it.
* 
* Now the number of batches are formed are very much, it is impossible for IB to handle them.
* So IB set criteria for selection: All those batches having strength at least D are selected.
* 
* Find the number of batches selected.
* 
* NOTE: If student x and student y know each other, student y and z know each other then
* student x and student z will also know each other.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(unordered_map<int, vector<int>> &adj_list, unordered_map<int, bool> &visited, int node, vector<int> &strength, int &batch_st) {
    visited[node]=true;
    batch_st += strength[node-1];
    if (adj_list.find(node)==adj_list.end()) return;
    for (int i=0;i<adj_list[node].size();i++) {
        if (!visited[adj_list[node][i]]) {
            dfs(adj_list, visited, adj_list[node][i], strength, batch_st);
        }
    }
}

int Batches(int A, vector<int> &B, vector<vector<int>> &C, int D) {
    int batches = 0;
    unordered_map<int, vector<int>> adj_list;
    unordered_map<int, bool> visited;
    // Create adj list
    for (int i=0;i<C.size();i++) {
        if (adj_list.find(C[i][0])==adj_list.end()) {
            adj_list[C[i][0]] = vector<int> {};
        }
        if (adj_list.find(C[i][1])==adj_list.end()) {
            adj_list[C[i][1]] = vector<int> {};
        }
        adj_list[C[i][0]].push_back(C[i][1]);
        adj_list[C[i][1]].push_back(C[i][0]);
    }
    // Initialize visited
    for (int i=1;i<=A;i++) {
        visited[i]=false;
    }
    int batch_st;
    for (int i=1;i<=A;i++) {
        if (!visited[i]) {
            batch_st = 0;
            dfs(adj_list, visited, i, B, batch_st);
            if (batch_st>=D)
                batches++;
        }
    }
    return batches;
}

int main() {
    int A=7;
    vector<int> B{1, 6, 7, 2, 9, 4, 5};
    vector<vector<int>> C;
    C.push_back(vector<int> {1,2});
    C.push_back(vector<int> {2,3});
    C.push_back(vector<int> {5,6});
    C.push_back(vector<int> {5,7});
    int D=12;
    cout << Batches(A,B,C,D) << endl;
    A=5;D=6;
    C.clear();
    vector<int> X{1,2,3,4,5};
    C.push_back(vector<int> {1,5});
    C.push_back(vector<int> {2,3});
    cout << Batches(A,X,C,D) << endl;
    return 0;
}
