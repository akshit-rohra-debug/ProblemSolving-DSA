#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> result;
vector<int> vertical;
vector<int> horizontal;
vector<int> diag1;
vector<int> diag2;

bool isNextMoveValid(int i, int j, int n) {
    if (vertical[j]==1) return false;
    if (horizontal[i]==1) return false;
    int temp;
    temp = i-j+n-1;
    if (diag1[temp]==1) return false;
    temp = i+j;
    if (diag2[temp]==1) return false;
    return true;
}

void nQueen(vector<string> &mat, int row, int n) {
    if (row==n) {
        result.push_back(mat);
        return;
    }
    for (int j=0;j<n;j++) {
        if (mat[row][j]!='.') {
            continue;
        }
        if (isNextMoveValid(row, j, n)) {
            int temp;
            vertical[j]=1;
            horizontal[row]=1;
            temp = row-j+n-1;
            diag1[temp]=1;
            temp = row+j;
            diag2[temp]=1;
            mat[row][j]='Q';
            nQueen(mat, row+1, n);
            mat[row][j]='.';
            vertical[j]=0;
            horizontal[row]=0;
            temp = row-j+n-1;
            diag1[temp]=0;
            temp = row+j;
            diag2[temp]=0;
        }
    }
}

vector<vector<string>> solve(int A) {
    vector<string> mat;
    for (int i=0;i<A;i++) {
        vertical.push_back(0);
        horizontal.push_back(0);
        diag1.push_back(0);
        diag1.push_back(0);
        diag2.push_back(0);
        diag2.push_back(0);
        string temp = "";
        for (int j=0;j<A;j++) {
            temp = temp + ".";
        }
        mat.push_back(temp);
    }
    nQueen(mat, 0, A);
    return result;
}

int main() {
    vector<vector<string>> result;
    result = solve(4);
    for (int i=0;i<result.size();i++) {
        for (int j=0;j<result[i].size();j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}