class Solution {
public:
    string largestOddNumber(string num) {
         int n = num.size();
        while (n > 0) {
            int digit = num[n - 1] - '0';
            if (digit % 2 != 0) {
                return num.substr(0, n);
            }
            n--;
        }
        return "";
    }
};