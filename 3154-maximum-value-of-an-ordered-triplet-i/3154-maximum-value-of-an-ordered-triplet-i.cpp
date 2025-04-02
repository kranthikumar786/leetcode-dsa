class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
       if(n < 3 ) {return 0;}

    long long  leftMax = nums[0];
    long long  rightMax = 0;   
    //    vector<int>maxValueRightSide(n,-1);
    //     maxValueRightSide[n-1] = nums[n-1];
    //   for(int k = n-2; k >= 0 ; k--) {
    //          maxValueRightSide[k] = max(maxValueRightSide[k+1], nums[k]);                 
    //     }
    //     vector<int>maxValueLeftSide(n,-1);
    //    maxValueLeftSide[0] = nums[0];
    //    for(int  i = 1; i < n ; i++) {
    //      maxValueLeftSide[i] = max(maxValueLeftSide[i-1],nums[i]); 
    //    }
    
    for(int i = 1; i < n -1; i++) {
                   
        rightMax = max(rightMax, leftMax - nums[i]); // Update rightMax as max diff
            ans = max(ans, rightMax * nums[i + 1]);      // Compute max triplet value
        leftMax = max(leftMax, (long long)nums[i]);  
    }
         return ans <= 0 ? 0 :ans;

    // for(int i = 0 ;i < n-2 ; i++) {
    //       for(int j = i +1; j < n-1  ;j++ ) {
    //             long long aa = (long long)(nums[i]-nums[j])*(maxValueTill[j+1]);
    //               ans = max(ans,aa);
    //            }
    //       } 
    //  return ans <= 0 ? 0 : ans; 
//========================================
    //   vector<int>maxValueLeftSide(n,-1);
    //    maxValueLeftSide[0] = nums[0];
    //    for(int  i = 1; i < n ; i++) {
    //      maxValueLeftSide[i] = max(maxValueLeftSide[i-1],nums[i]); 
    //      cout<<maxValueLeftSide[i]<<" ";
    //    }
    //    cout<<"\n";
    //     for(int i = 1; i < n - 1 ;i++) {

    //          for(int j = i+1 ; j < n ; j++) {
                   
    //                long long aa = (long long)(maxValueLeftSide[i-1]-nums[i])*(nums[j]);
    //             if(i == 2){
                  
    //                 cout<<maxValueLeftSide[i-1]<<" :" << nums[i] <<" ::" <<nums[j]<<" :::\n";
    //             //  cout<<aa<<" ";
    //               }
    //               ans = max(ans,aa);  
    //          }
    //     }

//         return ans <= 0 ? 0 :ans; 
    }
};