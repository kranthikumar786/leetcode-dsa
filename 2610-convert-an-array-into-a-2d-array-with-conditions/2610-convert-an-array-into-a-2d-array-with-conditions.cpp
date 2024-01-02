class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums){
    int n = nums.size();
        
    vector<int>frequency(n+1);
    vector<vector<int>>ans;
      
    for(int num : nums){
        if(frequency[num] >= ans.size()){
            ans.push_back({});
        }
         ans[frequency[num]].push_back(num);
          frequency[num]++;
        
    }
    return ans;    
        
        
       
        
        
        
        /*
        unordered_map<int,int>Frequency;
 int maxFrequency = 0;
 for(int num : nums) {
     Frequency[num]++;
 }
 for(auto value : Frequency) {

     if(value.second >= maxFrequency) {
         maxFrequency = value.second;
     }
 } 
vector<vector<int>>finalAns;
  while(maxFrequency--){
      set<int>mySet;
      for(auto value : Frequency) {
         if(value.second >= 1) {
              mySet.insert(value.first);
              Frequency[value.first]--;
           }
         }
       vector<int>ans;  
     
      for(int value : mySet) {
          ans.push_back(value);
          mySet.erase(value);
      }
      finalAns.push_back(ans);
  }
return finalAns;
    */
    }};
    
  



/*   

 What went good : 
 
 1) you way of thinking towards to gathering requiremnts 
 2) testing code with best/ worst cases :
 3) problem undestanding like how many rows : 

 what went Not good : 
     =>  1 <= nums[i] <= nums.length 
         i missed this constraint so i wrote some bad/unnecessary code 
       
       using of unnecessary data structures like set : 
       unordered_map<int,int>Frequency;
    
   = > You wrote a bad code which not optimal code : 
   = > 
   
   
   
         
         
         
         
           
           
         
         


   Input: nums = [1,3,4,1,2,3,1]

          1->3
          2->1
          3->2
          4->1



    /*
    figure out  max value and max Frequency of a value
      O(n) + O(n)
       = O(n)

       to decide how many rows required Time complexity : O(n)

      first push all values into set data structure :
       then push into ans of 2D array 
      again take value from hash then push into set and later push into ans of 2d.
    
    Time Complexity: maxFrequency * O(all values)
  from example one: [1,3,4,1,2,3,1]
       3 * all values {1,2,3,4} : 


first decide : noofRows == maxFrequecny of a value from given input : 

              then after insert one by one value of Frequecny one 
              do reperat above steps.


[1,2,3,4,5,6] :  Space wise best case  with min rows

[1,1,1,1,1] : spacewise best case but more rows

[1]
[1]
[1]
[1]
[1]
27min of time to submit with status AC
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
*/
