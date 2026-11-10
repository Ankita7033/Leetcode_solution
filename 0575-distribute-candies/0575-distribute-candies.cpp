class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // Sort the array to bring duplicate types next to each other
        sort(candyType.begin(), candyType.end());
        
        int unique_count = 1; // There is at least 1 type if the array is not empty
        
        // Count unique types by comparing adjacent elements
        for (size_t i = 1; i < candyType.size(); ++i) {
            if (candyType[i] != candyType[i - 1]) {
                unique_count++;
            }
        }
        
        // The limit is half of the total candies
        int max_allowed = candyType.size() / 2;
        
        return min(unique_count, max_allowed);
    }
};
