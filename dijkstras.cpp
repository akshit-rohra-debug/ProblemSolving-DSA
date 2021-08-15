/*
* Given a weighted undirected graph having A nodes and M weighted edges, and a source node C.
* You have to find an integer array D of size A such that:
* => D[i] : Shortest distance form the C node to node i.
* => If node i is not reachable from C then -1.
* 
* Note:
* There are no self-loops in the graph.
* No multiple edges between two pair of vertices.
* The graph may or may not be connected.
* Nodes are numbered from 0 to A-1.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int getParent(int a) {
    if (a == 0) {
        return -1;
    }
    return (a - 1) / 2;
}

int getFirstChild(int a) {
    if (a < 0) return -1;
    return (2 * a) + 1;
}

void perculateUpWithPayload(vector<int>& heap, vector<int>& extra, int node) {
    int parent = getParent(node);
    int temp = heap[node];
    int tempe = extra[node];
    while (temp < heap[parent] && parent != -1) {
        temp = heap[node];
        tempe = extra[node];
        heap[node] = heap[parent];
        extra[node] = extra[parent];
        heap[parent] = temp;
        extra[parent] = tempe;
        node = parent;
        parent = getParent(node);
    }
}

void perculateDownWithPayload(vector<int>& heap, vector<int>& extra, int node) {
    int size = heap.size();
    int firstChild = getFirstChild(node);
    while (true) {
        if (firstChild >= size) {
            return;
        }
        else if ((firstChild + 1) >= size) {
            if (heap[node] > heap[firstChild]) {
                int temp = heap[node];
                int tempe = extra[node];
                heap[node] = heap[firstChild];
                extra[node] = extra[firstChild];
                heap[firstChild] = temp;
                extra[firstChild] = tempe;
                node = firstChild;
            }
            else {
                return;
            }
        }
        else {
            if (heap[node] > heap[firstChild] || heap[node] > heap[firstChild + 1]) {
                if (heap[firstChild] < heap[firstChild + 1]) {
                    int temp = heap[node];
                    int tempe = extra[node];
                    heap[node] = heap[firstChild];
                    extra[node] = extra[firstChild];
                    heap[firstChild] = temp;
                    extra[firstChild] = tempe;
                    node = firstChild;
                }
                else {
                    int temp = heap[node];
                    int tempe = extra[node];
                    heap[node] = heap[firstChild + 1];
                    extra[node] = extra[firstChild + 1];
                    heap[firstChild + 1] = temp;
                    extra[firstChild + 1] = tempe;
                    node = firstChild + 1;
                }
            }
            else {
                return;
            }
        }
        firstChild = getFirstChild(node);
    }
}

void createMinHeapWithPayload(vector<int>& heap, vector<int>& extra) {
    int size = heap.size();
    for (int x = (size / 2) - 1; x >= 0; x--) {
        perculateDownWithPayload(heap, extra, x);
    }
}

void addToHeapWithPayload(vector<int>& heap, int value1, vector<int>& extra, int value2) {
    heap.push_back(value1);
    extra.push_back(value2);
    perculateUpWithPayload(heap, extra, heap.size() - 1);
}

vector<int> deleteRootNodeWithPayload(vector<int>& heap, vector<int> &extra) {
    int ret = heap[0];
    int rete = extra[0];
    int size = heap.size();
    heap[0] = heap[size - 1];
    heap[size - 1] = 0;
    extra[0] = extra[size - 1];
    extra[size - 1] = 0;
    heap.pop_back();
    extra.pop_back();
    perculateDownWithPayload(heap, extra, 0);
    return vector<int> {ret, rete};
}

vector<int> Dijkstras(int A, vector<vector<int>> &B, int C) {
    vector<int> result;
    unordered_map<int, int> tresult;
    tresult[C]=0;
    unordered_map<int, vector<pair<int, int>>> adj_list;
    for (int i=0;i<B.size();i++) {
        if (adj_list.find(B[i][0])==adj_list.end()) {
            adj_list[B[i][0]] = vector<pair<int, int>> {};
        }
        adj_list[B[i][0]].push_back(make_pair(B[i][1], B[i][2]));
        if (adj_list.find(B[i][1])==adj_list.end()) {
            adj_list[B[i][1]] = vector<pair<int, int>> {};
        }
        adj_list[B[i][1]].push_back(make_pair(B[i][0], B[i][2]));
    }
    // Create a min heap
    vector<int> weight, nodes;
    // Append all adj nodes of source (C)
    for (int i=0;i<adj_list[C].size();i++) {
        weight.push_back(adj_list[C][i].second);
        nodes.push_back(adj_list[C][i].first);
        tresult[adj_list[C][i].first] = adj_list[C][i].second;
    }
    createMinHeapWithPayload(weight, nodes);
    while(weight.size()) {
        pair<int, int> u = make_pair(weight[0], nodes[0]);
        deleteRootNodeWithPayload(weight, nodes);
        for (int i=0;i<adj_list[u.second].size();i++) {
            int temp = u.first + adj_list[u.second][i].second;
            if (tresult.find(adj_list[u.second][i].first)==tresult.end()) {
                tresult[adj_list[u.second][i].first] = temp;
                addToHeapWithPayload(weight, temp, nodes, adj_list[u.second][i].first);
            } else if (tresult[adj_list[u.second][i].first] > temp) {
                tresult[adj_list[u.second][i].first] = temp;
                addToHeapWithPayload(weight, temp, nodes, adj_list[u.second][i].first);
            }
        }
    }
    for (int i=0;i<A;i++) {
        if (tresult.find(i)==tresult.end()) {
            result.push_back(-1);
            continue;
        }
        result.push_back(tresult[i]);
    }
    return result;
}

int main() {
    int num = 5, source = 4;
    vector<vector<int>> mat;
    mat.push_back(vector<int>{0,3,4});
    mat.push_back(vector<int>{2,3,3});
    mat.push_back(vector<int>{0,1,9});
    mat.push_back(vector<int>{3,4,10});
    mat.push_back(vector<int>{1,3,8});
    vector<int> ans = Dijkstras(num, mat, source);
    for (int i=0;i<ans.size();i++) {
        cout << i << " - " << ans[i] << endl;
    }
    cout << endl << endl;
    num = 6;
    source = 4;
    mat.clear();
    mat.push_back(vector<int>{0,4,9});
    mat.push_back(vector<int>{3,4,6});
    mat.push_back(vector<int>{1,2,1});
    mat.push_back(vector<int>{2,5,1});
    mat.push_back(vector<int>{2,4,5});
    mat.push_back(vector<int>{0,3,7});
    mat.push_back(vector<int>{0,1,1});
    mat.push_back(vector<int>{4,5,7});
    mat.push_back(vector<int>{0,5,1});
    ans = Dijkstras(num, mat, source);
    for (int i=0;i<ans.size();i++) {
        cout << i << " - " << ans[i] << endl;
    }
    return 0;
}
