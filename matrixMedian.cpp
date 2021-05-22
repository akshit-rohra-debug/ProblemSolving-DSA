#include <iostream>
#include <vector>
using namespace std;

int findMedian(vector<vector<int> > &A) {
    int min,max,mid;
    int r = A.size();
    int c = (*A.begin()).size();
    vector<vector<int>>::iterator i;
    vector<int>::iterator j;
    //find min
    i=A.begin();
    min = *(*i).begin();
    i++;
    for(;i!=A.end();i++) {
        j =  (*i).begin();
        if (*j < min)
            min = *j;
    }
    
    //find max
    i=A.begin();
    j=(*i).end();
    j--;
    max = *j;
    for(;i!=A.end();i++) {
        j =  (*i).end();
        j--;
        if (*j > max)
            max = *j;
    }
    
    //find median
    int count;
    int want = (r*c+1)/2;
    while(min<max) {
        count = 0;
        mid = min + (max-min)/2;
        for (i=A.begin();i!=A.end();i++) {
            j = (*i).begin();
            while (*j <= mid && j!=(*i).end()) {
                count++;
                j++;
            }
        }
        //cout << "Min: " << min << endl;
        //cout << "Max: " << max << endl;
        //cout << "Mid: " << mid << endl;
        //cout << "Count: " << count << endl;
        //cout << "Want: " << want << endl;
        if (count<want)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main() {
    vector<vector<int>> A;
    A.push_back(vector<int>{1,3,5});
    A.push_back(vector<int>{2,6,9});
    A.push_back(vector<int>{3,6,9});
    cout << findMedian(A) << endl;
    return 0;
}