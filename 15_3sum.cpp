class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int j, k, desiredTwoSum, curSum;

        for (int i=0; i<nums.size()-2; i++) {
            j = i+1;
            k = nums.size()-1;

            if (i>0 && nums[i]==nums[i-1]) continue;

            desiredTwoSum = -nums[i];

            while (j < k){
                if (j>i+1 && nums[j]==nums[j-1]) {
                    j++;
                    continue;
                }

                curSum = nums[j] + nums[k];
                if (curSum == desiredTwoSum) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    continue;
                }
                if (curSum < desiredTwoSum) j++;
                else k--;
            }
        }

        return ans;
    }
};