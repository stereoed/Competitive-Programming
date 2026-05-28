class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> mono_increase; // What if i save the index of which they start!
        int msf = arr[0]; // max so far
        for (const int i  : arr){
            while (!mono_increase.empty() && mono_increase.top() > i){
                mono_increase.pop();
            }
            msf = max(msf, i);
            mono_increase.push(msf);
        }
        return mono_increase.size();
    }
};