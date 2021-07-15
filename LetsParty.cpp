/*
* In Danceland, one person can party either alone or can pair up with another person.
* Can you find in how many ways they can party if there are A people in Danceland?
* Note: Return your answer modulo 10003, as the answer can be large.
*/

#include <iostream>
#include <vector>
using namespace std;

int solve(int A) {
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    for (int i=3;i<=A;i++) {
        long long int temp = 1ll*(i-1)*arr[i-2];
        temp += arr[i-1]*1ll;
        arr.push_back(temp%10003);
    }
    return arr[A];
}

int main() {
    cout << solve(19) << endl;
    return 0;
}
