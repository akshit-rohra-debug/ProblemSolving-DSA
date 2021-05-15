#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int> &A, int B) {
    int start = 0;
    int end = A.size() - 1;
    int mid = -1;
    int pivot;
    int size = A.size();
    while(start!=end) {
        mid = start + (end - start)/2;
        //cout << "Start: " << start << endl;
        //cout << "Mid: " << mid << endl;
        //cout << "End: " << end << endl;
        if (A[mid] > A[mid+1]) {
            pivot = mid+1;
            break;
        }
        if (A[mid] < A[size-1]) {
            //go left
            end = mid;
            continue;
        } else {
            //go right
            start = mid;
            continue;
        }
    }
    if (start==end)
        pivot = start;
    //cout << "Pivot: " << pivot << endl;
    //Start binary search over here
    start = 0;
    end = A.size() - 1;
    while (start<=end) {
        mid = start + (end-start)/2;
        //cout << "Start: " << start << endl;
        //cout << "Mid: " << mid << endl;
        //cout << "End: " << end << endl;
        int om = (mid+pivot)%size;
        //cout << "Om: " << om << endl;
        if (A[om]==B) {
            return om;
        } else if (B < A[om]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return -1;
}

int main() {
    // Write C++ code here
    vector<int> v{194, 195, 196, 197, 198, 199, 201, 203, 204, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39, 40, 42, 43, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 61, 63, 65, 66, 68, 69, 70, 71, 73, 74, 76, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88, 89, 91, 92, 93, 94, 95, 97, 98, 99, 101, 103, 104, 105, 106, 107, 108, 109, 110, 113, 114, 115, 117, 118, 120, 121, 122, 123, 124, 127, 128, 130, 131, 133, 134, 135, 136, 137, 139, 140, 141, 142, 143, 144, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 158, 159, 160, 161, 162, 163, 164, 166, 167, 169, 170, 171, 172, 174, 175, 177, 178, 179, 181, 182, 184, 185, 187, 189, 190, 192, 193};
    //cout << v.size() << endl;
    cout << search(v, 4);
    return 0;
}