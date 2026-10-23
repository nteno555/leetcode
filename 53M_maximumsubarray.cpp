class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==1) return nums[0];

        int runningMin=nums[0], maxSum=nums[0];
        for (int i=1; i<nums.size(); i++) {
            nums[i] += nums[i-1];
            maxSum = max(max(nums[i] - runningMin, nums[i]), maxSum);
            runningMin = min(runningMin, nums[i]);
        }

        return max(maxSum, nums[nums.size()-1]);
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         return maxSub(nums, nums[0], 1);
//     }
//
//     int maxSub(vector<int>& nums, int maxSum, int curIdx) {
//         if (nums.size() == 1) return nums[0];
//
//         curElement = nums[curIdx];
//         maxSum = max(maxSum + curElement, curElement);
//         int next = maxSub(nums, maxSum, curIdx+1);
//
//         return max(maxSum, max(curElement, curElement+next));
//     }
// };