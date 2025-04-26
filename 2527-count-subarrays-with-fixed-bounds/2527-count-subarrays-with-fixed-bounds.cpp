
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int _p = -1; 
        int _q = -1; 
        int p_ = -1; 
        int q_ = -1; 
        long long ret = 0; 
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == minK) {
                p_ = i; 
            } else if(nums[i] < minK) {
                _p = i; 
            }
            if(nums[i] == maxK) {
                q_ = i; 
            } else if(nums[i] > maxK) {
                _q = i; 
            }
            int l = max(_p,_q);
            int r = min(p_,q_);
            ret += max(0, r - l);
        }
        return ret; 
    }
};






















// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//        dequeue<int>de;
//     long long ans = 0;
//        for(int i = 0 ; i< n ;i++) {
//             if(nums[i] == minK){
//                   if(de.empty()){

//                   }
//             }
//             if(nums[i] == maxK){

//             }

//        }
//    return ans;





//         /*
        
//         1,3,5,2,7,5
//         0 1 2 3 4 5 
//         dequeue<int>de;
//          0 2 

//           ans +=1 ;

//           0 2 reamins same not 2 added : 
//            ans+=1 ;

//           now 5 will be remove from back_pop();
//            7 won't be spushed because 7 > maxK: 
//            si deque size == 1: so ans won't increases: 
//                 break the loop becuase i can't find: 
//                    no breaking coul lead incorrect result becuase in future 
//                     some subarry if having like [1,3,5,2,7,5 , 1, 3, 5] : 
//                     it gives incorrect results:

//            de : 0 
//               now i will get minvalueK again  which is equal to already exsing: 
//                so remove from beginging if subarray propoerty has broen : find maxk > value : yes:
 
             
//                1 5 : 


//         approach : 
//            for(i->n) 
//                for each range (i , j) get min and max :
//                      int max1 = *max_element(nums.being()-i,nums.end()-j);
//                      int min1 = *min_elemet(nums.begin()-i,nums.end()-j); 
//                  if(min ==minK && max ==maxK)
//                       ans++;
                 
//          becuase first 5 from left to right , we can'tt take enritr subarray rithgt side:


//         */
//     }
// };