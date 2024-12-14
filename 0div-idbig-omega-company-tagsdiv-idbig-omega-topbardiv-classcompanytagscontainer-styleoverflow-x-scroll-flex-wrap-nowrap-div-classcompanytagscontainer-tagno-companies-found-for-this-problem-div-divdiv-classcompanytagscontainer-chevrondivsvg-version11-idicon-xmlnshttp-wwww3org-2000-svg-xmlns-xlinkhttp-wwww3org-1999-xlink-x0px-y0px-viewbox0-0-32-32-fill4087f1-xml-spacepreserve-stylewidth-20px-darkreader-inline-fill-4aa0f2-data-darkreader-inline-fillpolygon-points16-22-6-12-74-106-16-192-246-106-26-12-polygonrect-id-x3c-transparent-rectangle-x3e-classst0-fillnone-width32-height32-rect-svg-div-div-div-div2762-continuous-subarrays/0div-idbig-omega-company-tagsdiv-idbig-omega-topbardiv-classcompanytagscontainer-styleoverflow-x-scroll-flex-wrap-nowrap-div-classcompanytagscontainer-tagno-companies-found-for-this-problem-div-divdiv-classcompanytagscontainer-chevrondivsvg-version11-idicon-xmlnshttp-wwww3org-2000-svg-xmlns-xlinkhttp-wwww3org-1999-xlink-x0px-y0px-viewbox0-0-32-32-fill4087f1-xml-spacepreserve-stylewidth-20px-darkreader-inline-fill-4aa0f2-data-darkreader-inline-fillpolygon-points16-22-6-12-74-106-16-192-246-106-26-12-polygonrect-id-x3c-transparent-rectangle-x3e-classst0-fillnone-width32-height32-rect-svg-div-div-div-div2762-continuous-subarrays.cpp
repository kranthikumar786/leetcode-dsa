class Solution {
public:
    long long continuousSubarrays(vector<int>& a) 
    {
        long long ans = 0;
        multiset <int> st;
        for (int i = 0, j = 0; i < a.size(); i++)
        {
            st.insert(a[i]);
            while(*st.rbegin() - *st.begin() > 2)
            {
                st.erase(st.find(a[j++]));
            }
            ans += st.size();
        }
        return ans;
    }
};