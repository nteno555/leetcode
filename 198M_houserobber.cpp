class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<pair<int, pair<int, int>>> houses(nums.size(), {0, {0, 0}});
        // First = you robbed the house
        // Second = if you didn't rob it
        houses[0].first = nums[0];
        houses[1].first = nums[1];
        houses[1].second.first = nums[0];

        for (int i=2; i<nums.size(); i++) {
            houses[i].first = max(houses[i-1].second.first, houses[i-1].second.second)+ nums[i];
            houses[i].second.first = houses[i-1].first; 
            houses[i].second.second = houses[i-2].first;
        }

        return max(houses[nums.size()-1].first, max(houses[nums.size()-1].second.first, houses[nums.size()-1].second.second));
    }
};