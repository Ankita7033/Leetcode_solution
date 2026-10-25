
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;

        for (int i = 0; i < n; i++) {
            int rowMax = 0;
            int colMax = 0;

            for (int j = 0; j < n; j++) {
                // Top projection
                if (grid[i][j] > 0) {
                    area++;
                }

                // Front projection: maximum in each row
                rowMax = max(rowMax, grid[i][j]);

                // Side projection: maximum in each column
                colMax = max(colMax, grid[j][i]);
            }

            area += rowMax + colMax;
        }

        return area;
    }
};
