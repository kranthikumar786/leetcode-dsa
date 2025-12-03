class Solution {
    public int hammingWeight(int n) {
      int cnt = 0;
      while(n >=2){
          cnt += (n%2);
          n/=2;
      } 
     return cnt+=n;
    }
}