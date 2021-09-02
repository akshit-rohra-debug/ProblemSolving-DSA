/*
* There are A islands and there are M bridges connecting them.
* Each bridge has some cost attached to it.
* 
* We need to find bridges with minimal cost such that all islands
* are connected.
* 
* It is guaranteed that input data will contain at least one possible
* scenario in which all islands are connected with each other.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

void perculateUpWithPayload(vector<int>& heap, vector<vector<int>>& extra, int node) {
    int parent = getParent(node);
    int temp = heap[node];
    vector<int> tempe = extra[node];
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

void perculateDownWithPayload(vector<int>& heap, vector<vector<int>>& extra, int node) {
    int size = heap.size();
    int firstChild = getFirstChild(node);
    while (true) {
        if (firstChild >= size) {
            return;
        }
        else if ((firstChild + 1) >= size) {
            if (heap[node] > heap[firstChild]) {
                int temp = heap[node];
                vector<int> tempe = extra[node];
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
                    vector<int> tempe = extra[node];
                    heap[node] = heap[firstChild];
                    extra[node] = extra[firstChild];
                    heap[firstChild] = temp;
                    extra[firstChild] = tempe;
                    node = firstChild;
                }
                else {
                    int temp = heap[node];
                    vector<int> tempe = extra[node];
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

void createMinHeapWithPayload(vector<int>& heap, vector<vector<int>>& extra) {
    int size = heap.size();
    for (int x = (size / 2) - 1; x >= 0; x--) {
        perculateDownWithPayload(heap, extra, x);
    }
}

void addToHeapWithPayload(vector<int>& heap, int value1, vector<vector<int>>& extra, vector<int> value2) {
    heap.push_back(value1);
    extra.push_back(value2);
    perculateUpWithPayload(heap, extra, heap.size() - 1);
}

vector<int> deleteRootNodeWithPayload(vector<int>& heap, vector<vector<int>> &extra) {
    int ret = heap[0];
    vector<int> rete = extra[0];
    int size = heap.size();
    heap[0] = heap[size - 1];
    heap[size - 1] = 0;
    extra[0] = extra[size - 1];
    extra[size - 1].clear();
    heap.pop_back();
    extra.pop_back();
    perculateDownWithPayload(heap, extra, 0);
    return vector<int> {rete[0], rete[1], ret};
}

int CommutableIslands(int A, vector<vector<int>> &B) {
    int min_distance = 0;
    vector<int> heap;
    vector<vector<int>> payload;
    unordered_map<int, bool> target_vertex;
    //Initialize target_vertex
    for (int i=1;i<=A;i++) {
        target_vertex[i]=false;
    }
    unordered_map<int, unordered_map<int, int>> adj_list;
    // Create adj_list
    int min_index = 0;
    for (int i=0;i<B.size();i++) {
        // edge u->v
        if (adj_list.find(B[i][0])==adj_list.end()) {
            unordered_map<int, int> temp;
            adj_list[B[i][0]]=temp;
        }
        // edge v->u
        if (adj_list.find(B[i][1])==adj_list.end()) {
            unordered_map<int, int> temp;
            adj_list[B[i][1]]=temp;
        }
        adj_list[B[i][0]][B[i][1]]=B[i][2];
        adj_list[B[i][1]][B[i][0]]=B[i][2];
        if (B[i][2]<B[min_index][2]) {
            min_index = i;
        }
    }
    for (auto x : adj_list[B[min_index][0]]) {
        //cout << "From: " << B[min_index][0] << ", To: " << x.first << " - " << x.second << endl;
        addToHeapWithPayload(heap, x.second, payload, vector<int> {B[min_index][0], x.first});
    }
    //cout << "Min_distance: " << min_distance << endl << endl;
    target_vertex[B[min_index][0]]=true;
    while(heap.size()) {
        vector<int> temp = deleteRootNodeWithPayload(heap, payload);
        if (!target_vertex[temp[1]]) {
            min_distance += temp[2];
            target_vertex[temp[1]]=true;
            // for all neighbors add edges
            for (auto x : adj_list[temp[1]]) {
                //cout << "From: " << temp[1] << ", To: " << x.first << " - " << x.second << endl;
                addToHeapWithPayload(heap, x.second, payload, vector<int> {temp[1], x.first});
            }
            //cout << "Min_distance: " << min_distance << endl;
            //cout << endl;
        }
    }
    return min_distance;
}

int main() {
    int A=4;
    vector<vector<int>> B;
    B.push_back(vector<int>{1,2,1});
    B.push_back(vector<int>{2,3,4});
    B.push_back(vector<int>{1,4,3});
    B.push_back(vector<int>{4,3,2});
    B.push_back(vector<int>{1,3,10});
    cout << CommutableIslands(A,B) << endl;
    B.clear();
    A=4;
    B.push_back(vector<int>{1,2,1});
    B.push_back(vector<int>{2,3,2});
    B.push_back(vector<int>{3,4,4});
    B.push_back(vector<int>{1,4,3});
    cout << CommutableIslands(A,B) << endl;
}
