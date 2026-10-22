class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int otherNum;
        unordered_map<int, int> hash;

        for (int i=0; i<nums.size(); i++) {
            hash[nums[i]] = i;
        }

        for (int i=0; i<nums.size()-1; i++) {
            otherNum = target - nums[i];
            if (hash.find(otherNum) != hash.end() && hash[otherNum] != i) {
                return {i, hash[otherNum]};
            }
        }

        return {0, 0};
    }
};