//DAA Write a recursive program to find the solution of placing n
// queens on the chessboard so that no two queens attack each other using Backtracking

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<string> &board){

    //check column
    for(int i = 0; i< row; i++)
        if(board[i][col] == 'Q')
            return false;

    for(int i = row - 1, j = col -1; i >= 0, j>= 0; i--, j--)
        if(board[i][j] == 'Q')
            return false;

    for(int i = row - 1, j = col + 1; i >= 0, j<n; i--, j++)
        if(board[i][j] == 'Q')
            return false;

    return true;
}

void solve(int row, int n, vector<string> &board, vector<vector<string>> &ans){
    if(row == n){
        ans.push_back(board);
        return;
    }

    for(int col = 0; col <n; col++){
        if(isSafe(row, col, n, board)){
        board[row][col] = 'Q';

        solve(row+1, n, board, ans);
        board[row][col] = '.';
        }
    }
}
int main(){
    int n = 4;
    
    vector<string> board(n);
    for(int i = 0; i<n; i++)
        board[i] = string(n, '.');

    vector<vector<string>> ans;

    solve(0, n, board, ans);
    cout<< "All possible solutions:\n";
    for(auto &b : ans){
        for(auto &row : b)
            cout<< row <<endl;
        cout<<endl;
    }
}