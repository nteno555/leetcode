class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        int i=0;
        bool foundOverlap = false;

        while (i<intervals.size()) {
            // new interval starts/ends in another interval
            if ((newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) ||
                (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) || 
                (newInterval[0] <= intervals[i][0] && newInterval[1] >= intervals[i][1])
            ) {
                int begin = min(intervals[i][0], newInterval[0]);
                int end = max(intervals[i][1], newInterval[1]);
                while (i<intervals.size() && intervals[i][0] <= end) i++;

                ans.push_back({begin, max(end, intervals[i-1][1])});
                foundOverlap = true;
            } 
            else {
                ans.push_back(intervals[i]);
                i++;
            }
        }

        if (!foundOverlap) {
            ans.push_back(newInterval);
            sort(ans.begin(), ans.end());
        }

        return ans;
    }
};