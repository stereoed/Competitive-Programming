class Solution {
private:
    vector<vector<int>> rects;
    vector<pair<int, int>> indexRanges; // Stores start and end index ranges for each rectangle
    int totalArea;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalArea = 0;

        for (const auto& rect : rects) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            int area = (x2 - x1 + 1) * (y2 - y1 + 1); // Area of the rectangle
            indexRanges.push_back({totalArea, totalArea + area});
            totalArea += area;
        }
    }
    
    vector<int> pick() {
        // Step 1: Generate a random point index
        int randomPoint = rand() % totalArea;

        // Step 2: Find the rectangle corresponding to the random point index
        int rectIndex = 0;
        for (int i = 0; i < indexRanges.size(); i++) {
            if (randomPoint >= indexRanges[i].first && randomPoint < indexRanges[i].second) {
                rectIndex = i;
                break;
            }
        }

        // Step 3: Compute the offset within the chosen rectangle
        const auto& rect = rects[rectIndex];
        int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
        int width = x2 - x1 + 1;

        int offset = randomPoint - indexRanges[rectIndex].first; // Offset within the rectangle
        int dx = offset % width; // Horizontal offset
        int dy = offset / width; // Vertical offset

        return {x1 + dx, y1 + dy};
    }
};