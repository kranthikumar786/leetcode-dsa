class Solution {
public:

    int countDays(int days, vector<vector<int>>& meetings) {
            map<int, int> eventMap;
        for (const auto& meeting : meetings) {
            eventMap[meeting[0]]++;  
            eventMap[meeting[1]]--;  
        }

        int daysCount = 0, numberOfOnGoingMeeting = 0, lastMeetingDay = 0;
        for (auto [day, change] : eventMap) {
            if (numberOfOnGoingMeeting == 0) {
                daysCount += (day - lastMeetingDay - 1);
            }
            lastMeetingDay = day;
            numberOfOnGoingMeeting += change;
        }
        return daysCount + (days - lastMeetingDay);
    }
};