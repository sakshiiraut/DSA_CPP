class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;  
        for (int num = low; num <= high; ++num) {
            string s = to_string(num);
            int n = s.length();         
            if (n % 2 != 0) continue;         
            int half = n / 2;
            int leftSum = 0, rightSum = 0;
            for (int i = 0; i < half; ++i) {
                leftSum += s[i] - '0';
                rightSum += s[i + half] - '0';
            }
            if (leftSum == rightSum) {
                count++;
            }
        }
        return count;
    }
};
