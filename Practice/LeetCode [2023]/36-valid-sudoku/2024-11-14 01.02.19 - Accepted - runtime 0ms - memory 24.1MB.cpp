class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false)), cols(9, vector<bool>(9, false)), sub_box(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char num = board[i][j];
                if (num == '.'){
                    continue;
                }

                int index = num - '1';
                if (rows[i][index] || cols[j][index] || sub_box[(i / 3) * 3 + (j / 3)][index]){
                    return false;
                }

                rows[i][index] = true;
                cols[j][index] = true;
                sub_box[(i / 3) * 3 + (j / 3)][index] = true;
            }
        }

        return true;
    }
};