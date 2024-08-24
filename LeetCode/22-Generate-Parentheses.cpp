class Solution {
public:
    void backtrack(string& str, vector<string>& res, int nLeft, int nRight, int n){
        if (nLeft == n && nRight == n) {
            res.push_back(str);
        } 

        if (nRight > nLeft) {return;}

        if (nLeft > n) {return;}

        str += "(";
        backtrack(str, res, nLeft + 1, nRight, n);
        str.pop_back();
        str += ")";
        backtrack(str, res, nLeft, nRight + 1, n);
        str.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string str = "(";
        vector<string> res;
        backtrack(str, res, 1, 0, n);
        return res;
    }
};
