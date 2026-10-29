class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, mid, right=nums.size()-1;
        while (left<right) {
            mid = (left+right)/2;

            if (nums[mid]==target) return mid;
            else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        if (nums[left]==target) return left;

        return -1;
    }
};