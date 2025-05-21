class Solution {
private:
    void makeRowZero(vector<vector<int>>& matrix, int row, int col) {
        for (int j = 0; j < col; j++)
            matrix[row][j] = 0;    
    }  
    void makeColZero(vector<vector<int>>& matrix, int row, int col) {
        for (int i = 0; i < row; i++)
            matrix[i][col] = 0;    
    }    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;      
                }
            }
        }
        for (int j = 1; j < c; j++) {
            if (matrix[0][j] == 0) 
                makeColZero(matrix, r, j);
        }
        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0) 
                makeRowZero(matrix, i, c);
        }
        if (col0 == 0)
            makeColZero(matrix, r, 0);
    }
};