class Solution {
    public int numberOfBeams(String[] bank) {
        /**
         bank = ["011001",
                  "000000",
                  "010100",
                  "001000"]
         */

        int rows = bank.length;
        int columns = bank[0].length();
        int result = 0;
        int prevCount = 0;
        for (int row = 0; row < rows; row++) {
            int count = 0;
             for (int column = 0; column < columns; column++) {
                if (bank[row].charAt(column) == '1') {
                    count++;
                }
            }
            if (count != 0) {
                result += prevCount * count;
                prevCount = count;
            }
        }
        return result;
    }
}
