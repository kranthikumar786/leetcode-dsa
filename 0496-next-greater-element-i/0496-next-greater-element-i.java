class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    HashMap<Integer,Integer>nextGreastEle = new HashMap<>();
    Stack<Integer> st = new Stack<>();
    int n = nums2.length;
    for(int i = n-1;  i >= 0 ;i--) {
          while(!st.isEmpty() && st.peek() < nums2[i]) {
                  st.pop();
          }
        nextGreastEle.put(nums2[i] , st.isEmpty()  ? -1: st.peek());
        st.push(nums2[i]);  
    }
    int ans[] = new int[nums1.length];
    for(int i = 0 ; i < nums1.length ;i++){
         ans[i] = nextGreastEle.get(nums1[i]);
    }
  return ans;  
      
      /**
       Approach 1: 
        take i :  O(n)
           find same nums[i] == nums[j] :  O(n)
                  then find next greast elemtn L : O(n) 

   Tc : O(n^3) : 
   Sc : O(1):
  ---------------------
   Aprpoach 2: 
    ALL ARE UNIQUE ELEMNTS 
  num2 : putin HASHmPA: [] : TC : O(n) : + Sc: O (2*n) 
    put al vlaues in HashMap with Value and Index:  O(n) : 
       THEN FIND next greated elent in num2: O(n) : 

         TC : O(N^2) : 
         Sc : o(N):   
----------------------------------------------------
Approach 3 :
   nestGrestElm : 
      [1,3,4,5] : nestGreast won;t give by Suufix Max or preix mAx: 
         it giv emax in cmpltely righ side with continoues same left side as well: 
           5 -1

  stack is Best: 
   with SuffixMax:  O(n) : 
   [1,3,4,2] : 
    
  HashMap : []  : O(n) 
                [stack : 1, ]
 max[3, 4 -1,-1]   

 pseducODE: 
   Tc: O(n) :HashMpa with valuebbyIndex for num2: 
      
     Tc:  nextGREASTvALUE using stack then storu in righMaxSuffix: O(n) :

    num1: 
       HasmAP + rightMaxSuffix : (1) : 

    TC : O(n) : 
    Sc : O(n) + O(n) : (stack + rightMaxSuffix) :    

HashMap<Integer,Integer> valueByIndex = new HashMap<>();
    int n  = nums2.length;
    for(int i = 0 ; i < n ;i++) {
           valueByIndex.put(nums2[i],i); // {1->0,3->1, 4->2, 2->3}
    }  
    Stack<Integer> st = new Stack<>();
    int rightMax[] = new int[n];
    for(int i = n-1; i >= 0 ;i--) {
          while(!st.isEmpty() &&  st.peek()  < nums2[i] ) {
               st.pop();
          }
         rightMax[i] = st.isEmpty() ? -1 : st.peek();
         st.push(nums2[i]);     // [-1,-1]
    }  
   int ans [] = new int[nums1.length];
   for(int  i = 0 ; i < nums1.length ;i++) {
          int index = valueByIndex.get(nums1[i]);
        ans[i] = rightMax[index];
   }


Approach 4 : 

 not required of addtion arary to stor enext greast eleemnt and
  next where cur value is present 
   both can be presented in one HashMap : 


       */  

    }
}