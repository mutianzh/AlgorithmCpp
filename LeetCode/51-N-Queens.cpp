class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> col;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        backtrack(0, n, col, posDiag, negDiag, board, res);
        return res;
    }
private:
    void backtrack(int r, int n, unordered_set<int>& col, unordered_set<int>& posDiag, unordered_set<int>& negDiag, vector<string>& board, vector<vector<string>>& res){
        if (r == n) {
            res.push_back(board);
            return;
            }
        for (int c=0; c < n; c++){
            if (!col.count(c) && !posDiag.count(c - r) && !negDiag.count(c + r)){
                col.insert(c);
                posDiag.insert(c - r);
                negDiag.insert(c + r);
                board[r][c] = 'Q';
                backtrack(r+1, n, col, posDiag, negDiag, board, res);
                col.erase(c);
                posDiag.erase(c - r);
                negDiag.erase(c + r);
                board[r][c] = '.';
            }
        }
    }
};
