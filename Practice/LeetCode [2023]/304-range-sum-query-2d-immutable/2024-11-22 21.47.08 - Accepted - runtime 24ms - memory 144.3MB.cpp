class NumMatrix {
private:
    vector<vector<int>>& matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // In-place prefix sum calculation
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = (i > 0) ? matrix[i - 1][j] : 0;
                int left = (j > 0) ? matrix[i][j - 1] : 0;
                int upLeft = (i > 0 && j > 0) ? matrix[i - 1][j - 1] : 0;

                matrix[i][j] += up + left - upLeft;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = matrix[row2][col2];
        int subtractUp = (row1 > 0) ? matrix[row1 - 1][col2] : 0;
        int subtractLeft = (col1 > 0) ? matrix[row2][col1 - 1] : 0;
        int addOverlap = (row1 > 0 && col1 > 0) ? matrix[row1 - 1][col1 - 1] : 0;

        return total - subtractUp - subtractLeft + addOverlap;
    }
};