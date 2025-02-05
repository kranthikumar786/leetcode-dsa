class Solution {
    public int minimumRounds(int[] tasks) {
     Map<Integer,Integer>freMap = new HashMap<>();
   for(int task : tasks) {
    freMap.put(task, freMap.getOrDefault(task,0)+1);
   }
    int ans = 0;
  for(Map.Entry<Integer,Integer>map : freMap.entrySet()) {
      int fre = map.getValue();
      if( fre== 1) {
         return -1;
      }
       if(fre %3 == 0) {
          ans += fre/3;
       } else{
        ans += fre/3 +1;
       }
  } 
return ans;

        /**
        [2,2,3,3,2,4,4,4,4,4]
         thinking to sort first : the all  difficuly level Question comes to one place
         [2,2,2,3,3,4,4,4,4,4] : 

         2 o r 3 :
         chosen max : 
      priorityQueue : 
         min elelement :
         two indeiex : 
         leftptr : and 
         rightptr : 
           if frequncey == 1 : then return -1  :

            if(fequncy == 3) 
             {
                 move leftPtr = right+1; 
                  right++;
                  cnt++;
             } else if( rightptr - leftptr >= 3 && fruence == 2) {
                 move leftPtr = right+1; 
                  right++;   
                  cnt++;
             } else if(frequncy == 1 && righPtr - leftPtr > =2){
                  return -1;
             }  
    return noOfRounds; 


    TC : O(nlogn)
    SC: O(1) :
    ------------
      order of eleemnt not matter so using frequncy aarray might helps : 
  
         4,4,4,4,4 
         4- > 5 
         if(fre != 1){
         if fre > = 5 
              ans += fre/5 + fre%5 : 
         if fre == 3  || freq == 2 
            round++;   
        } 
        else if (fr == 1) {
           return -1;
        }


          Map<Integer, Integer> M = new HashMap<>();
         int n = tasks.length;
        for(int i = 0 ; i < n ; i++) {
           M[tasks[i]]++;
        }
       int ans = 0; 
    for(Map.Entry<Integer,Integer>map : M.entrySet()) {
          if(M.getValue() == 1) {
             return -1;
          }
        int fe = M.getValue();
        ans += ((fe/5) + (fe%5));
       if(fe%2 != 0 || fe%3 != 0 || fe%5 != 0){return -1;}
    }  
return ans;
        tc : O(n)
        sc :O(n) :
         */
    }
}