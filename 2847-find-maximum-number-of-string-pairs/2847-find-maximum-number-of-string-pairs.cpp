class Solution {
public:
    string reverse(string str){
        int i=0;
        int j=str.size()-1;
        while(i<=j){
              swap(str[i],str[j]);
              i++;
              j--;
        }
        return str;
    }
    int count=0;
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>pair;
        for(int i=0;i<words.size();i++){
            if(words[i]==reverse(words[i])){
                if(pair.find(words[i])!=pair.end()) count++;
            }
            else if(pair.find(reverse(words[i]))!=pair.end()) count++;
            pair.insert(words[i]);
        }
        return count;
    }

};