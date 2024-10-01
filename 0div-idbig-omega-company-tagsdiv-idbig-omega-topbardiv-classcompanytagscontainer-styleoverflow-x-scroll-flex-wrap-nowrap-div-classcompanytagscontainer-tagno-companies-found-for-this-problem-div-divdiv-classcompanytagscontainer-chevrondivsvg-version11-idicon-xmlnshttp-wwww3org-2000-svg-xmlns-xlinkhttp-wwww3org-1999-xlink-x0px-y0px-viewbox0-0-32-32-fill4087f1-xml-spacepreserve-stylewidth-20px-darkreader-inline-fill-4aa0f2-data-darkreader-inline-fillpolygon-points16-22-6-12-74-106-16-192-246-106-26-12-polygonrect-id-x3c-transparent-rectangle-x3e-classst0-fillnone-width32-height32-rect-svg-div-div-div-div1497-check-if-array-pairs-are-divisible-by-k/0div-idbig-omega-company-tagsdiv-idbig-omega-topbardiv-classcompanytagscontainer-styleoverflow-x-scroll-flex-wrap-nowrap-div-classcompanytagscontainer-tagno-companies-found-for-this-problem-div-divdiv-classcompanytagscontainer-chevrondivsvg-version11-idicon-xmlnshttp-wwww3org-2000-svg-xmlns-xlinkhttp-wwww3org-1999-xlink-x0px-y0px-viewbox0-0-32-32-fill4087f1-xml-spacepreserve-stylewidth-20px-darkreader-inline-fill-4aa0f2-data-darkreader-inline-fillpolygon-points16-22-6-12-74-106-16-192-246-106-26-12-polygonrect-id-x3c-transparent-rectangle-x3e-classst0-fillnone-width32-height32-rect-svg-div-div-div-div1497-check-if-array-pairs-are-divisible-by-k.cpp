class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]%k;
            if(arr[i]<0) arr[i]+=k;
        }
        sort(arr.begin(),arr.end());
        
        int l=0;
        int r=n-1;
        
        int c=0;
        while(l<n && arr[l]==0)
        {
            c++;
            l++;
        }
        if(c%2==1) return false;
        
        while(r>l)
        {
            if(arr[r]+arr[l]!=k) return false;
            
            r--;
            l++;
        }
        return true;
    }
};