class Solution {
public:
    bool canAliceWin(int n) {
        int i = 10;
        while (n >= i){
            n -= i;
            i --;

            if (n < 0) return false;

            n -= i;
            i --;

            if (n < 0) return true;
        }

        return false;
    }
};