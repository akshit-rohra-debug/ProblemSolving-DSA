/*
* Given an array of integers A and an integer B. You must
* modify the array exactly B number of times. In single
* modification, we can replace any one array element A[i] by -A[i].
* 
* You need to perform these modifications in such a way that
* after exactly B modifications, sum of the array must be maximum. 
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

int solve(vector<int>& A, int B) {
    int sum = 0;
    createMinHeap(A);
    for(int i=0;i<B;i++) {
        int temp=deleteRootNode(A);
        addToHeap(A, -1*temp);
    }
    for(int i=0;i<A.size();i++) {
        sum += A[i];
    }
    return sum;
}

int main() {
    vector<int> A{57, 3, -14, -87, 42, 38, 31, -7, -28, -61};
    int B=10;
    cout << solve(A,B) << endl;
    return 0;
}