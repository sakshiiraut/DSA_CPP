class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> alternating(n, 0);

        // Step 1: Precompute alternating array
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;  // Circular index
            if (colors[i] != colors[next]) {
                alternating[i] = 1;
            }
        }

        // Step 2: Compute initial window sum
        int count = 0;
        int altSum = 0;
        for (int i = 0; i < k - 1; i++) {
            altSum += alternating[i];
        }

        // Step 3: Slide through array using modular indexing
        for (int i = 0; i < n; i++) {
            int exitIdx = (i - 1 + n) % n;  // Element leaving window
            int enterIdx = (i + k - 2) % n; // New element entering window

            if (i > 0) {
                altSum -= alternating[exitIdx]; // Remove old
                altSum += alternating[enterIdx]; // Add new
            }

            // Valid alternating group if sum is exactly (k - 1)
            if (altSum == k - 1) {
                count++;
            }
        }

        return count;
    }
};
