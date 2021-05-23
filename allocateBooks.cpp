/*
* Given an array of integers A of size N and an integer B.
* College library has N books,the ith book has A[i] number of pages.
* You have to allocate books to B number of students so that maximum
* number of pages alloted to a student is minimum.

* A book will be allocated to exactly one student.
* Each student has to be allocated at least one book.
* Allotment should be in contiguous order, for example: A student
* cannot be allocated book 1 and book 3, skipping book 2.
* Calculate and return that minimum possible number.
* NOTE: Return -1 if a valid assignment is not possible.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool allocationPossible(vector<int> &A, int mid, int n) {
    int sum = 0;
    vector<int>::iterator it = A.begin();
    if ((*max_element(A.begin(), A.end()))>mid) return false;
    while(it!=A.end()) {
        if((sum+(*it))>mid) {
            //cout << "Element: " << (*it) << endl;
            //cout << "Sum: " << sum+(*it) << endl;
            //cout << "Allocation with sum = *it" << endl;
            n--;
            sum = *it;
        } else if ((sum+(*it))==mid) {
            //cout << "Element: " << (*it) << endl;
            //cout << "Sum: " << sum+(*it) << endl;
            //cout << "Allocation with sum = 0" << endl;
            n--;
            sum=0;
        } else {
            sum = sum + *it;
        }
        it++;
    }
    return (n==0) ? (sum==0) : (n>0);
}

int books(vector<int> &A, int B) {
    if (B>A.size()) return -1;
    int min = 0;
    vector<int>::iterator it = A.begin();
    int max = 0;
    while(it!=A.end()) {
        max += *it;
        it++;
    }
    int mid = 0;
    while(min<max) {
        mid = min + (max-min)/2;
        //cout << "Min: " << min << endl;
        //cout << "Max: " << max << endl;
        //cout << "Mid: " << mid << endl;
        if (allocationPossible(A, mid, B)) {
            //cout << "True" << endl;
            max = mid;
        } else {
            //cout << "False" << endl;
            min = mid + 1;
        }
    }
    //cout << "Answer: " << min << endl;
    return min;
}

int main() {
    vector<int> A = {97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24};
    int B = 26;
    cout << books(A,B) << endl;
    return 0;
}