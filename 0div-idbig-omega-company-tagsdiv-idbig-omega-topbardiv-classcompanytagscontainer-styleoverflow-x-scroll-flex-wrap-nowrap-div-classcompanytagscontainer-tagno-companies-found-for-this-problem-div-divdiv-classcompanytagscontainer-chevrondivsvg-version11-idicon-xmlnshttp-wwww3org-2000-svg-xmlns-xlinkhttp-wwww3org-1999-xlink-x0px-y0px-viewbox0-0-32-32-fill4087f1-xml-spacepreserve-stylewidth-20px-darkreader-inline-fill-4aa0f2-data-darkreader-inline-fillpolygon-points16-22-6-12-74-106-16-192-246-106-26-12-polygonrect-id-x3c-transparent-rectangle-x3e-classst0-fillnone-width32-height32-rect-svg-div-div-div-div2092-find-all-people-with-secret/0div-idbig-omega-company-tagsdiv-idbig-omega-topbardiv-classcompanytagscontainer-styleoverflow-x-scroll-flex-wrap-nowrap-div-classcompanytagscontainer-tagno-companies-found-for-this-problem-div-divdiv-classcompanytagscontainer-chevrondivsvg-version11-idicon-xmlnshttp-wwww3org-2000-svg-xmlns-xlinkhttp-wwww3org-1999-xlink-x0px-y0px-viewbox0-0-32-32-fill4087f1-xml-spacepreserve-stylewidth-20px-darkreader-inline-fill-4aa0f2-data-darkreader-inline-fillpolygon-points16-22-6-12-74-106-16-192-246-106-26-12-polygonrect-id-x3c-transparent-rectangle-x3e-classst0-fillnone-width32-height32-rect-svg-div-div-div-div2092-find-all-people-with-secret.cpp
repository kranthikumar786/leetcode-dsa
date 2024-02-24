class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
  
        
        /*
        Sort the elemtns in Asce order with time.

      [1,2,2]   [3,1,3] [0,3,3] : 
 
 
 
 p = 3 :  t = 0
 p = 3 ,   t = 2 :    this time no entry into ans array : 
 
  p = 3 -> 1 : t = 3 : 
      3- > 0 :  t = 3 :      hashset[3,1,0] : 
      
      p = 1  or p = 0 : 
      
      so simple travesring eon't work , thinking towards to backtrack with alrady visited node ..? 
        possiblity like hraph Question ..? 
         undirected weighted graph ..? 
           
           iam slo thinkg like time constraint ..  ..? think with prime/ kruskal algos ..? 
           
      like this possibilitylist : [ 1,0 ]

        */
        
       unordered_map<int,vector<pair<int,int>>>Graph;
       
        for(auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1] , t = meeting[2];
            Graph[x].emplace_back(t,y);
            Graph[y].emplace_back(t,x);
        }
       vector<int>earliest(n,INT_MAX);
        earliest[0] = 0; // this is at 0th
        earliest[firstPerson] = 0; // first Person can be any place in n
        queue<pair<int,int>>q;
        q.emplace(0,0);
        q.emplace(firstPerson,0);
        // DO DFS
        
         while (!q.empty()) {
             auto [person,time] = q.front();
             q.pop();
             
             for(auto [t,nextPerson] : Graph[person]) {
                 
                    if( t >= time && earliest[nextPerson]  >t) {
                          earliest[nextPerson] = t;
                         q.emplace(nextPerson,t);
                    }
             }
         }
        
        vector<int>ans;
        for(int i = 0 ; i < n ; i++) {
              if ( earliest[i] != INT_MAX){
                  ans.push_back(i);
              }
        }
        return ans;
    }
};