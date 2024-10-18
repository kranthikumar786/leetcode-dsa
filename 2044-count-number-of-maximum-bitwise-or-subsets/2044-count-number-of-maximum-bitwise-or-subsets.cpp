class Solution {
public:
    int c=0;
    void t(int i,int x,int m,vector<int> &a)
    {
        if(i>=a.size()) return ;

        int y=x|a[i];
        if(y==m) c++;
        t(i+1,y,m,a);
        t(i+1,x,m,a);
    }
    int countMaxOrSubsets(vector<int>& a) {
        int m=0;
        for(int i=0;i<a.size();i++)
        m=m|a[i];
        t(0,0,m,a);
        return c;
    }
};