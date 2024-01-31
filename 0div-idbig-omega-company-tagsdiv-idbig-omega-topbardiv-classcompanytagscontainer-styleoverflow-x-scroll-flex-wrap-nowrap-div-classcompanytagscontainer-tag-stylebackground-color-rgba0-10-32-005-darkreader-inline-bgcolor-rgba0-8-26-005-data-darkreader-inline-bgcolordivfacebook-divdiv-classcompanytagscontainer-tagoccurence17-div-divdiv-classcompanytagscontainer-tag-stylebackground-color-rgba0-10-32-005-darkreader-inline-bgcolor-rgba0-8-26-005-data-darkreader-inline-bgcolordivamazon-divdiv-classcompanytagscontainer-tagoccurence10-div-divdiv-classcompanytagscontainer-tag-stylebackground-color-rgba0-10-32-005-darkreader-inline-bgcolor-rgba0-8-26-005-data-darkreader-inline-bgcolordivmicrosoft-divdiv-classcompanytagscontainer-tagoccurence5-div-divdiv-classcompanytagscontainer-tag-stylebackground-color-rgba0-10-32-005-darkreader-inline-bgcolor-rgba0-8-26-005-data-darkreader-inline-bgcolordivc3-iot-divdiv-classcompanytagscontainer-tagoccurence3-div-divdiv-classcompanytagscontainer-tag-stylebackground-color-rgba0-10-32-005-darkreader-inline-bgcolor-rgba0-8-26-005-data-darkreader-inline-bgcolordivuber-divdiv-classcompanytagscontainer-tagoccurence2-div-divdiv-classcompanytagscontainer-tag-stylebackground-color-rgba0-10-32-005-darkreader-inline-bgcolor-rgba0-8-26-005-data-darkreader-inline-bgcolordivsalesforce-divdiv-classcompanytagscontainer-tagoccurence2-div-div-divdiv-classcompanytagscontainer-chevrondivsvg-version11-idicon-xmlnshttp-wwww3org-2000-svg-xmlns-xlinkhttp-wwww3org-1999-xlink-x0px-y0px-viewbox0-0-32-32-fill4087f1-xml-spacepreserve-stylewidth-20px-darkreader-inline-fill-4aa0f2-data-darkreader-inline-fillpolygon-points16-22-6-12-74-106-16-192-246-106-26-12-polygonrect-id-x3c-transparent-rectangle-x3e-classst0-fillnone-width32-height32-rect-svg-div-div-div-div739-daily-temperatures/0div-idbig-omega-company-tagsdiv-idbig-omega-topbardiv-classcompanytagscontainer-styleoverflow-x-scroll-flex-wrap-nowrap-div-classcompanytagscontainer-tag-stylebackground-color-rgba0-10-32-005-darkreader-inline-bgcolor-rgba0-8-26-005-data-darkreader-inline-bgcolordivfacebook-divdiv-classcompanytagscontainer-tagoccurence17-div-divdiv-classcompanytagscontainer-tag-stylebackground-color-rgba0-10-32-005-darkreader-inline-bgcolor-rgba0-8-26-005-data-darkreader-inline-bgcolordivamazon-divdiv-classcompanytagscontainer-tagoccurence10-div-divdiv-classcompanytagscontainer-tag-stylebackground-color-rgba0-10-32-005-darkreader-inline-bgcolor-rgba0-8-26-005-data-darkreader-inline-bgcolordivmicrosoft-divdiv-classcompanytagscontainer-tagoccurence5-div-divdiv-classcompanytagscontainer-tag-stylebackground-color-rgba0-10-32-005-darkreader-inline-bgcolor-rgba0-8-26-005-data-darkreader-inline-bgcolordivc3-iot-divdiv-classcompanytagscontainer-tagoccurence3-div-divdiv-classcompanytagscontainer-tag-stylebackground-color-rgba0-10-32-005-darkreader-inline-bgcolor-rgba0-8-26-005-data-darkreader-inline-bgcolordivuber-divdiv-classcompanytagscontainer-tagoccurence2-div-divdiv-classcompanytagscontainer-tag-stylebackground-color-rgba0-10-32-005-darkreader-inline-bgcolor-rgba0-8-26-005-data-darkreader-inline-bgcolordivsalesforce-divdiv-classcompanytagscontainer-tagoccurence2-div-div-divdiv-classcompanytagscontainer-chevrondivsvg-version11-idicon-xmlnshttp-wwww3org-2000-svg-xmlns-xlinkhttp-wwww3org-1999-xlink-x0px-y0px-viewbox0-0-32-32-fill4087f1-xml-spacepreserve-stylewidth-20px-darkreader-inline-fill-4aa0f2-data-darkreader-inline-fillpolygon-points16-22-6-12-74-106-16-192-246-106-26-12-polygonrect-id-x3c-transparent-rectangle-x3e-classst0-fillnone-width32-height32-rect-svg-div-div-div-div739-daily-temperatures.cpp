class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        int i=n-1;
        for(;i>=0;i--)
        {
            while(!st.empty()&&temperatures[st.top()]<=temperatures[i])
                      st.pop();
            if(st.empty())
                ans[i]=0;
            else
                ans[i]=st.top()-i;
           st.push(i); 
            
        }
       // ans[0]=st.top()-i+1;
        return ans;
    }
};