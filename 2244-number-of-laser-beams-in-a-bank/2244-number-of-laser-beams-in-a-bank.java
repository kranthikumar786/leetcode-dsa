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
        int total = 0;

        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                if (bank[row].charAt(column) == '0')
                    continue;

                for (int row1 = row + 1; row1 < rows; row1++) {
                    boolean f = false;
                    for (int column1 = 0; column1 < columns; column1++) {
                        if (bank[row1].charAt(column1) == '1') {
                            total++;
                            f = true;
                        }
                    }
                    if (f) {
                        break;
                    }
                }
            }
        }
        return total;
    }
}
