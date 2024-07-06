class Solution {
public:
    void mrow(vector<vector<int>>& matrix, int i) {
        int m = matrix[0].size();
        for(int k = 0; k < m; k++) {
            if(matrix[i][k] != 0) { 
                matrix[i][k] = -1;
            }
        }
    }
    
    void mcol(vector<vector<int>>& matrix, int j) {
        int n = matrix.size();
        for(int k = 0; k < n; k++) {
            if(matrix[k][j] != 0) { 
                matrix[k][j] = -1;
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    mrow(matrix, i);
                    mcol(matrix, j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
