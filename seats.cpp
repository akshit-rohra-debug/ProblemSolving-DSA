/*
* There is a row of seats represented by string A. Assume that it contains N
* seats adjacent to each other. There is a group of people who are already seated
* in that row randomly. i.e. some are sitting together & some are scattered.
* An occupied seat is marked with a character 'x' and an unoccupied seat
* is marked with a dot ('.')
* Now your target is to make the whole group sit together i.e. next to each other,
* without having any vacant seat between them in such a way that the total number
* of hops or jumps to move them should be minimum.
* In one jump a person can move to the adjacent seat (if available).
* NOTE: 1. Return your answer modulo 107 + 3.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(string A) {
    long long int hops=0;
    long long int mod = 10000003;
    vector<int> people;
    int size=A.length();
    for(int i=0;i<size;i++) {
        if (A[i]=='x')
            people.push_back(i);
    }
    if (people.size()==0) return 0;
    int median = people.size()/2;
    int center_pos = people[median];
    for (int i=0;i<people.size();i++) {
        int start = people[i];
        int end = center_pos - median + i;
        hops = (hops + 1ll*(abs(end-start)))%mod;
    }
    return hops;
}

int main() {
    cout << solve("....x..xx...x..") << endl;
    cout << solve("..xx.x") << endl;
    return 0;
}
