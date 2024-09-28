class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        int n = maximumHeight.size(), Prev = INT_MAX;
        long long sum = 0;
        for(int a : maximumHeight) {
             Prev = a = min(Prev-1 ,a);
               if(a == 0) {return -1;}
             sum += a; 
        }
        return sum; 
    }
};