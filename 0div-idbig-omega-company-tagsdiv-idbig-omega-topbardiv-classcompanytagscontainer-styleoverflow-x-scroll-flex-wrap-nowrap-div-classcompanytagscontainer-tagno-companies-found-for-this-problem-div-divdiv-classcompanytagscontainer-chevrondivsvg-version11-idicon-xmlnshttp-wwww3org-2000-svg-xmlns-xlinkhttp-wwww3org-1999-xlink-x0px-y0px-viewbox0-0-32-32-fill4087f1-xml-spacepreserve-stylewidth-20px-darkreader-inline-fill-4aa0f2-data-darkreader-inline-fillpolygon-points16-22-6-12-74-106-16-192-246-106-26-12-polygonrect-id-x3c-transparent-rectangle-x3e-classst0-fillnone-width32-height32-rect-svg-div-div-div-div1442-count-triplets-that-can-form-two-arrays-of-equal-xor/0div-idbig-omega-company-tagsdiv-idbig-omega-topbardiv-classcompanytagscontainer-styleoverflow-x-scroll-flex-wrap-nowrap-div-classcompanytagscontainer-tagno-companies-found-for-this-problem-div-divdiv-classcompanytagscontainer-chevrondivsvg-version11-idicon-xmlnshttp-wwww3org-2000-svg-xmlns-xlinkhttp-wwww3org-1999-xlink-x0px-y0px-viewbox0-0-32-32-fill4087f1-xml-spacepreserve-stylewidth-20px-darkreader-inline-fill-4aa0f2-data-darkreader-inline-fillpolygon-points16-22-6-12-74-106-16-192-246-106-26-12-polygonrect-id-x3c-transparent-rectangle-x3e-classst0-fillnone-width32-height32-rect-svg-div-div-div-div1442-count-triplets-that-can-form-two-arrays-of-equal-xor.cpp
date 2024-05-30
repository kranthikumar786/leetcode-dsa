class Solution {
public:
    int countTriplets(vector<int>& a) {
        int c=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            int x=0;
            for(int j=i;j<n;j++)
            {
                x=x^a[j];
                int y=0;
                for(int k=j+1;k<n;k++)
                {
                    y=y^a[k];
                    if(y==x) c++;
                }
            }
        }
        return c;
    }
};