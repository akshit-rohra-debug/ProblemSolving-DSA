/*
* Min Heap with Payload functions
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

vector<int> deleteRootNodeWithPayload(vector<int>& heap, vector<int>&extra) {
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

int main() {
    vector<int> A{4,3,2,7,6};
    vector<int> payload{4,3,2,7,6};
    createMinHeapWithPayload(A, payload);
    addToHeapWithPayload(A, 1, payload, 1);
    addToHeapWithPayload(A, 11, payload, 11);
    while(A.size()!=0) {
        vector<int> temp = deleteRootNodeWithPayload(A,payload);
        for (int j=0;j<temp.size();j++) {
            cout << temp[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
