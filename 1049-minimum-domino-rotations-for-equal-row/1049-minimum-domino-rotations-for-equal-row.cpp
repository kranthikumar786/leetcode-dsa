class Solution {
public:
    int check(int x, vector<int>& A, vector<int>& B) {
        int rotationsA = 0, rotationsB = 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] != x && B[i] != x) {
                return -1;
            } else if (A[i] != x) {
                rotationsA++;
            } else if (B[i] != x) {
                rotationsB++;
            }
        }
        return min(rotationsA, rotationsB);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1 || tops[0] == bottoms[0]) return result;
        return check(bottoms[0], tops, bottoms);
    }
};


// class Solution {
// public:
//     int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         int n = tops.size();
//        if(n == 1) {return 0;}
//        int ansT = 0;
//        int ansD = 0;
//          int topV = tops[0];
//          int bottomV = bottoms[0];
//        for(int i = 1 ;i < n ;i++) {
//             if(topV == tops[i] || bottomV == bottoms[i]) {

//             } else{
//                 swap(tops[i], bottoms[i]);
//                  if(topV == tops[i] || bottomV == bottoms[i]) {
//                    ansT++;
//                    swap(tops[i], bottoms[i]);
//                } else{
//                   return -1;
//                }
               
//             }
//        }
//        cout<<ansT<<"\n";

//          bottomV = tops[0];
//          topV = bottoms[0];
//        for(int i = 1 ;i < n ;i++) {
//             if(topV == tops[i] || bottomV ==  bottoms[i]) {
//                   cout<<"kbdfsjb";
//             } else{
//                 swap(tops[i], bottoms[i]);
//                  if(topV == tops[i] || bottomV == bottoms[i]) {
//                    ansD++;
//                } else{
//                   return -1;
//                }
//             }
//        }
//        cout<<ansD<<":\n";
//       return min(ansD,ansT); 


// // tops =    [2,1,2,4,2,2], 
// // bottoms = [5,2,6,2,3,2]
           

//  // tops =   [2,5,5,5,5,5], 
// // bottoms = [5,2,2,2,2,2]
   




//              /*swap () :   an ddon;t swap :
               
//                  if topvall = =top[i]  move ahead: 

//                   if(bottomvalue == bottom[i])  move ahed: 

//                      else swpa ()
//                        recheck : 
//                        if not matcihng
//                         retuinr1-;1  
             
//              */
// //            2 2 2 2 2 2
// //            5 1 6 4 3 2
              
// //            either 2 or 5 : 
// //    approach : 

// //      maintina two ptrs: 
// //     possiblites : tops[0] , bottoms[0] : 

// //        same or not same: 
// //        tops[1] == topvalue ..? 
// //                      or 
// //        bottoms[1] == topvalue ..?                


// // [3,5,1,2,3], bottoms = 
// // [3,6,3,3,4]

// //   return false at index 1 : 

        

//     }
// };