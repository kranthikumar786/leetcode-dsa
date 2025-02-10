/**
   Missing follow up  Question   for that  i started wrting unncessary code: 
   a1b2c3 : 
   always  left to digit non-digit char present ...? always : 
   so we can avoid of checking :  isChar () 

   //    public boolean isChar(char c) {
//          return (c >= 'a' && c <= 'z');
//      } 

Q5)  if we are dealing with adjacnets check how it always : 
          ex : in this probelm : a2 , in test case : if i is digit then i-1 is always a char : if i-1 is present : 
             without this testcase i have wriiren some unncesssay code as well : 

--------------------------------------------------------------
    getting lastIndex for every time is not best performance code :
    since all may not be digits so  not using is properly : 
    int charLastIndex = sb.lenght()-1: 
 ---------------------------------------------
here : 
  my first logic for checking was 
    int charvalue = char - '0';
     return ( charvalue >= 0 && charvalue <= 9) :
     This works and  but not best for this case  however  if i want to do some basic artherimetic operations    with charValue like :  sum the digits present in string best for those cases : 
         but here our  use case is simplt check and no need of  converting so : 
         here scenario is different  simply use it like below : 
   public boolean isDigit(char c ){
         return (c >= '0' && c <= '9');
    }
=================================================================================
New Learning : 
 Character  wrapper class can help to avoid wrting manual code: 
Character.isDigit(c))
---------------------------------
 StringBuilder != to stirng :
so sb.toString() shold be used :
------------------------------------- 
sb.deleteCharAt(sb.length()-1); delete  : O(n)
----------------------------------------
ab.append(c) : adding or creating  new eleemnt  - O(n) incase of resizing :  
--------------------------------------------------
sb.charAt(index) : check  or search :  O(1)
-------------------------------------------------
sb.insert(index, c) :  to update the value: O(1) 
-------------------------------------------------------------
aaaaaaaaaaaaaaaaa12345678901234567
in this test case : i have to resize the strngBuilder to appedn a char : 
  TC : O(n) :
if all test case are bigger like this : 

  in worst case of lentht 100 all can be chars : so i have append all of them : 
     = 100/16 : 
      6.25 times size resizing which is acceptable  so fine : 
      using of it : 
    This How StringBuilder Resizes Its Internal Buffer
    newCapacity = (oldCapacity * 2) + 2;

  or 
    else use 
       StringBuilder sb = new StringBuilder(101);
       is also works while takeing TC is higher propeorty over Space Complexity for large  test cases : 
 StringBuilder sb = new StringBuilder(1000); // Preallocate space for 1000 characters  



 */
class Solution {
    public String clearDigits(String s) {
      StringBuilder sb = new StringBuilder();
      for(char c : s.toCharArray()){
    sb = ((Character.isDigit(c) && sb.length() > 0 ) ? 
             sb.deleteCharAt(sb.length()-1) :
              sb.append(c));
      }      
     return sb.toString(); 
}
}
      /**
-----------------------------
 Common Stirng test cases : 
   singel string as input : 
    1) ""  -> empty stirng  : best case for TC & SC : 
    2) "a" -> single char :  
    3) "ab" - > even lenght stirng :  any dependec on ans :  like palindrome:
    4) "abc" -> odd length stirng : any depedence on ans : like palindrome  
    
      edge case : 
      corner case : 


  Output related Questions : 

     1) answer always existings ..? :
     2) if exist : single answer present or multple answer presnet then what to retun
       like first one or secocond  or thire comes first etc...
       if no answer what to retuen ..? 
    all Follwup quesiont  of single stirn as input then 
      mulplt stirng as input :
        relation b/w stirng like :
          s1 == s2  : anagram v.imp base condtion :
           or s1 > s2   how to treat : ex edit diasnce  simply return remaing string letnth
            or 
            s1 < s2   : how to treat here as well : 
  once your coding logic is correct: 

  1) modulizerd code : 
  2) readbile code : 
  3) performance : 
  4) effciency code :
  5) using less memory code  :
  6) single pass code : 
  7) how good are you at using pre-defined methods :

Performnace based    TC  : 
  followu p Questions : 
      TC: 
     best case  tc : 
     avg case tc : 
      worst case tc :
     SC : 
     best case sc : 
     avg case sc : 
     worst case sc :  
 ----------------------
    mulplt stirng as input :




------------------------------

      "a234" :
      "aaa4":

      123
      bac123:
        c1 
        ba23 : 
        a2 
        b3 : 
        "" : 
       bac112 : 

  all digits possible..? only digits and no no-pdigit chars in string :
    Stack<Character > st= new Stack<>() ;


  boolean isChar(char c) {
      return (c >= 'a' && c <= 'z');
  }
  boolean isDigit(char digit) {
     return ((digit -'0' >= 0) && (digit -'0' <= 9));
  }
     for( char c : s) {
          if(!st.empty() || isChar(s.peek())){
               s.pop();
          } else{
            st.push(c);
          }
     }
     

    string ar immutable so can't use directly ; 
    even size alos not fixed : how much will reamins ans how much will be delted : 
    so use  string bufffer if want to do wihtout stack and use buffered string as stack and operations : 
  

    ---------------
     count appproach : using varibles only : 


       */  
    