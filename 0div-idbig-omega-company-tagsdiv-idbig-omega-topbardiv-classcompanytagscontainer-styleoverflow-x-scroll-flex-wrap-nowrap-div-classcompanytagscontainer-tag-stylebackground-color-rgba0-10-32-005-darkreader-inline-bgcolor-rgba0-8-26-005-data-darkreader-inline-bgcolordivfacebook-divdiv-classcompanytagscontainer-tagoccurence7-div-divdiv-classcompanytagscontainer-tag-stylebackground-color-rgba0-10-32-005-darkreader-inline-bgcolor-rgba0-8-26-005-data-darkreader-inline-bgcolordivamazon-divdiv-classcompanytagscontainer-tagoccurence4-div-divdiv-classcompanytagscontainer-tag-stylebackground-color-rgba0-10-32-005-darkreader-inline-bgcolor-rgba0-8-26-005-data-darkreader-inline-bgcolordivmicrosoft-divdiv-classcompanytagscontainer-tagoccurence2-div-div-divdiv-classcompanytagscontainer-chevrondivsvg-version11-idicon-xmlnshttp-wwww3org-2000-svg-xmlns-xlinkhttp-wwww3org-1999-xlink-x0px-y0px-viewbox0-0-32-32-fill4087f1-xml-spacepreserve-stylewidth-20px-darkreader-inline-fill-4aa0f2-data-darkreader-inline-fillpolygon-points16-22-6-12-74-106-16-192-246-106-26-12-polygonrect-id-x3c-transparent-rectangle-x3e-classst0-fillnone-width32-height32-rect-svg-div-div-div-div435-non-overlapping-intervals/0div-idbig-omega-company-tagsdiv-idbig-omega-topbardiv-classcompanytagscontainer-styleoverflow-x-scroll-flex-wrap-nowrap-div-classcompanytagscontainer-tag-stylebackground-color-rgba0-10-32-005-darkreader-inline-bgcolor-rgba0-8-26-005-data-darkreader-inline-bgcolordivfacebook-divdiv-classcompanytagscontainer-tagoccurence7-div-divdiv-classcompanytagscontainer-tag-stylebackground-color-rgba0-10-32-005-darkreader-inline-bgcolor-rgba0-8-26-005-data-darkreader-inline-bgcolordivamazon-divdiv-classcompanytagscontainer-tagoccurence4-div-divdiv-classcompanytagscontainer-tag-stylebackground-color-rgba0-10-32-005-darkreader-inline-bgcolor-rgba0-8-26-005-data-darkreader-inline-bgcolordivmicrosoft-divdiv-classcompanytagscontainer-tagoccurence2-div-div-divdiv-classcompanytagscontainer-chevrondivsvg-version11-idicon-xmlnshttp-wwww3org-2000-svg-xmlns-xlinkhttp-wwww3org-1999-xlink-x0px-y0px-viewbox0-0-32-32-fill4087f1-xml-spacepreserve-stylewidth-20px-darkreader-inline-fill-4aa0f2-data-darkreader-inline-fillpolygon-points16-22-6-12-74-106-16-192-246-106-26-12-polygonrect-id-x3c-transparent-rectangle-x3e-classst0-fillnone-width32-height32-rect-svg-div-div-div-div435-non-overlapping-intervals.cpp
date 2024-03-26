class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int ans = 0 , previous = 0 ;
        for(int current = 1 ; current < n ; current++){
            
             if(intervals[previous][1] > intervals[current][0]) {
                  ans++;
                 if(intervals[previous][1] >= intervals[current][1]) {
                        previous = current;
                 }
             }
            else {
                previous = current;
            }
        }
       return ans; 
    }
};