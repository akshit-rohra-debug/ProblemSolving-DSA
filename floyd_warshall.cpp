/*
* FloydWarshall
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> FloydWarshall(vector<vector<int>> &A) {
    int n = A.size();
    for (int k=0;k<n;k++) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (i==j || i==k || j==k || A[i][k]==-1 || A[k][j]==-1) continue;
                if (A[i][j]==-1) {
                    A[i][j] = A[i][k]+A[k][j];
                    continue;  
                }
                A[i][j] = min(A[i][j],(A[i][k]+A[k][j]));
            }
        }
    }
    return A;
}

int main() {
    vector<vector<int>> A;
    A.push_back(vector<int>{0,50,39});
    A.push_back(vector<int>{-1,0,-1});
    A.push_back(vector<int>{-1,10,0});
    vector<vector<int>> ans = FloydWarshall(A);
    for (int i=0;i<ans.size();i++) {
        for (int j=0;j<ans.size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
