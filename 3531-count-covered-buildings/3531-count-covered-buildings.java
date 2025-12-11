class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {

        HashMap<Integer, int[]> rowMap = new HashMap<>();
        HashMap<Integer, int[]> colMap = new HashMap<>();

        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            rowMap.putIfAbsent(y, new int[]{x, x});
            rowMap.get(y)[0] = Math.min(rowMap.get(y)[0], x);
            rowMap.get(y)[1] = Math.max(rowMap.get(y)[1], x);

            colMap.putIfAbsent(x, new int[]{y, y});
            colMap.get(x)[0] = Math.min(colMap.get(x)[0], y);
            colMap.get(x)[1] = Math.max(colMap.get(x)[1], y);
        }

        int count = 0;

        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            int minX = rowMap.get(y)[0];
            int maxX = rowMap.get(y)[1];
            int minY = colMap.get(x)[0];
            int maxY = colMap.get(x)[1];

            boolean left  = minX < x;
            boolean right = maxX > x;
            boolean down  = minY < y;
            boolean up    = maxY > y;

            if (left && right && up && down) {
                count++;
            }
        }

        return count;
    }
}



// class Solution {
//     public int countCoveredBuildings(int n, int[][] buildings) {
//      HashMap<Integer,Integer>hm = new HashMap<>();
//      for(int building[] : buildings) {
//         hm.put(buildings[0],buildings[1]);
//      }
//      int cnt = 0;
//       for(for(int building[] : buildings) {
//           int cbx =  building[0];
//           int cby =  building[1];
//           boolean l = r = t = d = false;
//           if(cbx+1 && cby+1){
//              l = true;
//           } 
//           if(cbx-1 && cby-1){
//              r = true;
//           }
//           if(cbx+1 && cby-1){
//              d = true;
//           }
//           if(cbx-1 && cby+1){
//              t = true;
//           }

//        if(t&d&r&l){
//         cnt++;
//        }
//     }
//     return cnt;
// }

