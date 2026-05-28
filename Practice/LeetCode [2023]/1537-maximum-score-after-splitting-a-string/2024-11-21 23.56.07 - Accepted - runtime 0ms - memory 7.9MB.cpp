class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), o = 0, totalOnes = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '1') totalOnes++;
        }

        cout << totalOnes;

        int ceroes = 0;
        for (int i = 0; i < n - 1 ; i++){
            if (s[i] == '0') ceroes++;
            else totalOnes--;
            o = max(o, totalOnes + ceroes);
        }

        return o;
    }
};