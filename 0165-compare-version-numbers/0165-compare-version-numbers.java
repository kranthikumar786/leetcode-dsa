class Solution {
    public int compareVersion(String version1, String version2) {
        int i = 0, j = 0;
        int n1 = version1.length();
        int n2 = version2.length();
         while(i < n1  || j < n2) {
            int num1 = 0 , num2 = 0;
              while(i < n1 && version1.charAt(i) != '.') {
                    num1 = (num1*10) + (version1.charAt(i) -'0');
                    i++;
              }
              while(j < n2 && version2.charAt(j) != '.') {
                    num2 = (num2*10) + (version2.charAt(j) -'0');
                    j++;
              }
              if(num1 != num2) {
                  return num2 > num1 ? -1 : 1;
              }
              i++;
              j++;
         }
         return 0;
        //  String v1[] = version1.split("\\.");
        //  String v2[] = version2.split("\\.");
        //  int len = Math.max(v1.length,v2.length);
        //  for(int i = 0 ; i < len ; i++) {
        //      int num1 = i < v1.length ? Integer.parseInt(v1[i]) : 0;
        //      int num2 = i < v2.length ? Integer.parseInt(v2[i]) :0;
        //       if(num1 < num2)  return -1;
        //       if(num1 > num2) return 1;
        //  }
        //  return 0;
    }
}