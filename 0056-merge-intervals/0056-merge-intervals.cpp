class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end());
         stack<pair<int,int>>st;
         for(auto interval : intervals) {
            int sleft = interval[0];
            int sright = interval[1]; 
            while(!st.empty() && st.top().second >= sleft) {
                sleft = min(sleft, st.top().first);
                sright = max(sright, st.top().second);
                   st.pop();
              }
             st.push({sleft,sright}); 
         }
         vector<vector<int>> ans;
        while (!st.empty()) {
            ans.push_back({st.top().first, st.top().second});
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
//             int total  = intervals.size();
//            for(auto interval : intervals) {
//             minHeap.push({interval[0],interval[1]});
//            }
//            vector<vector<int>>ans;
//            while(!minHeap.empty()) {
//               int topleft = minHeap.top().first;
//               int topright = minHeap.top().second;
//                          minHeap.pop();
//                      while(!minHeap.empty()) {
//                        int sleft = minHeap.top().first;
//                        int sright = minHeap.top().second;
//                          if(topright >= sleft) {
//                             total--;
//                             topright = max(topright,sright);
//                           //  topright = sright;
//                               minHeap.pop();
//                          } else{break;}
//                      }
//                      vector<int>bb;
//                      bb.push_back(topleft);
//                      bb.push_back(topright);
//                   ans.push_back(bb);   
//            }
//           //cout<<total<<"\n"; 
//     return ans;
//     }
// };

// /*
// [[1,4],[2,3]]
// */

// //class Solution {
// // public:
// //     /*static bool cmp(vector<int>&a, vector<int>&b){
// //         return (a[0] == b[0] && a[1] > b[1]);
// //     }*/
// //     vector<vector<int>> merge(vector<vector<int>>& intervals) {
// //       vector<vector<int>>ans;
// //       sort(intervals.begin(),intervals.end());
// //        int n = intervals.size();
// //         for (int i = 0 ; i < n ; i++) { 
// //           cout<<intervals[i][0] << intervals[i][1] <<" ";
// //        }
// //        ans.push_back(intervals[0]);
        
      
// //          int left = 0 , right = n - 1 , mid ;
        
// //          while (left <= right && left < n ) {
// //                  mid = (right + left)>>1;
             
// //               if(ans.back()[1]  >= intervals[mid][0]) {
// //                    ans.back()[1] = max(ans.back()[1] , intervals[mid][1]);
// //                    left = mid +1;
// //               } else {
// //                   ans.push_back(intervals[mid]);
// //                   left = mid +1;
// //               }
// //          } 
        
// //         /*
// //         for(int cur = 1 ; cur < n ; cur++){
            
// //             if(ans.back()[1] >= intervals[cur][0]) { 
// //                  // if(ans.back()[1] > intervals[cur][1])
// //                    //     continue;
// //                 ans.back()[1] = max(intervals[cur][1],ans.back()[1]);
// //             } else{
// //              ans.push_back(intervals[cur]);   
// //             }
// //         }   */
// //         return ans;
// //     }
// // };