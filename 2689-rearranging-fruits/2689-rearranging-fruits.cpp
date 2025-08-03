class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int n = basket1.size();
        for (int i = 0; i < n; ++i) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
        }


        vector<int> extra;
        for (auto& [val, f] : freq) {
            if (f % 2 != 0) return -1;  // odd = not possible
            for (int i = 0; i < abs(f) / 2; ++i)
                extra.push_back(val);  // half from one basket
        }

        sort(extra.begin(), extra.end());
        int smallestFruit = min(*min_element(basket1.begin(), basket1.end()),
                                *min_element(basket2.begin(), basket2.end()));


        long long cost = 0;
        for (int i = 0; i < extra.size() / 2; ++i) {
            cost += min(extra[i], 2 * smallestFruit);
        }

        return cost;
    }
};
