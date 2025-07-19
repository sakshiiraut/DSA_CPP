class Solution {
public:
   string reverse(string word){
    int i=0;
    int n=word.size();
    int j=n-1;
    while(i<=j){
        char temp=word[i];
        word[i]=word[j];
        word[j]=temp;
        i++;
        j--;
    }
    return word;
   }
    string reverseWords(string s) {
      string reversedString = reverse(s);  // reverse the full string
        string word = "";
        string ans = "";
        int n = reversedString.size();

        for (int i = 0; i <= n; ++i) {
            // If current character is space or end of string
            if (i == n || reversedString[i] == ' ') {
                if (!word.empty()) {
                    ans += reverse(word) + " ";
                    word = "";
                }
            } else {
                word += reversedString[i];
            }
        }

        // Remove trailing space if exists
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};
