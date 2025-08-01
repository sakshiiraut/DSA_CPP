class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;     // Final unique OR values
        unordered_set<int> prev;       // ORs ending at previous index

        for (int num : arr) {
            unordered_set<int> curr;
            curr.insert(num);

            for (int val : prev) {
                curr.insert(val | num);
            }

            for (int val : curr) {
                result.insert(val);
            }

            prev = curr;  // Move to next index
        }

        return result.size();
    }
};
