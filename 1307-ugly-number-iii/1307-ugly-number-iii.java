class Solution {
    
    public long gcd(long a , long b) {
        return b == 0 ? a : gcd(b,a%b);
    }
    public long lcm(long a, long b) {
          return a / gcd(a,b)*b;
    }
    public int nthUglyNumber(int n, int a, int b, int c) {
      long ab = lcm(a,b);
      long bc = lcm(b,c);
      long ac = lcm(a,c);
      long abc = lcm(ab,c);
      long low = 1 ; long high = 2_000_000_000;
      while(low < high) {
        long mid = low + (high-low) /2;
        long cnt = mid/a + mid/b + mid/c - mid/ab-mid/bc-mid/ac+mid/abc;
        if(cnt < n) {
            low = mid+1;
        }else{
            high = mid;
        }
      }
    return (int)low;
    }
}

/**

long pr = (long)a*b;
    pr = pr * c;
    int cnt = 0;
    for(int i = 1; i <= pr ; i++) {
         if(i%a == 0 || i%b == 0 || i%c ==0){
            cnt++;
         }
         if(cnt == n){return i;}
    }
   return (int)pr;

 take range [1-50] :  n = 22 , a = 2 , b = 3, c= 5 : 
     50/a = 25 : times:
     50/b = 16 imes:
     50/c = 10 times:
     i just need 22 : 
     here individulay values are ginving 25, 16,10 but i can't chose signle ele:

     becuase in the squnce values are like 2, 3, 4, 5,6, : here for 2 3 only counted:
        so have to take combinely ;;;
     so common factor: 
     least common factor  ..? of all three might help ..? 

   

 */