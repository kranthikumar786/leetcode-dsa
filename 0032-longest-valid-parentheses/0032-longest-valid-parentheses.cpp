class Solution {
public:
    int longestValidParentheses(string s) {
       /* 
        this only=?()
        // this is =>(())
            
            
       
      )()())
            
         length is 4
           
         generate all substrings then check for max among these and updates 
             TC:O(n*N)
              sc:0(1)
            
        ()()()())  test case Provising max ans
           ()() pefrect ans+length becomes ans
               
           ( ()()( edges are not partonf ans:
               
                  ())(()()()((( ans ids provide in middle/
                
          ()()( ()()()() one the test case:
               
               
            ()()( ()() ans can have mulplie ans..?
                 
                 
                  
                  base case is if s.size()<1
              return 0;
        */
        
        
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            int t=stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
     
            
        
    }
};