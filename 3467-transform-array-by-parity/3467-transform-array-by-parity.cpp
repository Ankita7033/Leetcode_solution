class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int>v(nums.size());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] % 2 == 0)
                v[i] = 0;
            else
                v[i] = 1;
        }
        sort(v.begin(),v.end());
        return v;
    }
};