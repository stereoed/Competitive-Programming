class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Goal: O(1) space -> I'll have to use my result as my monotonic stack. Seems hard since results don't care about actual indices: will scrap the idea in favor of a monotonic stack.
        // Goal: O(nums1.length + nums2.length) time solution -> Its possible because the problem asks for one ;) (won't stop till I beat 95%).

        // Attempt 1
        int n = nums1.size();
        vector<int> o(n, -1);
        /* Idea 1: what I sort nums1 in the order they appear in nums2 (in reverse so I can pop later) and have their original index in output.
        How would this affect numbers for which no greater number is found? Is it actually efficient? Who knows...
        
        iota(o.begin(), o.end(), nums1.size() - 1); // This should create a vector [0,1,2,...,n - 1], right?
        sort(o.begin(), o.end(), [&nums1](const int& a, const int& b){return a > b}); // HMMM, will scrap the idea since it'll probably be too much overhead :p */

        /* Idea 2: since all integers are unique I could try combining both lists or iterating backwards :). Scrapped*/
        /* Idea 3: why not use an unordered map for keeping my nums1's indexes and a monotonis stack for when I actually find those values :p */

        unordered_map<int, int> indices{};
        stack<int> toFind;
        for (int i = n - 1; i > -1; i--){
            // OBSOLETE (IDEA 2): nums2.push_back(nums1[i]); I wonder if I could just nums1 + nums2 to make this faaaaster
            indices[nums1[i]] = i; // Could there be a faster way, kinda like enumerate in python???
        } 

        // Now that I have indices, I can actually work this out.
        for (const int val : nums2){ // I don't really need the indices here, since its just asking me for the next big number
            while(!toFind.empty() && toFind.top() < val){
                // cout << toFind.top() << val << indices[toFind.top()] << "\n";
                o[indices[toFind.top()]] = val;
                toFind.pop();
            }
            if (indices.find(val) != indices.end()){
                toFind.push(val);
            }
        }

        return o;
    }
};