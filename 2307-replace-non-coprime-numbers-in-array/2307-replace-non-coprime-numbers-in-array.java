class Solution {
    public int GCD(int a, int b){
          while(b != 0){
             int temp = b;
             b = a%b;
             a = temp;
          }
         return a; 
    }
    
    public List<Integer> replaceNonCoprimes(int[] nums) {
       List<Integer>st = new ArrayList<>();
      for(int num : nums){
          while(st.size() > 0 ){
             int top = st.get(st.size()-1);
             int gcdNum = GCD(top,num);
             if(gcdNum  <= 1){
                    break;
              }
               st.remove(st.size()-1);
               //num = (top * num)/gcdNum; 
               num = (top/ gcdNum)*num;
          }
         st.add(num); 
      }
     return st;

       /**
        int gcd(int a, int b){
              while(b != 0){
                int temp = b;
                b = a%b;
                a = b;
              }
        }
        int gcdFromMe = gcd(a,b);
      if(gcdFromMe > 1)
      lcm = a*b /gcdFromMe ;
       st.add(lcm);
        else{
            break;
        }
        */ 
    }
}