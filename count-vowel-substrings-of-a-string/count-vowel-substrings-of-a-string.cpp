class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                map<char,int>vowels;
                for(int k=i;k<=j;k++){
                    if(word[k] == 'a' || word[k] == 'e' || word[k] == 'i' || word[k] == 'o' || word[k] == 'u'){
                        vowels[word[k]]++;
                    }else{
                        vowels.clear();
                        break;
                    }
                }
                if((int)vowels.size() == 5){
                    ans++;
                }
            }
        }
        return ans;
    }
};