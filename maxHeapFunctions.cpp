/*
* Max Heap functions
*/

#include <iostream>
#include <vector>
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

void perculateUp(vector<int>& heap, int node) {
    int parent = getParent(node);
    int temp = heap[node];
    while (temp > heap[parent] && parent != -1) {
        temp = heap[node];
        heap[node] = heap[parent];
        heap[parent] = temp;
        node = parent;
        parent = getParent(node);
    }
}

void perculateDown(vector<int>& heap, int node) {
    int size = heap.size();
    int firstChild = getFirstChild(node);
    while (true) {
        if (firstChild >= size) {
            return;
        }
        else if ((firstChild + 1) >= size) {
            if (heap[node] < heap[firstChild]) {
                int temp = heap[node];
                heap[node] = heap[firstChild];
                heap[firstChild] = temp;
                node = firstChild;
            }
            else {
                return;
            }
        }
        else {
            if (heap[node] < heap[firstChild] || heap[node] < heap[firstChild + 1]) {
                if (heap[firstChild] > heap[firstChild + 1]) {
                    int temp = heap[node];
                    heap[node] = heap[firstChild];
                    heap[firstChild] = temp;
                    node = firstChild;
                }
                else {
                    int temp = heap[node];
                    heap[node] = heap[firstChild + 1];
                    heap[firstChild + 1] = temp;
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

void createMaxHeap(vector<int>& heap) {
    int size = heap.size();
    for (int x = (size / 2) - 1; x >= 0; x--) {
        perculateDown(heap, x);
    }
}

void addToHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    perculateUp(heap, heap.size() - 1);
}

int deleteRootNode(vector<int>& heap) {
    int ret = heap[0];
    int size = heap.size();
    heap[0] = heap[size - 1];
    heap[size - 1] = 0;
    heap.pop_back();
    perculateDown(heap, 0);
    return ret;
}

int main() {
    vector<int> A{4,3,2,7,6};
    createMaxHeap(A);
    addToHeap(A, 1);
    addToHeap(A, 11);
    while(A.size()!=0) {
        cout << deleteRootNode(A) << " ";
    }
    cout << endl;
    return 0;
}
