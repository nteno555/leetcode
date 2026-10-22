class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> forwards(len), backwards(len), ans(len);

        forwards[0] = nums[0];
        backwards[len-1] = nums[len-1];

        for (int i=1; i<len; i++) {
            forwards[i] = nums[i] * forwards[i-1];
            backwards[len-i-1] = nums[len-i-1] * backwards[len-i];
        }

        for (int i=1; i<len-1; i++) {
            ans[i] = forwards[i-1] * backwards[i+1];
        }
        ans[0] = backwards[1];
        ans[len-1] = forwards[len-2];

        return ans;
    }
};