class TopVotedCandidate {
    unordered_map<int, int>m;
    vector<int>time;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int>count;
        int lead = -1;
        time = times;
        for (int i = 0; i < persons.size(); i++) {
            count[persons[i]]++;
            if (count[persons[i]] >= count[lead])
                lead = persons[i];
            m[times[i]] = lead;
        }
    }
    
    int q(int t) {
        int val = *(--upper_bound(time.begin(), time.end(), t));
        return m[val];
    }
};
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */