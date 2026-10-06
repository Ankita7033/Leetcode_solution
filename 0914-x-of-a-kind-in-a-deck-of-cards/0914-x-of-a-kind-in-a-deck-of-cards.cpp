class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;

        // Count frequency of each card
        for (int card : deck) {
            freq[card]++;
        }

        // Find GCD of all frequencies
        int g = 0;

        for (auto& [card, count] : freq) {
            g = gcd(g, count);
        }

        // X must be at least 2
        return g >= 2;
    }
};