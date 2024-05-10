class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        int n = arr.size();
        map<double, pair<int,int>> mp;
        vector<int> ans;
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            double a = arr[i];
            double b = arr[j];
            double db = a/b;
            mp[db] = {i,j};
            j--;
            if(i==j)
            {
                i++;
                j = n-1;
            }
        }
        int c = 0;
        for(auto it : mp)
        {
            c++;
            if(c==k)
            {
                ans.push_back(arr[it.second.first]);
                ans.push_back(arr[it.second.second]);
                break;
            }
        }
        return ans;
    }
};