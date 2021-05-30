/*
* Given an unsorted integer array A of size N.
* Find the length of the longest set of consecutive
* elements from the array A.
*/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solve(const vector<int> &A) {
    unordered_map<int,int> umap;
    int max=0;
    for(int i=0;i<A.size();i++) {
        umap[A[i]]=1;
    }
    for(int i=0;i<A.size();i++) {
        //Find if this is the beginning of series
        if(umap.find(A[i]-1)==umap.end()) {
            //Previous number not found
            //This is start of series
            int count=1;
            int temp=A[i]+1;
            while(umap.find(temp)!=umap.end()) {
                //found
                count++;
                temp++;
            }
            if(count>max)
                max=count;
        }
    }
    return max;
}

int main() {
    vector<int> A{100,4,200,1,3,2};
    cout << solve(A) << endl;
    return 0;
}