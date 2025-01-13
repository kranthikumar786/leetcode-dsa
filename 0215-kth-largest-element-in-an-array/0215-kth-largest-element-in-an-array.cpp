class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>heap; // default is maxHeap : 
        for(int num : nums){
            heap.push(num);
        }
         k--;
       while(k--) {
            int top = heap.top();
             heap.pop();
          }
  return heap.top();
    }
};

