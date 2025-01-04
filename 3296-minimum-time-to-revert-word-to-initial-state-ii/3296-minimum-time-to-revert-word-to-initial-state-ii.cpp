class Solution {
public:
vector<int> zFunction(string text){
       string concanatedString = text;
       int concanatedStringLength = concanatedString.size();
       vector<int>zFun(concanatedStringLength,0);
       int prefixWindowLeftPtr = 0 , prefixWindowRightPtr = 0 ;
         for(int index = 1; index < concanatedStringLength ; index++) {
                  if(index > prefixWindowRightPtr) {
                       prefixWindowLeftPtr = prefixWindowRightPtr = index ;
                       while(prefixWindowRightPtr < concanatedStringLength && concanatedString[prefixWindowRightPtr] ==  concanatedString[prefixWindowRightPtr-prefixWindowLeftPtr]) {
                               prefixWindowRightPtr++;
                       }
                      zFun[index] = prefixWindowRightPtr-prefixWindowLeftPtr; // no of chars matched with currentIndex as prefix update here 
                      prefixWindowRightPtr--; // mismatch so come back 
                  } else{
                            /*
                            now we are operating in side Window here 
                            case 1: if don't exceed the prefixWindowRightPtr 
                                            so simply copy the already computed values
                        */
                                int index1 = index - prefixWindowLeftPtr;
                                if(zFun[index1] < prefixWindowRightPtr -index + 1 ) {
                                    zFun[index] = zFun[index1]; // coping the already computed values
                                } else{
                                       prefixWindowLeftPtr = index;
                                       while(prefixWindowRightPtr < concanatedStringLength && concanatedString[prefixWindowRightPtr] == concanatedString[prefixWindowRightPtr-prefixWindowLeftPtr]) {
                                            prefixWindowRightPtr++; 
                                        }
                                        zFun[index] = prefixWindowRightPtr - prefixWindowLeftPtr;
                                        prefixWindowRightPtr--;
                                      }
            }
         }
           return zFun; 
                                /*
                                            case 2 : if does exceed the prefixWindowRightPtr
                                                re-compute the values :*/
      }
    int minimumTimeToInitialState(string word, int k) {
     vector<int> zComputed = zFunction(word);

      int wordSize = word.size() ,ans = INT_MAX;
      for(int i = 0 ; i < wordSize ; i +=k){
            if(zComputed[i] == (wordSize-i)){
                ans = min(ans,i/k);
            }
      } 
    return ans == INT_MAX ? (wordSize + k - 1) / k : ans;  
    }
};

 /*

 z- algo : 
   
   index = 1 ;  since for first char no prefix so we can initilizes with 0 :

   inorder to traveser the window or prefix search we use 
    leftPtr = 0 , rightPtr = 0 ;

   G E E K $ G E E K S F O R G E E K S

  if (index > rightPtr){ // which basically says whether i have computed or not for this index 
                            windowendptr is less then currentPtr , let's compute the next window 
                                                
                                                        move  windowstartingPtr , windowendingPtr to curretPtr 

                                                        leftPtr = rightPtr = index ;

                                                        now check for out of bounds then check for window prefix : 

                                                    while(rightPtr < conStringLength && conString[rightPtr] == conString[rightPtr - leftPtr]) {
                                                            rightptr++;; // if match move righPtr
                                                    }
                                                    
                                                    // till now we found few chars were matching as  substring of length which is also a prefix with currentPtr
                                                        zFun[currPtr] = rightPtr - leftPtr; // here no need of -1 becuase we start with 1 insted of 0 ;
                                                            
                                                        rightPtr--;   // come back to since this is mismatch
  } else{

         now i found few match so current window ending  is beyond my currPtr :
            

         1. since i have already compute the future value so i don't need to re-compuate again 
         2. even though i have caluted fre future values but few values might match with their future values and may give better resuslt then previous matches 

   
  } 


    



   "a b a c a b a"
        i       j 
    0 0 1 0 0 1 2 

    
        orignal = "abacaba" , k = 3
      
       chagingS = "abacaba" , k = 3
                   
                   "acaba" + "bac" , k = 3 : 
removed = "aba"       
     second++;
---------------------------------------
           chaingState = "acababac"

            if(chaingState == orignal) {return seconds;}

    orignal =       "abacaba"
         
    chaingState =   "cababac"   k = 3 : 
                 how close those are ..? 

                  find the oringal in chaing..?

                   how much it it matching ..? 


            orignal =       "a b a c a b a"
                                   i
            chaingState =   "c a b a b a c"
                                     j  
           
   here O = aba  is matching with C = c aba bac

   since itnot like taking one by one , it's random k value 
    
     */ 