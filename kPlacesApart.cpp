/*
* Given N persons with different priorities standing in a queue.
* Queue is following a property that Each person is standing atmost
* B places away from it's sorted position.
* Your task is to sort the queue in the increasing order of priorities.
* NOTE:
* 	No two persons can have the same priority.
* 	Use the property of the queue to sort the queue with complexity O(NlogB).
*/

#include <iostream>
#include <vector>
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

vector<int> solve(vector<int>& A, int B) {
    vector<int> result;
    vector<int> arr;
    for (int i=0;i<=B;i++) {
        arr.push_back(A[i]);
    }
    createMinHeap(arr);
    for (int i=0;i<A.size();i++) {
        int temp = deleteRootNode(arr);
        result.push_back(temp);
        if ((B+i+1)<A.size()) {
            addToHeap(arr, A[B+i+1]);
        }
    }
    return result;
}

int main() {
    vector<int> A{1, 2, 10, 17, 21, 95};
    int B=1;
    vector<int> answer = solve(A, B);
    for (int i=0;i<answer.size();i++) {
        cout << answer[i] << " ";
    }
    return 0;
}
