/*
* Given an directed acyclic graph having A nodes. A matrix B of size M x 2 is given which
* represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].
* Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such
* that for every directed edge uv, vertex u comes before v in the ordering. Topological
* Sorting for a graph is not possible if the graph is not a DAG.
* Return the topological ordering of the graph and if it doesn't exist then return an empty array.
* If there is a solution return the correct ordering. If there are multiple solutions print
* the lexographically smallest one.
* Ordering (a, b, c) is said to be lexographically smaller than ordering (e, f, g)
* if a < e or if(a==e) then b < f and so on.
* 
* NOTE:
*     There are no self-loops in the graph.
*     There are no multiple edges between two nodes.
*     The graph may or may not be connected.
*     Nodes are numbered from 1 to A.
*     Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int getParent(int a) {
    if (a==0) {
        return -1;
    }
    return (a-1)/2;
}

int getFirstChild(int a) {
    if (a<0) return -1;
    return (2*a)+1;
}

void perculateUp(vector<int>& heap, int node) {
    int parent = getParent(node);
    int temp = heap[node];
    while(temp<heap[parent] && parent!=-1) {
        temp=heap[node];
        heap[node]=heap[parent];
        heap[parent]=temp;
        node=parent;
        parent=getParent(node);
    }
}

void perculateDown(vector<int>& heap, int node) {
    int size=heap.size();
    int firstChild=getFirstChild(node);
    while(true) {
        if (firstChild>=size) {
            return;
        } else if ((firstChild+1)>=size) {
            if (heap[node]>heap[firstChild]) {
                int temp=heap[node];
                heap[node]=heap[firstChild];
                heap[firstChild]=temp;
                node=firstChild;
            } else {
                return;
            }
        } else {
            if (heap[node]>heap[firstChild] || heap[node]>heap[firstChild+1]) {
                if (heap[firstChild]<heap[firstChild+1]) {
                    int temp=heap[node];
                    heap[node]=heap[firstChild];
                    heap[firstChild]=temp;
                    node=firstChild;
                } else {
                    int temp=heap[node];
                    heap[node]=heap[firstChild+1];
                    heap[firstChild+1]=temp;
                    node=firstChild+1;
                }
            } else {
                return;
            }
        }
        firstChild=getFirstChild(node);
    }
}

void createMinHeap(vector<int>& heap) {
    int size=heap.size();
    for(int x=(size/2)-1;x>=0;x--) {
        perculateDown(heap,x);
    }
}

void addToHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    perculateUp(heap,heap.size()-1);
}

int deleteRootNode(vector<int>& heap) {
    int ret = heap[0];
    int size = heap.size();
    heap[0] = heap[size-1];
    heap[size-1] = 0;
    heap.pop_back();
    perculateDown(heap, 0);
    return ret;
}

vector<int> TopologicalSort(int A, vector<vector<int>> &B) {
    vector<int> result;
    unordered_map<int, vector<int>> adj_list;
    vector<int> zero;
    unordered_map<int, int> indegree;
    // Create adj_list
    for (int i=0;i<B.size();i++) {
        if (adj_list.find(B[i][0])==adj_list.end()) {
            adj_list[B[i][0]] = vector<int> {};
        }
        adj_list[B[i][0]].push_back(B[i][1]);
        if (indegree.find(B[i][1])==indegree.end()) {
            indegree[B[i][1]]=0;
        }
        indegree[B[i][1]]++;
    }
    // Complete init for indegree
    for (int i=1;i<=A;i++) {
        if (indegree.find(i)==indegree.end()) {
            // does not exists, has indegree zero
            indegree[i]=0;
            zero.push_back(i);
        }
    }
    createMinHeap(zero);
    int size = zero.size();
    while(zero.size()) {
        int top = zero[0];
        deleteRootNode(zero);
        result.push_back(top);
        if (adj_list.find(top)==adj_list.end()) {
            continue;
        }
        for (int j=0;j<adj_list[top].size();j++) {
            indegree[adj_list[top][j]]--;
            if (indegree[adj_list[top][j]]==0) {
                addToHeap(zero, adj_list[top][j]);
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> A;
    int B = 6;
    A.push_back(vector<int>{6,3});
    A.push_back(vector<int>{6,1});
    A.push_back(vector<int>{5,1});
    A.push_back(vector<int>{5,2});
    A.push_back(vector<int>{3,4});
    A.push_back(vector<int>{4,2});
    vector<int> ans = TopologicalSort(B, A);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    A.clear();
    B = 3;
    A.push_back(vector<int>{1,2});
    A.push_back(vector<int>{2,3});
    A.push_back(vector<int>{3,1});
    ans.clear();
    ans = TopologicalSort(B, A);
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
