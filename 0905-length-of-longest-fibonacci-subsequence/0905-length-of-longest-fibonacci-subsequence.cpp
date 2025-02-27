class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> indexMap;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            indexMap[arr[i]] = i;
        }

        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int prevVal = arr[k] - arr[j];
                if (prevVal >= arr[j]) continue;
                
                if (indexMap.count(prevVal)) {
                    int i = indexMap[prevVal];
                    dp[j][k] = dp[i][j] + 1;
                    maxLen = max(maxLen, dp[j][k]);
                }
            }
        }

        return (maxLen > 2) ? maxLen : 0;
    }
};



// class Solution {
// public:
//     unordered_map<int, int> indexMap;
//     unordered_map<int, unordered_map<int, int>> dp; 

//     int rec(int i, int j, vector<int>& nums) {
//         if (j >= nums.size()) return 0;  

//         if (dp[i].find(j) != dp[i].end()) return dp[i][j]; 

//         int nextVal = nums[i] + nums[j];  
//         int k = indexMap.count(nextVal) ? indexMap[nextVal] : -1;

//         int take = 0;
//         if (k != -1) take = 1 + rec(j, k, nums); 

//         return dp[i][j] = take;
//     }

//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n = arr.size();
//         int maxLen = 0;

//         for (int i = 0; i < n; i++) {
//             indexMap[arr[i]] = i;
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 maxLen = max(maxLen, 2 + rec(i, j, arr)); // Minimum length is 2
//             }
//         }

//         return (maxLen > 2) ? maxLen : 0;
//     }
// };




// class Solution {
// public:
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n = arr.size();
//         unordered_set<int> numSet(arr.begin(), arr.end());
//         int maxLen = 0;
//         for (int start = 0; start < n; ++start) {
//             for (int next = start + 1; next < n; ++next) {
//                 int prev = arr[next];
//                 int curr = arr[start] + arr[next];
//                 int len = 2;
//                 while (numSet.find(curr) != numSet.end()) {
//                     int temp = curr;
//                     curr += prev;
//                     prev = temp;
//                     maxLen = max(maxLen, ++len);
//                 }
//             }
//         }
//         return maxLen;
//     }
// };


// class Solution {
// public:
//     unordered_set<int> Fre;  
//     int rec(int index, vector<int>& nums, vector<int>& arr) {
//         if (index >= nums.size()) {
//             return arr.size();
//         }

//         if (arr.size() >= 2) {
//             int lastTwoSum = arr[arr.size() - 2] + arr[arr.size() - 1];

//             if (lastTwoSum > nums.back()) {
//                 return arr.size();
//             }
//             if (Fre.find(lastTwoSum) == Fre.end()) {
//                 return arr.size();
//             } else {
//                 arr.push_back(lastTwoSum); 
//             }
//         }

//         if (arr.size() < 3) {
//             arr.push_back(nums[index]);
//         }

//         int take = rec(index + 1, nums, arr);  

//         if (!arr.empty())
//             arr.pop_back();  

//         int donTake = rec(index + 1, nums, arr);  

//         return max(take, donTake);
//     }

//     int lenLongestFibSubseq(vector<int>& arr) {
//         Fre.clear();
//         for (int num : arr) {
//             Fre.insert(num);  
//         }
//         vector<int> lp;
//         int ans = rec(0, arr, lp);
//         return (ans < 3 ? 0 : ans);  
//     }
// };

 /*

 [1,3,100,120]

[1,2,3,5,8,11]

   [1,2,3,4,5,6,7,8]

    1 : 2 3 : 

    1,2,1+2 = 3 :
   1 2 3 : 
      2 + 3 = 5 : 
 1 2 3 5 : 
     3 + 5 = 8 : 

  1 don't take : 
  2 3   4not equal 
   
   2 + 3 = 5 : next elemt : 
   2 3 5 : 
      3  +5 = 8 : is present ..? yes: 

    2 3 5 8 
        5 + 8 = 13 is out of range nums 13 > [end-1] : 
              return :
    4 : 2 3 5 8 : 

    don't include 2 :

    3 4  != 5
    3 + 4 = 7 : 
   3 length :  3 4 7 : 
       4 + 7 = 11 > 8 : 

    will process the ame till last  elemts : 






   will take 2^n : tc :
   SC:0(n) : 
    1 : next two elemts search : 

 pseduco code : 

 hashMap<int>Fre;
 rec(int index ,nums,arr){
     if(index >= n  ){
          return arr.length(); 
     }
     if(arr.legnth() >= 2){
         if(arr[lefnght()-2] + arr[legth()-1] > arr[n-1]){
              return arr.length();
         }
        if(fre.count(arr[lefnght()-2] + arr[legth()-1]) > 0) 
            ans.push_back(arr[index]);  
     }
     if(arr.length() < 2){
        arr.push_back(arr[index]);
     }
    int take = rec(index +1 , nums);
       ans.pop_back();
    int don'tTake = rec(index+1, nums,arr);
    return max(take, don'ttake)
 }

     1 + 2 = 3 : 
     1 2 3 : 


        what is coming into my mind : 
         take and don;t take ...? 
          how ...? 

          if single elemtns iam aware of it  easily : 
           like
             take =    nums[i] + rec(i+1,nums) ;
             don'take =         rec(i+1, num) : 
  
  


        

    if(n  < 3) {reutrn 0 ;} // input base case: 


 */

//     }
// };