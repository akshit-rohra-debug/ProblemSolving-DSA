/*
* Given two array of integers A and B describing a pair of (A[i], B[i])
* coordinates in 2D plane. A[i] describe x coordinates of the ith point
* in 2D plane whereas B[i] describes the y-coordinate of the ith point
* in 2D plane.
* 
* Find and return the maximum number of points which lie on the same line.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

int gcd(int a, int b) {
    if (a==0) return b;
    return gcd(b%a, a);
}

pair<int, int> slope(pair<int, int> a, pair<int, int> b) {
    int dx = b.first - a.first;
    int dy = b.second - a.second;
    int g = gcd(dx,dy);
    return make_pair(dx/g, dy/g);
}

int solve(vector<int> &A, vector<int> &B) {
    int imax = 0;
    int size = A.size();
    unordered_map<int, unordered_map<int, int>> hmap;
    for (int i=0;i<size;i++) {
        pair<int, int> ip(A[i], B[i]);
        int same = 0;
        int jmax = 0;
        for (int j=0;j<size;j++) {
            if (i==j) continue;
            pair<int, int> jp(A[j], B[j]);
            pair<int, int> s;
            //cout << "IP: " << ip.first << " " << ip.second << " JP: " << jp.first << " " << jp.second << endl;
            if ((ip.first == jp.first) && (ip.second==jp.second)) {
                same++;
                //cout << "Same" << endl;
            } else {
                s = slope(ip, jp);
                //cout << "Slope: " << s.first << ", " << s.second << endl;
                // Add slope to the map
                if (hmap.find(s.first)==hmap.end()) {
                    // x not found
                    unordered_map<int, int> temp;
                    temp[s.second] = 1;
                    hmap[s.first] = temp;
                } else {
                    if (hmap[s.first].find(s.second)==hmap[s.first].end()) {
                        // y not found
                        hmap[s.first][s.second] = 1;
                    } else {
                        // x and y both found
                        hmap[s.first][s.second]++;
                    }
                }
            }
            jmax = max(jmax, hmap[s.first][s.second] + same + 1);
            //cout << "Jmax: " << jmax << " map: " << hmap[s.first][s.second] << " same: " << same << endl;
        }
        hmap.clear();
        imax = max(imax, jmax);
    }
    return imax;
}

int main() {
    vector<int> A{6, -5, 3, -6, 3, -9, -8, -7};
    vector<int> B{5, 0, -8, 1, -1, 6, 3, -3};
    cout << solve(A,B) << endl;
    return 0;
}
