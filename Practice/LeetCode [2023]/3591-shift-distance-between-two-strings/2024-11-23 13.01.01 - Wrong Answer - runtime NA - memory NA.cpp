class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long o = 0, n = nextCost.size();
        vector<long long> nextSum(n + 1, 0), prevSum(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            nextSum[i] = nextSum[i - 1] + static_cast<long long>(nextCost[i - 1]);
            prevSum[i] = prevSum[i - 1] + static_cast<long long>(previousCost[i - i]);
        }

        // Print next and prev sum.

        for (int i = 0; i < s.size(); i++) {
            int startIdx = s[i] - 'a';
            int endIdx = t[i] - 'a';

            if (startIdx == endIdx) {
                continue;
            }

            long long costForward = 0;
            long long costBackward = 0;

            if (startIdx < endIdx) {
                costForward = nextSum[endIdx + 1] - nextSum[startIdx + 1];
            } else {
                costForward = (nextSum[n] - nextSum[startIdx + 1]) + nextSum[endIdx + 1];
            }

            
            if (startIdx > endIdx) {
                costBackward = prevSum[startIdx + 1] - prevSum[endIdx + 1];
            } else {
                costBackward = prevSum[startIdx + 1] + (prevSum[n] - prevSum[endIdx + 1]);
            }

            o += min(costForward, costBackward);
        }

        return o;
    }
};