class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1,0);
     steps[0]=1;
     steps[1]=2;
     for(int i=2;i<n;i++)
     {
         steps[i]=steps[i-2]+steps[i-1];
     }
     return steps[n-1]; 
    }
};
/*
   ans(3):

   ans(2) 

     ans(1) : 

    

   
*/