/*
* Given a matrix of integers A of size N x M consisting of 0 and 1.
* A group of connected 1's forms an island. From a cell (i, j) such that A[i][j] = 1
* you can visit any cell that shares a corner with (i, j) and value in that cell is 1.
* 
* More formally, from any cell (i, j) if A[i][j] = 1 you can visit:
* - (i-1, j) if (i-1, j) is inside the matrix and A[i-1][j] = 1.
* - (i, j-1) if (i, j-1) is inside the matrix and A[i][j-1] = 1.
* - (i+1, j) if (i+1, j) is inside the matrix and A[i+1][j] = 1.
* - (i, j+1) if (i, j+1) is inside the matrix and A[i][j+1] = 1.
* - (i-1, j-1) if (i-1, j-1) is inside the matrix and A[i-1][j-1] = 1.
* - (i+1, j+1) if (i+1, j+1) is inside the matrix and A[i+1][j+1] = 1.
* - (i-1, j+1) if (i-1, j+1) is inside the matrix and A[i-1][j+1] = 1.
* - (i+1, j-1) if (i+1, j-1) is inside the matrix and A[i+1][j-1] = 1.
* 
* Return the number of islands.
* NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.
*/

#include <iostream>
#include <vector>
using namespace std;

bool InBound(int i, int j, int n, int m) {
    if (i<0 || j<0) return false;
    if (i>=n || j>=m) return false;
    return true;
}

void dfs(vector<vector<int>> &adj_mat, vector<vector<int>> &visited, int i, int j) {
    visited[i][j]=1;
    int n=adj_mat.size();
    int m=adj_mat[0].size();
    // Modifiers for all 8 directions
    int rowi_modifier[8] = {-1,-1,-1,0,0,1,1,1};
    int colj_modifier[8] = {-1,0,1,-1,1,-1,0,1};
    int temp_i, temp_j;
    for (int k=0;k<8;k++) {
        temp_i = i + rowi_modifier[k];
        temp_j = j + colj_modifier[k];
        if (InBound(temp_i,temp_j,n,m) && !visited[temp_i][temp_j] && adj_mat[temp_i][temp_j]==1) {
            dfs(adj_mat, visited, temp_i, temp_j);
        }
    }
}

int NumberOfIslands(vector<vector<int>> &A) {
    int number_of_islands = 0;
    vector<vector<int>> visited;
    int n = A.size();
    int m = A[0].size();
    // Initialize visited
    for (int i=0;i<n;i++) {
        visited.push_back(vector<int>{});
        for (int j=0;j<m;j++) {
            visited[i].push_back(0);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!visited[i][j] && A[i][j]==1) {
                number_of_islands++;
                dfs(A,visited,i,j);
            }
        }
    }
    return number_of_islands;
}

int main() {
    vector<vector<int>> A;
    A.push_back(vector<int>{0,1,0});
    A.push_back(vector<int>{0,0,1});
    A.push_back(vector<int>{1,0,0});
    cout << NumberOfIslands(A) << endl;
    A.clear();
    A.push_back(vector<int>{1,1,0,0,0});
    A.push_back(vector<int>{0,1,0,0,0});
    A.push_back(vector<int>{1,0,0,1,1});
    A.push_back(vector<int>{0,0,0,0,0});
    A.push_back(vector<int>{1,0,1,0,1});
    cout << NumberOfIslands(A) << endl;
    return 0;
}
