class Solution {
public:
    int minAddToMakeValid(string S) {
        
        int res = 0;
        stack<char> st;
        
        for(char ch : S)
        {
            if(ch == ')')
            {
                if(st.empty())
                    res++;
                else
                    st.pop();
            }
            else if(ch == '(')
                st.push(ch);
        }
        
        while(!st.empty())
        {
            res++;
            st.pop();
        }
        return res;
    }
};