class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v(101, 0);
        int year = 0;
        for (const vector<int>& log : logs){
            v[log[0] - 1950]++;
            v[log[1] - 1950]--;
        }
        for (int i = 1; i < 101; i++){
            v[i] += v[i - 1];
            if (v[i] > v[year]) year = i;
        }

        return year + 1950;
    }
};