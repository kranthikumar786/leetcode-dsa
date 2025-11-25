class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
       int n1 = nums1.length;
       int n2 = nums2.length;
       int n3 = n1+n2;
       int c[] = new int[n1+n2];
       int i = 0 , j = 0 , k = 0;
        while( i < n1 && j < n2){
              if(nums1[i] < nums2[j]){
                 c[k] = nums1[i];
                  i++;
              } else{
                 c[k] = nums2[j];
                 j++;
              }
              k++;
         } 
         while(i < n1){
            c[k] = nums1[i];
            i++;
            k++;
         }
         while(j < n2) {
            c[k] = nums2[j];
            k++;
            j++;
         }
    if(n3%2 != 0){
        return (c[n3/2])*1.0;
    }
    return (c[n3/2] + c[(n3/2)-1])/2.0;
    }
}