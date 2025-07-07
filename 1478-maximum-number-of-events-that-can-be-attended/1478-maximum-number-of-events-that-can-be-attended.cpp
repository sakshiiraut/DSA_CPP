class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());  // Sort by start day
        priority_queue<int, vector<int>, greater<int>> pq;  // min-heap for end days

        int n = events.size(), i = 0, res = 0;
        int day = 1;

        while (i < n || !pq.empty()) {
            // If no events are active, jump to next available start day
            if (pq.empty()) {
                day = events[i][0];
            }

            // Push all events starting today into the heap
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);  // push end day
                i++;
            }

            // Remove all events that have already expired
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event that ends earliest
            if (!pq.empty()) {
                pq.pop();
                res++;
                day++;
            }
        }

        return res;
    }
};
