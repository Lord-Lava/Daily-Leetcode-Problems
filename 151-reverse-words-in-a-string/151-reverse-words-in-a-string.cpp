class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        
        for(int i=0;i<s.size();i++){
            string word="";
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            if(word!=""){
                st.push(word);
            }
        }
        
        string res;
        
        while(st.size()>1){
            res.append(st.top());
            res.push_back(' ');
            st.pop();
        }
        res.append(st.top());
        st.pop();
        
        return res;
    }
};