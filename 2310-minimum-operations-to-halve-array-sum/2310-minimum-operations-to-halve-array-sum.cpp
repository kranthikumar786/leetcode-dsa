class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>maxHeap ;
        double sum = 0; 
       for(int num : nums){
          sum += num;
          maxHeap.push(num);
       } 
     double sum2 = sum;
     sum /= 2.0; // 15.5
      int cnt = 0;
       while(maxHeap.size() > 0 && sum < sum2) {
             cnt++;
             double topV = maxHeap.top(); maxHeap.pop();
             sum2 -= topV;
             topV /= (2.0);
             sum2 += topV;
             maxHeap.push(topV);
       }
      return cnt;  
    }
};