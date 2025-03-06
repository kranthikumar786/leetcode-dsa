class Solution {
public:
    #define SIZE 40  // 40 * 64 = 2560 bits (enough for 2500)
    long long bits[SIZE] = {0};      
    int duplicate = -1, missing = -1;

    void setNumber(int n) {
        int index = (n - 1) / 64;
        int pos = (n - 1) % 64;
        
        if (bits[index] & (1LL << pos)) {
            duplicate = n;  
        } else {
            bits[index] |= (1LL << pos);  
        }
    }

    bool isSet(int n) {
        return bits[(n - 1) / 64] & (1LL << ((n - 1) % 64));
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int range = n * n;
        memset(bits, 0, sizeof(bits)); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                setNumber(grid[i][j]);
            }
        }

        for (int i = 1; i <= range; i++) {
            if (!isSet(i)) {
                missing = i;
                break;
            }
        }

        return {duplicate, missing};
    }
};
