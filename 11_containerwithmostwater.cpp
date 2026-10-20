class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, i=0, j = height.size()-1;

        while (i<j) {
            if (height[i] < height[j]) {
                maxArea = max(maxArea, (j-i) * height[i]);
                i++;
            }
            else {
                maxArea = max(maxArea, (j-i) * height[j]);
                j--;
            }
        }

        return maxArea;
    }
};