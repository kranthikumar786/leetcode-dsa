class Solution {
public:
vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> res;
    vector<int> count(10, 0);
    for (int d : digits) count[d]++;
    
    for (int i = 100; i <= 999; i += 2) {
        int h = i / 100;
        int t = (i / 10) % 10;
        int o = i % 10;
        count[h]--; count[t]--; count[o]--;
        if (count[h] >= 0 && count[t] >= 0 && count[o] >= 0)
            res.push_back(i);
        count[h]++; count[t]++; count[o]++;
    }

    return res;
}
};