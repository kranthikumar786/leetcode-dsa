class Solution {
public:
    bool judgeSquareSum(int c) {
       /*  int l=1,h=c;
        while(l<=h){
            int val=(l*l)+(h*h);
            int m=l+h>>1;
            if(val==c)
                return 1;
            else if(val>c)
                  h=m-1;
            else
                l=m+1;
        }
        return 0;
        */
      long  int l=0,r=sqrt(c);
        while(l<=r){
             long int cur=(l*l)+(r*r);
            if(cur>c)
                r--;
            else if(cur<c)
                 l++;
            else
                 return 1;
        }
        return 0;
    }
};