/*
* Write a program to solve a Sudoku puzzle by filling the empty cells.
* Empty cells are indicated by the character '.' You may assume that
* there will be only one unique solution.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
//[r][value-1]
int horizontal[9][9]={0};
//[c][value-1]
int vertical[9][9]={0};
//[box][value-1]
int box[9][9]={0};

int toInt(char a) {
    return (int)a - (int)'0';
}

char toChar(int a) {
    return (char)(a+(int)'0');
}

void printMatrix(int m[][9]) {
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void print2dVector(vector<vector<char>> v) {
    int r = v.size();
    for (int i=0;i<r;i++) {
        int c = v[i].size();
        for(int j=0;j<c;j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void generateMatrices(vector<vector<char>> sudoku) {
    //build horizontal
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (sudoku[i][j]!='.') {
                horizontal[i][toInt(sudoku[i][j])-1]=1;
                vertical[j][toInt(sudoku[i][j])-1]=1;
                int ti,tj;
                ti = i/3;
                tj = j/3;
                box[ti*3+tj][toInt(sudoku[i][j])-1]=1;
            }
        }
    }
}

bool check(int r, int c, int num) {
    //horizontal
    if (horizontal[r][num-1]==1)
        return false;
    //vertical
    if (vertical[c][num-1]==1)
        return false;
    //box
    int i,j;
    i=r/3;
    j=c/3;
    if (box[i*3+j][num-1]==1)
        return false;
    return true;
}

bool solveSudoku(vector<vector<char>> &A, int r, int c) {
    bool flag = true;
    if (r==8 && c==9) {
        return true;
    } else if (c==9) {
        r++;
        c=0;
    }
    if (A[r][c]=='.') {
        for (int i=1;i<10;i++) {
            if (check(r,c,i)) {
                A[r][c]=toChar(i);
                horizontal[r][i-1]=1;
                vertical[c][i-1]=1;
                int ti=r/3;
                int tj=c/3;
                box[ti*3+tj][i-1]=1;
                flag = solveSudoku(A,r,c+1);
                if (flag) return true;
                A[r][c]='.';
                horizontal[r][i-1]=0;
                vertical[c][i-1]=0;
                box[ti*3+tj][i-1]=0;
            }
        }
    } else {
        flag = solveSudoku(A,r,c+1);
        if (flag) return true;
    }
    return false;
}

void solve(vector<vector<char>> &A) {
    generateMatrices(A);
    solveSudoku(A,0,0);
}

int main() {
    //9 9 53..7.... 6..195... .98....6. 8...6...3 4..8.3..1 7...2...6 .6....28. ...419..5 ....8..79
    vector<vector<char>> sudoku;
    sudoku.push_back(vector<char>{'5','3','.','.','7','.','.','.','.'});
    sudoku.push_back(vector<char>{'6','.','.','1','9','5','.','.','.'});
    sudoku.push_back(vector<char>{'.','9','8','.','.','.','.','6','.'});
    sudoku.push_back(vector<char>{'8','.','.','.','6','.','.','.','3'});
    sudoku.push_back(vector<char>{'4','.','.','8','.','3','.','.','1'});
    sudoku.push_back(vector<char>{'7','.','.','.','2','.','.','.','6'});
    sudoku.push_back(vector<char>{'.','6','.','.','.','.','2','8','.'});
    sudoku.push_back(vector<char>{'.','.','.','4','1','9','.','.','5'});
    sudoku.push_back(vector<char>{'.','.','.','.','8','.','.','7','9'});
    
    int r = sudoku.size();
    for (int i=0;i<r;i++) {
        int c = sudoku[i].size();
        for(int j=0;j<c;j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    solve(sudoku);
    print2dVector(sudoku);
    return 0;
}