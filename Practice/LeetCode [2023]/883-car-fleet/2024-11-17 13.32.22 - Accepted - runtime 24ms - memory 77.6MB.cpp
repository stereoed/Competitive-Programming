class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Brute force n_1
        int o{0}; 
        double m{0};

        int n = position.size();
        if (n == 0) return 0;

        // Pair positions and speeds
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), [&](pair<int, int> a, pair<int, int> b){return a.first > b.first;});

        for (const auto& car : cars){
            double c = static_cast<double>(target - car.first) / car.second;
            if (c > m){
                m = c;
                o++;
            }
        }
        return o;
    }
};