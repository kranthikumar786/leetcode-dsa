class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        unordered_set<int> distinctSet(nums.begin(), nums.end());
        int totalDistinct = distinctSet.size();

        unordered_map<int, int> freqMap;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            freqMap[nums[right]]++;

            while (freqMap.size() == totalDistinct) {
                ans += (n - right);
                
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }
                left++;
            }
        }

        return ans;
    }
};



// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//      int n = nums.size();
//       int ans = 0;
//     unordered_set<int>s;
//     for(int num : nums){
//          s.insert(num);
//     }
//     int distint = s.size();
//       s.clear();

//      unordered_map<int,int>um;
//      int leftptr = 0;
//      int rightPtr = 0;
//       while(leftptr < n) {
//            while(rightPtr < n ) {
//                 um[nums[rightPtr]]++;
//                if(um.size() == distint) {
//                  ans += (n-rightPtr);
               
//                }
//                rightPtr++; 
//            }
//             um[nums[leftptr]]--;
//                 if(um.size() == distint) {
//                  ans += (n-leftptr);
//                  //leftptr++;
//                } else{
//                   break;
//                }
//                 um[nums[leftptr]]--;
//               leftptr++; 
//       }
//     //   for(int i = 0 ; i < n ;i++) {
//     //           s.clear();
//     //       for(int j = i ; j < n ;j++) {
//     //             s.insert(nums[j]);
//     //            if(s.size() == distint ) {
//     //               ans += (n-j);
//     //                break;
//     //            }
//     //       }
//     //   }
//          return ans;
//     }
// };

// /*
// [1,3,1,2,2,6]
// [1,3,1,2,2,6]

// 5,5,5,5,5:
//  5: 
// 5 5 5 5 
// 4

// 5  5  5

//  3 

//  here what should be a calcautor: index , or size of set:

// 1 3 1 2 2 : 

// 1 3 1 2 :  1: 
// 1 3 1 2 2 : 2: 

//   3 1 2 2 : 1: 

//     size of subarray : 
//       remove subarray size then get add the no.of elemnets raming:
//    1 3 1 2 2 : 
//      3 1 2 2 : 

//      once 1 removed from unorder_map : 
//        map.size() == distinctvalues: 
//          if(n-j > distinctValue) {
//             ans++ ;

//          } 





// */