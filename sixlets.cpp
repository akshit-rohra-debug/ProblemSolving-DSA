/*
* Given a array of integers A of size N and an integer B.
* Return number of non-empty subsequences of A of size B
* having sum <= 1000.
*/

#include <iostream>
#include <vector>
using namespace std;

int count = 0;

void subsequence(vector<int> &array, int index, vector<int> arr, int breakPoint, int sum)
{
    if (arr.size() == breakPoint) {
        if (arr.size() != 0 && sum <= 1000) {
            ::count++;
        }
        return;
    }
    if (index==array.size() || arr.size()>breakPoint || sum > 1000) {
        return;
    }
    //excluding this element
    subsequence(array, index+1, arr, breakPoint, sum);
    arr.push_back(array[index]);
    sum = sum + array[index];
    subsequence(array, index+1, arr, breakPoint, sum);
    //including this element
    return;
}

int main() {
    vector<int> array{5,17,1000,8};
    vector<int> arr;
    int B = 3;
    subsequence(array, 0, arr, B, 0);
    cout << "Count: " << count << endl;
    return 0;
}