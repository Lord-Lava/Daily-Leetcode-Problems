class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    
    int countVowelSubstrings(string word) {
        int n = word.size();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            unordered_set<char>vowel_set;
            int j = i;
            while(isVowel(word[j])){
                vowel_set.insert(word[j]);
                j++;
                if(vowel_set.size() == 5){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};