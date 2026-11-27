class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;

        sort(intervals.begin(), intervals.end());
        int begin = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;

        for (vector<int> i: intervals) {
            if (i[0] > end) {
                ans.push_back({begin, end});
                begin = i[0];
                end = i[1];
            } else {
                end = max(end, i[1]);
            }
        }

        ans.push_back({begin, end});

        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<int> nums(10001, 0);
//         vector<vector<int>> ans;
//         vector<vector<int>> singles;
//
//         for (vector<int> i: intervals) {
//             nums[i[0]]++;
//             nums[i[1]]--;
//
//             if (i[0] == i[1]) singles.push_back(i);
//         }
//
//         for (int i=1; i<nums.size(); i++) {
//             nums[i] += nums[i-1];
//         }
//
//         int i=0, startI;
//         while (i<nums.size()) {
//             if (nums[i] > 0) {
//                 startI = i;
//                 while (i<nums.size() && nums[i] > 0) {
//                     nums[i]++;
//                     i++;
//                 }
//                 nums[i]++;
//                 ans.push_back({startI, i});
//             }
//             i++;
//         }
//
//         for (vector<int> s: singles) {
//             if (nums[s[0]] <= 0) {
//                 nums[s[0]]++;
//                 ans.push_back(s);
//             }
//         }
//
//         return ans;
//     }
// };