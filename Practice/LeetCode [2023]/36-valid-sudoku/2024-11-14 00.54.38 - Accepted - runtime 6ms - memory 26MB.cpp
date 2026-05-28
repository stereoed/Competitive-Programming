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

                if (rows[i].count(num)){
                    return false;
                }

                if (cols[j].count(num)){
                    return false;
                }

                int sub_box_index = (i / 3) * 3 + (j / 3);
                if (sub_box[sub_box_index].count(num)){
                    return false;
                }

                rows[i].insert(num);
                cols[j].insert(num);
                sub_box[sub_box_index].insert(num);

            }
        }

        return true;
    }
};