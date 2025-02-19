class Solution {
    int count = 0;
    String ans = "";
    public void generateHappyStrings(StringBuilder comb, int n, int k) {
        if (comb.length() == n) {
            count++;
            if (count == k) {
                ans = comb.toString();
            }
            return;
        }
        for (char c = 'a' ; c < 'd' ; c++) {
            if (comb.length() > 0 && comb.charAt(comb.length() - 1) == c) {
                continue;
            }
            comb.append(c);
            generateHappyStrings(comb, n, k);
            comb.deleteCharAt(comb.length() - 1); 
        }
    }
    public String getHappyString(int n, int k) {
        generateHappyStrings(new StringBuilder(), n, k);
        return ans;
    }
}

     



     /**
     
       
    use abc as source and genrate all possbile n size permutaions ...? 
    and then chose kth one 
      example : 
      n = 1: k = 3:
      a 
      b 
      c 

      ex2 : 

      a 
      b 
      c 
      ab  ;  k = 4 :
      4th : is ab whishi is length == 2 not 1 so don't genrate length 2 return empty



       n = 3 :  k = 9 : 
       n = 1 :   n = 2 :               
       a           ab
       b           ac  
       c           bc 
                   ca 
                   ba
                   cb :
                   order does mattter ..? yes : 



    n = 3 : 
     aba  1
     abc 2
     aca 3
     acb 4
     bab 5
     bac 6 
     bca 7
     bcb 8
     cab 9
     cac 10
     cba 11
     cbc 12 
             rec(i,combincation){
                 if(i+1 < 3 && combination[i] == combinations[i+1]){return;}
                  if(combinations.length == 3){
                     list.push_back(combinations);
                  }
                  if(combinations.length > 4){return;}
       string input = "abc" ;
       for(int i = 0; i < inut.size() ;i++) {
             combination += input[i]; // aaa  :
          rec(i,comobition);
       }
    chocie of elemts like : 1 place is fixed then swap remaing places wiht remaing chars and chsck  the adjusts are not same  :
     
    as per my logic abc will genrate first but expaction is aba since lexigraphicall smallest one 
 ...? 
       abc : 


      */   