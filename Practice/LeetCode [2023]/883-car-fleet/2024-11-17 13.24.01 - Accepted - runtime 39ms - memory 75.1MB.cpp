class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Brute force n_1
        int o{0}; 
        double m{0};

        // Order indices based on speed;
        vector<int> indices(position.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&position](int a, int b){
            return position[a] > position[b];
        });

        for (const int i : indices){
            double c = static_cast<double>(target - position[i]) / speed[i];
            if (c > m){
                m = c;
                o++;
            }
        }
        return o;
    }
};