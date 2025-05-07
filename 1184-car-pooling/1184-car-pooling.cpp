class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

      vector<int>diffarray(1001,0);
       for(auto trip : trips){
        diffarray[trip[1]] += trip[0];
        diffarray[trip[2]] -= trip[0];
       }

     for(int i = 0; i < 1001; i++) {
          capacity -= diffarray[i];
          if(capacity < 0){return 0;}
     } 
     return capacity >=0 ;
    }
};

/*
class Solution {
public:
   static bool Compare(vector<int>&a ,vector<int>&b){
       if(a[1] == b[1]) {
          return a[2] < b[2];
       }
       return a[1] < b[1];
   }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
     sort(trips.begin(),trips.end(),Compare);
     int curCap = 0; 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
     for(auto trip : trips) {
         while(!minHeap.empty() && minHeap.top().first <= trip[1]) {
                curCap -= minHeap.top().second;
                minHeap.pop();
                }
         if(curCap + trip[0] <= capacity) {
             minHeap.push({trip[2],trip[0]});
             curCap += trip[0];
          }
           else{
            return false;
           }
     }
      return true;
    }
};
[[2,1,5],[3,1,6],[3,1,7]]
cp : 7 ,  flas3e
cp : 8  true
cp : 9 :  true

[[2,1,5],[3,5,6],[3,1,7]]

 cp : 6 : 


[8,1,7],  7, 8
[4,2,9]]  9 , 12
[[9,3,6], so ideally take this : and for removing i ahve to check complte st and end: 
              
               7 <= 3 , no 
           6 , 26 
                
[8,4,9],
[6,6,8],
28: 

*/