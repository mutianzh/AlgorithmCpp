class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int r=0; r < n/2; r++){
            for (int c=r; c < n - 1 - r; c++){
                int row = c;
                int col = n-1-r;
                for (int i=0; i<3; i++){
                    int next_row = col;
                    int next_col = n-1-row;
                    swap(matrix[r][c], matrix[row][col]);
                    row = next_row;
                    col = next_col;
                }
            }
        }
    }
};
