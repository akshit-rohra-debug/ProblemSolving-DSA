/*
* Given a matrix of integers A of size N x M .
* There are 4 types of squares in it:
* 1. 1 represents the starting square.  There is exactly one starting square.
* 2. 2 represents the ending square.  There is exactly one ending square.
* 3. 0 represents empty squares we can walk over.
* 4. -1 represents obstacles that we cannot walk over.
* Find and return the number of 4-directional walks from the starting
* square to the ending square, that walk over every non-obstacle square exactly once.
* Note: Rows are numbered from top to bottom and columns are numbered from left to right.
*/

#include <iostream>
#include <vector>
using namespace std;

int paths;
int sizeI;
int sizeJ;

void travel(vector<vector<int>> &A, int i, int j, int countZero) {
    //cout << "I: " << i << endl;
    //cout << "J: " << j << endl;
    //cout << "A[i][j]: " << A[i][j] << endl;
    int temp;
    //up
    temp = i-1;
    //cout << "Temp: " << temp << endl;
    //cout << "J: " << j << endl;
    if (temp>-1 && temp<sizeI && j>-1 && j<sizeJ) {
        //cout << "A[temp][j]: " << A[temp][j] << endl;
        if (A[temp][j]==0) {
            //cout << "UP" << endl;
            A[temp][j]=-1;
            travel(A,temp,j,countZero-1);
            A[temp][j]=0;
        } else if (A[temp][j]==2 && countZero==0) {
            paths++;
            return;
        }
    }
    //down
    temp = i+1;
    //cout << "Temp: " << temp << endl;
    //cout << "J: " << j << endl;
    if (temp>-1 && temp<sizeI && j>-1 && j<sizeJ) {
        //cout << "A[temp][j]: " << A[temp][j] << endl;
        if (A[temp][j]==0) {
            //cout << "Down" << endl;
            A[temp][j]=-1;
            travel(A,temp,j,countZero-1);
            A[temp][j]=0;
        } else if (A[temp][j]==2 && countZero==0) {
            paths++;
            return;
        }
    }
    //left
    temp = j-1;
    //cout << "I: " << i << endl;
    //cout << "Temp: " << temp << endl;
    if (i>-1 && i<sizeI && temp>-1 && temp<sizeJ) {
        //cout << "A[i][temp]: " << A[i][temp] << endl;
        if (A[i][temp]==0) {
            //cout << "Left" << endl;
            A[i][temp]=-1;
            travel(A,i,temp,countZero-1);
            A[i][temp]=0;
        } else if (A[i][temp]==2 && countZero==0) {
            paths++;
            return;
        }
    }
    //right
    temp = j+1;
    //cout << "I: " << i << endl;
    //cout << "Temp: " << temp << endl;
    if (i>-1 && i<sizeI && temp>-1 && temp<sizeJ) {
        //cout << "A[i][temp]: " << A[i][temp] << endl;
        if (A[i][temp]==0) {
            //cout << "Right" << endl;
            A[i][temp]=-1;
            travel(A,i,temp,countZero-1);
            A[i][temp]=0;
        } else if (A[i][temp]==2 && countZero==0) {
            paths++;
            return;
        }
    }
}

int solve(vector<vector<int>> &A) {
    paths = 0;
    sizeI = A.size();
    if (sizeI>0) {
        sizeJ = A[0].size();
    } else {
        return 0;
    }
    int countZero = 0;
    int startI = -1, startJ = -1;
    for (int i=0;i<A.size();i++) {
        for (int j=0;j<A[i].size();j++) {
            if (A[i][j]==1) {
                startI = i;
                startJ = j;
            } else if (A[i][j]==0) {
                countZero++;
            }
        }
    }
    //cout << "StartI: " << startI << endl;
    //cout << "StartJ: " << startJ << endl;
    //cout << "Zeros: " << countZero << endl;
    travel(A,startI,startJ,countZero);
    return paths;
}

int main() {
    vector<vector<int>> A;
    A.push_back(vector<int>{1,0,0,0});
    A.push_back(vector<int>{0,0,0,0});
    A.push_back(vector<int>{0,0,2,-1});
    cout << solve(A);
    return 0;
}