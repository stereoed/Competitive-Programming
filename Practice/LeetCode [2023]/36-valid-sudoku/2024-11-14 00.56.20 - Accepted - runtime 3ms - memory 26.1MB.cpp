class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9), cols(9), sub_box(9);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                int num = board[i][j];
                if (num == '.'){
                    continue;
                }

                if (rows[i].count(num) || cols[j].count(num) || sub_box[(i / 3) * 3 + (j / 3)].count(num)){
                    return false;
                }

                rows[i].insert(num);
                cols[j].insert(num);
                sub_box[(i / 3) * 3 + (j / 3)].insert(num);
            }
        }

        return true;
    }
};