/*
* The gray code is a binary numeral system where two successive
* values differ in only one bit. Given a non-negative integer A
* representing the total number of bits in the code, print the
* sequence of gray code. A gray code sequence must begin with 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

vector<string> grayCode(int bits) {
    vector<string> ret;
    if (bits==1) {
        ret.push_back("0");
        ret.push_back("1");
    } else {
        vector<string> temp = grayCode(bits-1);
        //append 0 with ret
        int size = temp.size();
        for(int i=0; i<size; i++) {
            ret.push_back("0"+temp[i]);
        }
        //append 1 with ret
        for(int i=size-1; i>=0; i--) {
            ret.push_back("1"+temp[i]);
        }
    }
    return ret;
}

int bStringToInt(string binary) {
    int ret = 0;
    int size = binary.size();
    int power = 0;
    for(int i = size-1;i>-1;i--) {
        int temp = (int)binary[i]-(int)'0';
        ret = ret + temp*pow(2,power);
        power++;
    }
    return ret;
}

vector<int> solve(int A) {
    vector<string> ans = grayCode(A);
    vector<int> ret;
    int size = ans.size();
    for (int i=0;i<size;i++) {
        ret.push_back(bStringToInt(ans[i]));
    }
    return ret;
}

int main() {
    vector<int> arr = solve(3);
    int size = arr.size();
    for (int i=0;i<size;i++) {
        cout << arr[i] << endl;
    }
    return 0;
}