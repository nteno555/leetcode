class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, mid, right = nums.size()-1;

        while (left < right && right<nums.size()) {
            mid = (right+left)/2;

            cout << nums[mid] << endl;

            if (nums[mid]==target) return mid;
            if (nums[mid]<nums[left]) {
                if (target < nums[mid] || target >= nums[left]) right = mid-1;
                else left = mid+1;
            }
            else if (nums[mid] > nums[right]) {
                if (nums[mid] < target || nums[left] > target) left = mid + 1;
                else right =  mid-1;
            }
            else {
                if (nums[mid] > target) right = mid-1;
                else left = mid+1;
            }
        }

        if (nums[left]==target) return left;
        return -1;
    }
};