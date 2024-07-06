class Solution {
public:
    // Function to merge overlapping intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // Sort intervals based on the starting value
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); i++) {
            // If ans is empty or there is no overlap, add the interval to ans
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                // If there is an overlap, merge the intervals by updating the end value
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
