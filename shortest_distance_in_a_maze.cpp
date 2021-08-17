/*
Given a matrix of integers A of size N x M describing a maze.
The maze consists of empty locations and walls.
1 represents a wall in a matrix and 0 represents an empty location in a wall.
There is a ball trapped in a maze. The ball can go through empty spaces by rolling
up, down, left or right, but it won't stop rolling until hitting a wall
(maze boundary is also considered as a wall). When the ball stops, it could choose the next direction.

Given two array of integers of size B and C of size 2 denoting the
starting and destination position of the ball.
Find the shortest distance for the ball to stop at the destination.
The distance is defined by the number of empty spaces traveled by the ball
from the starting position (excluded) to the destination (included).
If the ball cannot stop at the destination, return -1.	
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

enum class Direction {
    kUp=0,
    kDown=1,
    kLeft=2,
    kRight=3,
    kNoDirection=4
};

bool IsWall (int node, vector<vector<int>> &A, int m) {
    int i=node/m;
    int j=node%m;
    if (A[i][j]==1) return true;
    return false;
}

bool MatchNode(int source, vector<int> dest, int m) {
    int temp = m*dest[0]+dest[1];
    if (temp==source) return true;
    return false;
}

bool InBound(int i, int j, int i_max, int j_max) {
    if (i<0 || j<0) return false;
    if (i>=i_max || j>=j_max) return false;
    return true;
}

int GetNode(int old, Direction d, int n, int m) {
    int i=old/m;
    int j=old%m;
    switch(d) {
        case Direction::kUp:
            i--;
            if (InBound(i,j,n,m)) return (m*i)+(j);
            return -1;
        case Direction::kDown:
            i++;
            if (InBound(i,j,n,m)) return (m*i)+(j);
            return -1;
        case Direction::kLeft:
            j--;
            if (InBound(i,j,n,m)) return (m*i)+(j);
            return -1;
        case Direction::kRight:
            j++;
            if (InBound(i,j,n,m)) return (m*i)+(j);
            return -1;
    }
    return -1;
}

Direction GetDirection(vector<int> &direction) {
    if (direction[(int)Direction::kUp]==0) {
        return Direction::kUp;
    }
    if (direction[(int)Direction::kDown]==0) {
        return Direction::kDown;
    }
    if (direction[(int)Direction::kLeft]==0) {
        return Direction::kLeft;
    }
    if (direction[(int)Direction::kRight]==0) {
        return Direction::kRight;
    }
    return Direction::kNoDirection;
}

int GetShortestDistanceInMaze(vector<vector<int>> &A, vector<int> &B, vector<int> &C) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> visited;
    int node;
    // Initialize visited
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            node = (n*i)+j;
            if (A[i][j]) {
                // Wall
                visited.push_back(vector<int>{-1,-1,-1,-1});
            } else {
                // Empty
                visited.push_back(vector<int>{0,0,0,0});
            }
        }
    }
    //Direction modifier
    int i_modifier[4] = {-1,0,0,1};
    int j_modifier[4] = {0,-1,1,0};
    queue<vector<int>> q;
    node = m*B[0] + B[1];
    for (int i=0;i<4;i++) {
        int temp_node = GetNode(node, (Direction)i, n, m);
        if (temp_node>=0 && visited[temp_node][i]==0) {
            q.push(vector<int>{temp_node, i});
            visited[temp_node][i]=1;
        }
    }
    int size = q.size();
    int next_node;
    while(!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        //cout << "Current node: " << temp[0] << ", Direction: " << temp[1] << endl;
        // Get next node, if wall & current is final dest, return dist
        // If current not final dest, get new direction and next node
        // Go to next node if direction not visited and not a wall
        next_node = GetNode(temp[0], (Direction)temp[1], n, m);
        if (next_node!=-1 && IsWall(next_node, A, m)) {
            if (MatchNode(temp[0], C, m)) {
                return visited[temp[0]][temp[1]];
            }
            Direction d = GetDirection(visited[node]);
            if (d==Direction::kNoDirection) continue;
            for (int i=0;i<4;i++) {
                if (visited[temp[0]][i]==0) {
                    next_node = GetNode(temp[0], (Direction)i, n, m);
                    if (next_node!=-1 && !IsWall(next_node, A, m) && visited[next_node][i]==0) {
                        visited[next_node][i] = 1 + visited[temp[0]][temp[1]];
                        q.push(vector<int> {next_node, i});
                    }
                }
            }
            continue;
        }
        if (next_node!=-1 && !IsWall(next_node, A, m) && visited[next_node][temp[1]]==0) {
            visited[next_node][temp[1]] = 1 + visited[temp[0]][temp[1]];
            q.push(vector<int> {next_node, temp[1]});
        }
        if (next_node==-1) {
            if (MatchNode(temp[0], C, m)) {
                return visited[temp[0]][temp[1]];
            }
            Direction d = GetDirection(visited[node]);
            if (d==Direction::kNoDirection) continue;
            for (int i=0;i<4;i++) {
                if (visited[temp[0]][i]==0) {
                    next_node = GetNode(temp[0], (Direction)i, n, m);
                    if (next_node!=-1 && !IsWall(next_node, A, m) && visited[next_node][i]==0) {
                        visited[next_node][i] = 1 + visited[temp[0]][temp[1]];
                        q.push(vector<int> {next_node, i});
                    }
                }
            }
            continue;
        }        
    }
    return -1;
}

int main() {
    vector<vector<int>> A;
    vector<int> B{1,1};
    vector<int> C{2,1};
    A.push_back(vector<int>{1,1,0,1});
    A.push_back(vector<int>{0,0,0,1});
    A.push_back(vector<int>{1,0,0,1});
    A.push_back(vector<int>{0,0,1,0});
    cout << GetShortestDistanceInMaze(A,B,C) << endl;
    A.clear();
    B.clear();
    C.clear();
    B.push_back(5);
    B.push_back(1);
    C.push_back(9);
    C.push_back(0);
    A.push_back(vector<int>{0,0,0});
    A.push_back(vector<int>{0,0,0});
    A.push_back(vector<int>{1,1,1});
    A.push_back(vector<int>{0,0,1});
    A.push_back(vector<int>{1,1,1});
    A.push_back(vector<int>{1,0,0});
    A.push_back(vector<int>{1,1,0});
    A.push_back(vector<int>{0,0,1});
    A.push_back(vector<int>{0,1,0});
    A.push_back(vector<int>{0,1,0});
    cout << GetShortestDistanceInMaze(A,B,C) << endl;
    A.clear();
    B.clear();
    C.clear();
    B.push_back(3);
    B.push_back(2);
    C.push_back(2);
    C.push_back(0);
    A.push_back(vector<int>{0,0,1});
    A.push_back(vector<int>{1,0,1});
    A.push_back(vector<int>{0,0,0});
    A.push_back(vector<int>{1,0,0});
    A.push_back(vector<int>{0,0,1});
    A.push_back(vector<int>{1,1,1});
    A.push_back(vector<int>{0,0,1});
    A.push_back(vector<int>{1,0,1});
    A.push_back(vector<int>{0,0,0});
    cout << GetShortestDistanceInMaze(A,B,C) << endl;
    return 0;
}
