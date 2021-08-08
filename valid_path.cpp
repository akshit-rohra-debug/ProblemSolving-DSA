/*
* There is a rectangle with left bottom as (0, 0) and right up as (x, y).
* There are N circles such that their centers are inside the rectangle.
* Radius of each circle is R. Now we need to find out if it is possible that we
* can move from (0, 0) to (x, y) without touching any circle.
* Note : We can move from any cell to any of its 8 adjecent neighbours and we
* cannot move outside the boundary of the rectangle at any point of time.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

bool IsBound(int i, int j, int x_limit, int y_limit) {
    if (i<0 || j<0) return false;
    if (i>x_limit || j>y_limit) return false;
    return true;
}

bool dfs(vector<vector<int>> &matrix, int i, int j, int x, int y) {
    if (i==x && j==y) return true;
    // Modifiers for all 8 directions
    int rowi_modifier[8] = {-1,-1,-1,0,0,1,1,1};
    int colj_modifier[8] = {-1,0,1,-1,1,-1,0,1};
    int temp_x, temp_y;
    for (int k=0;k<8;k++) {
        temp_x = i+rowi_modifier[k];
        temp_y = j+colj_modifier[k];
        if (IsBound(temp_x, temp_y, x, y) && !matrix[temp_x][temp_y]) {
            // Once this path is explored, no need to explore it again
            matrix[temp_x][temp_y]=1;
            if (dfs(matrix, temp_x, temp_y, x, y)) return true;
        }
    }
    return false;
}

bool InAnyCircle(int i, int j, vector<int> &x, vector<int> &y, int r) {
    for (int k=0;k<x.size();k++) {
        int x_minus_i_sq = pow(x[k]-i,2);
        int y_minus_j_sq = pow(y[k]-j,2);
        long long int sum = x_minus_i_sq + y_minus_j_sq;
        if (sum <= pow(r,2)) {
            return true;
        }
    }
    return false;
}

string ValidPath(int x, int y, int n, int r, vector<int> &a, vector<int> &b) {
    // Adjacency matrix
    vector<vector<int>> matrix;
    // Initialize adj matrix
    for (int i=0;i<=x;i++) {
        matrix.push_back(vector<int>{});
        for (int j=0;j<=y;j++) {
            if (InAnyCircle(i,j,a,b,r)) {
                matrix[i].push_back(1);
            } else {
                matrix[i].push_back(0);
            }
        }
    }
    // Validation for source and destination
    // If it lies in the restricted area (circle) or not
    if (matrix[x][y]==1 || matrix[0][0]==1) return "NO";
    if (dfs(matrix,0,0,x,y)) return "YES";
    return "NO";
}

int main() {
    int x=5,y=3,n=1,r=1;
    vector<int> a{2};
    vector<int> b{3};
    cout << ValidPath(x,y,n,r,a,b) << endl;
    x=1;y=1;n=1;r=1;
    a.clear();b.clear();
    a.push_back(1);
    b.push_back(1);
    cout << ValidPath(x,y,n,r,a,b) << endl;
    x=47;y=44;n=3;r=7;
    a.clear();b.clear();
    a.push_back(21);
    a.push_back(43);
    a.push_back(35);
    b.push_back(21);
    b.push_back(34);
    b.push_back(13);
    cout << ValidPath(x,y,n,r,a,b) << endl;
    return 0;
}
