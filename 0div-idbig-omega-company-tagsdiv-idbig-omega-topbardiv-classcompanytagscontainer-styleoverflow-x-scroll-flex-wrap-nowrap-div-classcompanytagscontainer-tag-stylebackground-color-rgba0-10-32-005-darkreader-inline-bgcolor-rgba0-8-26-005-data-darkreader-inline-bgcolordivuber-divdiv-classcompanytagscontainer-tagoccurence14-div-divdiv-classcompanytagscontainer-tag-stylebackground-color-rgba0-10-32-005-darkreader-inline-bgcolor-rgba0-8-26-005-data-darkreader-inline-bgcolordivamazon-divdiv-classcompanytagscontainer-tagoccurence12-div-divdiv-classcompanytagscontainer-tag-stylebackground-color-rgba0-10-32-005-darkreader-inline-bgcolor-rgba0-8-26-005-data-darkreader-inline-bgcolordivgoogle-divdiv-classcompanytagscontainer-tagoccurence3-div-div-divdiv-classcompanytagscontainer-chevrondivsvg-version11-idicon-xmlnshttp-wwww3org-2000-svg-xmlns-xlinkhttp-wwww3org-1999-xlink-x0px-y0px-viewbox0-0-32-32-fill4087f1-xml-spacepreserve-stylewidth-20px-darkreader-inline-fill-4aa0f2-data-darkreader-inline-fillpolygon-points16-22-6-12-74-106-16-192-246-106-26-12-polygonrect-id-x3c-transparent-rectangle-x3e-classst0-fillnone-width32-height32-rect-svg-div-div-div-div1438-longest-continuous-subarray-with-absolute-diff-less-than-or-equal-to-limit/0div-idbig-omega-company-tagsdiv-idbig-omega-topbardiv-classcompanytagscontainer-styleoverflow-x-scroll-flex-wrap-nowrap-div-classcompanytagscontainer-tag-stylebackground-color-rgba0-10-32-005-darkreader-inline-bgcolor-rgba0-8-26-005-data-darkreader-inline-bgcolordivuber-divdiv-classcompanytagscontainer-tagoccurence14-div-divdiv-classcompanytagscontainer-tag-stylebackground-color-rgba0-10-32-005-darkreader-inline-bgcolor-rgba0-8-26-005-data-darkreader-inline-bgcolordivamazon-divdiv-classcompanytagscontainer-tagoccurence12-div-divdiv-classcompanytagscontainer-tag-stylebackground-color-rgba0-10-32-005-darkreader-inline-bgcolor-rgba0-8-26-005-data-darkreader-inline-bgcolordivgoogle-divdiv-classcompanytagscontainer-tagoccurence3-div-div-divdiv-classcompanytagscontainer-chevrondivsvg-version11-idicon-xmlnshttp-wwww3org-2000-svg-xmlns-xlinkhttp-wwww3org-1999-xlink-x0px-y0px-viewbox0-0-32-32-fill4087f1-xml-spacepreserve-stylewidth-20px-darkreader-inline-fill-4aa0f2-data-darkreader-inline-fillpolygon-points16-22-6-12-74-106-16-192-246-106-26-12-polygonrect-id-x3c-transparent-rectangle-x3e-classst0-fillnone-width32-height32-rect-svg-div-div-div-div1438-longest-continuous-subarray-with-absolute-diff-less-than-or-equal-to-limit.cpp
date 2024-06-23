class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
     deque<int>maxD,minD;
       int j=0,i=0,maxLen=0;
        for(j=0;j<nums.size();j++)
        {
           while(maxD.size()&&nums[j]>maxD.back())
               maxD.pop_back();
            maxD.push_back(nums[j]);
           while(minD.size() && nums[j]<minD.back())
               minD.pop_back();
            minD.push_back(nums[j]);
            if(maxD.front()-minD.front()>limit)
            {
               while(maxD.front()-minD.front()>limit)
               {
                  if(maxD.front()==nums[i])
                      maxD.pop_front();
                   if(minD.front()==nums[i])
                       minD.pop_front();
                   i++;
                   
               }
                
            }
            maxLen=max(j-i+1,maxLen);
        }
        return maxLen;
    }
};