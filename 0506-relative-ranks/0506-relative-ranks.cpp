class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;

        // Sort from highest to lowest
        sort(sorted.begin(), sorted.end(), greater<int>());

        vector<string> answer;

        for (int i = 0; i < score.size(); i++) {
            // Find position of score[i]
            int pos = find(sorted.begin(), sorted.end(), score[i]) - sorted.begin();

            if (pos == 0)
                answer.push_back("Gold Medal");
            else if (pos == 1)
                answer.push_back("Silver Medal");
            else if (pos == 2)
                answer.push_back("Bronze Medal");
            else
                answer.push_back(to_string(pos + 1));
        }

        return answer;
    }
};