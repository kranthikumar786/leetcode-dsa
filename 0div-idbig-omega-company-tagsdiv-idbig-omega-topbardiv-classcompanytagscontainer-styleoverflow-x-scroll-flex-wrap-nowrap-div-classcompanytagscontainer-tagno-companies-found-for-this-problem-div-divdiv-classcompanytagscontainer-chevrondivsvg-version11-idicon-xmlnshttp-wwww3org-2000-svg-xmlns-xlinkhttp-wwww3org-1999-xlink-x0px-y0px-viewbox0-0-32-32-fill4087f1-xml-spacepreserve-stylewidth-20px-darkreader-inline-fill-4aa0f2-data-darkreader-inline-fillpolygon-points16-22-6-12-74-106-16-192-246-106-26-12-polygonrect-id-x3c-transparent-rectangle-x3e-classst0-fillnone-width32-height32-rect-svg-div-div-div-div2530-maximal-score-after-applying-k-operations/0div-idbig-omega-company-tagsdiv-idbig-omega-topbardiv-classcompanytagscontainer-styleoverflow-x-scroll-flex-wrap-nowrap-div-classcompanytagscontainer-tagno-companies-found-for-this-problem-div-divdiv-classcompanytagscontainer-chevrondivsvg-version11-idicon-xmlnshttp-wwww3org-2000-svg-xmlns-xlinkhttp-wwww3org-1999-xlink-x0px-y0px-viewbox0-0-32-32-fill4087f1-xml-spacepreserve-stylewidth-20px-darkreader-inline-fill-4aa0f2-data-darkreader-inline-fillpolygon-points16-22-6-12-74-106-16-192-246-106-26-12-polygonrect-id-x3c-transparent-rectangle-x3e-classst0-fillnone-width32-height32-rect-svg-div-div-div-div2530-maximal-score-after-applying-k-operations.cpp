class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int>maxHeap;
        for(int num : nums) {
              maxHeap.push(num);
        }
       long long ans = 0;
          while (k--) {
               int topV = maxHeap.top();
                  maxHeap.pop();
              ans += topV;
            maxHeap.push(ceil(topV / 3.0));
          }
  return ans;
    }
};