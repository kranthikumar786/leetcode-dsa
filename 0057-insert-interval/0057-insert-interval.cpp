class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // 1. Add all intervals that end before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }

        // 2. Merge all overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // 3. Add all the remaining intervals
        while (i < n) {
            result.push_back(intervals[i++]);
        }

        return result;
    }
};




/*
intervals =
[[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval =
[4,8]
Output
[[1,2],[3,8],[6,7],[8,10],[12,16]]
Expected
[[1,2],[3,10],[12,16]]
*/