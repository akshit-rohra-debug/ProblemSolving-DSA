/*
* Given a matrix of integers A of size N x M consisting of 0, 1 or 2.
* Each cell can have three values:
* The value 0 representing an empty cell.
* The value 1 representing a fresh orange.
* The value 2 representing a rotten orange.
* Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom)
* to a rotten orange becomes rotten. Return the minimum number of minutes that must
* elapse until no cell has a fresh orange. If this is impossible, return -1 instead.
* Note: Your solution will run on multiple test cases. If you are using global variables,
* make sure to clear them. 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool InBound(int i, int j, int n, int m) {
    if (i<0 || j<0) return false;
    if (i>=n || j>=m) return false;
    return true;
}

int GetMinutesToRot(vector<vector<int>> &A) {
    int minutes = 0;
    vector<vector<bool>> visited;
    int n = A.size();
    int m = A[0].size();
    queue<vector<int>> q;
    // Initialize visited and scan for initial rotten oranges
    for (int i=0;i<n;i++) {
        visited.push_back(vector<bool>{});
        for (int j=0;j<m;j++) {
            visited[i].push_back(false);
            if (A[i][j]==2) {
                q.push(vector<int>{i,j});
            }
        }
    }
    // Modifiers for all 4 directions
    int rowi_modifier[4] = {-1,0,0,1};
    int colj_modifier[4] = {0,-1,1,0};
    // BFS
    int size = q.size();
    int i, j;
    while(!q.empty()) {
        // Run for size of queue and increase minutes after that
        for (int x=0;x<size;x++) {
            i = q.front()[0];
            j = q.front()[1];
            q.pop();
            visited[i][j]=true;
            int temp_i, temp_j;
            for (int k=0;k<4;k++) {
                temp_i = i + rowi_modifier[k];
                temp_j = j + colj_modifier[k];
                if (InBound(temp_i, temp_j, n, m) && !visited[temp_i][temp_j] && A[temp_i][temp_j]==1) {
                    q.push(vector<int>{temp_i, temp_j});
                    A[temp_i][temp_j]=2;
                }
            }
        }
        minutes++;
        size = q.size();
    }
    minutes--;
    // Check if even 1 fresh orange is remaing
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            if (A[i][j]==1) return -1;
        }
    }
    return minutes;
}

int main() {
    vector<vector<int>> A;
    A.push_back(vector<int>{2,1,1});
    A.push_back(vector<int>{1,1,0});
    A.push_back(vector<int>{0,1,1});
    cout << GetMinutesToRot(A) << endl;
    A.clear();
    A.push_back(vector<int>{2,1,1});
    A.push_back(vector<int>{0,1,1});
    A.push_back(vector<int>{1,0,1});
    cout << GetMinutesToRot(A) << endl;
    return 0;
}
