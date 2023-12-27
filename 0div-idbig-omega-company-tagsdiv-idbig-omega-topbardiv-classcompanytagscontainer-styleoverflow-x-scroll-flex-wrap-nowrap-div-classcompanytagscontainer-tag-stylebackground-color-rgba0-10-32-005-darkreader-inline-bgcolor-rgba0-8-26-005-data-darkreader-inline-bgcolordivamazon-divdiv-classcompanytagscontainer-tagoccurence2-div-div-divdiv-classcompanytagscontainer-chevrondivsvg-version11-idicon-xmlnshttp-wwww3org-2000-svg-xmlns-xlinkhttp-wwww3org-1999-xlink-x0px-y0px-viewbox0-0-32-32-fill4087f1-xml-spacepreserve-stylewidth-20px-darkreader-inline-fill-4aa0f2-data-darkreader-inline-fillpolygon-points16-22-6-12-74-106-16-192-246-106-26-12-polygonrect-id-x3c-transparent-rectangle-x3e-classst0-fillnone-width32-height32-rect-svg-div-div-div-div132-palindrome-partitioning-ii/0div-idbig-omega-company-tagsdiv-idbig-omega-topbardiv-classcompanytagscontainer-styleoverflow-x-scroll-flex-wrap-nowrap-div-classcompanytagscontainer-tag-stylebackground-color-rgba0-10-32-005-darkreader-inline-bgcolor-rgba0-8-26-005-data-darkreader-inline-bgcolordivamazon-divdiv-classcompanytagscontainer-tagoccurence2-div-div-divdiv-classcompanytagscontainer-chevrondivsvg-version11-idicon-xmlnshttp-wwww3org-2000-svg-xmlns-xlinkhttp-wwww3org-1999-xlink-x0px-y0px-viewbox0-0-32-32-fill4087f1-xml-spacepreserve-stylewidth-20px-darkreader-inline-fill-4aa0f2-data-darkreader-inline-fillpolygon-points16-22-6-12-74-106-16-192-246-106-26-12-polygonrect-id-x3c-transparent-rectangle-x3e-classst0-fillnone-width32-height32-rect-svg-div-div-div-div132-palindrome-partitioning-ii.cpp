class Solution {
public:
    int minCut(string s) {
  vector<int> dp(s.size() + 1);
  iota(begin(dp), end(dp), 0);
  for (int m = 0; m < s.size(); ++m) {
    for (int i = m, j = m + 1; i >= 0 && j < s.size() && s[i] == s[j]; --i, ++j) 
        dp[j + 1] = min(dp[j + 1], 1 + dp[i]);
    for (int i = m, j = m; i >= 0 && j < s.size() && s[i] == s[j]; --i, ++j) 
        dp[j + 1] = min(dp[j + 1], 1 + dp[i]);
  }
  return dp[s.size()] - 1;

    
    
    
   /* bool isPalindrome(int leftIndex , int rightIndex , const string &s) {
   
        while(leftIndex <= rightIndex && s[leftIndex++] != s[rightIndex--]) {
               return false;
         }
        return true;
    }

 int minPartitioning(int startIndex , const string &s, vector<int>&dp) {
      if(startIndex == s.size()) {return 0;}
       if(dp[startIndex] != -1) {
             return dp[startIndex];
       }

       int ans = INT_MAX;
       for(int endIndex = startIndex ;endIndex < s.size() ; endIndex++) {
             if(isPalindrome(startIndex ,endIndex,s)) {
                       cout<<startIndex << " :" <<endIndex<<"\n";
                 int minCount = 1 + minPartitioning(endIndex +1 , s , dp);
                 ans = min(ans,minCount);
             }
       }
      return dp[startIndex] = ans; 
 }  
    int minCut(string s) {
  vector<int>dp(s.size() , -1);
  return minPartitioning(0 , s, dp)-1;

        /*
        max cuts will be s.lenth()-1 : ex  : if  s = "aab" = > 3 then max xuts will be 2  : 
        
        which one to chosee and why ...?
        
          left == right 
            (OR)  
          left == left +1 ..?
          
          example 1:
          
           s = "aab"
           
           
             every single char is palindrome so  let's cut  
             
                3  < = >a | a | b| 
                      = > aa| b (remaining)
                      
                        so check aa is palindrome or not =  > yes palindomre
                        next 
                         aab = > it not a palindrome 
                          come back to aa | reaming string lenth -1 could be added to alrady existing                                ans
                          
                           then move with next 
                           
                           aabb is string 
                           
                           aab not a palindrome 
                         but  bb is palindome 
                         so 
                         
                         come to next index of where palindrome ended 
                         
                          now bb is my string = >  fine min for this : 
                           b is palinfrome 
                           bb is palindrome ..? 
                           yes 
                           so only 1 cut reruried finally
                             
                           so just to count how many times the  palidomr's index + 1 calling

        */


        
    }
};