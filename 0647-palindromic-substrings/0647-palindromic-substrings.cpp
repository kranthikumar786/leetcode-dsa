class Solution {
public:
    int countSubstrings(string s) {
        int e=-1,m=-1,r,l,k,c=0;
        string ps = "#";
        for(int i=0;i<s.size();i++){
            ps+=s[i]; ps+="#";  //#a#b#c#b#a
        }
        vector<int>v(ps.size()+1,0);
        
        for(int i=0;i<ps.size();i++){
            int mr = 2*m-i, k = 0;
            // power of precomputation
            if(e>=i) k = min(e-i,v[mr]);
            l = i-k; r = i+k;
            // normal matching
            while(--l>=0&&++r<ps.size() && ps[l]==ps[r])
                k++;
            l++;r--;
            v[i] = k;
            if(r>=e){
                e=r;
                m=i;
            }
            c+=(k+1)/2;
        }
        return c;
    }

};
