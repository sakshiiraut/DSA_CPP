class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stringstream ss(s);
        string word;
        string result;
        stack<string>ch;
    while (ss >> word) {  // Read words from the stream
        ch.push(word);
    }
         while (!ch.empty()) {
        result += ch.top();
        ch.pop();
        if (!ch.empty()) {
            result += " "; 
        }
    }
    return result;
  }
};