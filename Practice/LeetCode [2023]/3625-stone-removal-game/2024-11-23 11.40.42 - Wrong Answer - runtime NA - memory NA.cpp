class Solution {
public:
    bool canAliceWin(int n) {
        bool flag = false;
        for (int i = 10; i < n; i--){
            n -= i;
            flag = !flag;
        } 
        return flag;
    }
};