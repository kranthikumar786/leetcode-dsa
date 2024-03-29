class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
     
        vector<vector<int>>ans;
         int n = firstList.size();
         int m = secondList.size();
        
        for(int i = 0 ; i < n ; i++) {
            
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            for(int j = 0 ; j < m ; j++) {
                  int start2 = secondList[j][0];
                  int end2 = secondList[j][1];
                
                if(start2 > end1 || start1 > end2) {
                     continue;
                } else {
                    ans.push_back({max(start1,start2) , min(end1,end2)});
                }
            }
        }
        return ans;
        /*
        Input: 
        firstList = [[0,2],[5,10],[13,23],[24,25]],
        secondList = [[1,5],[8,12],[15,24],[25,26]]
        
            
        Scenario1  : (0 <= 1  && 2 <= 5 )
                          if(0 <= 1 && 1 <= 2 && 2 <= 5)
        startPoint = max(List1[i][0], List2[j][0] );
        endPoint = min(List1[i][1],List2[j][1]);
        
               5 <= 8 && 10 < = 12 
                   */      
    }
};