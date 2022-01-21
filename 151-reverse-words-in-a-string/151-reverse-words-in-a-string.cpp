class Solution {
public:
    string reverseWords(string str) {
       stack<string>st;  

        int size = str.size();     

        for(int i = 0; i< size ;i++){ 
            string word=""; 
            while(i<size && str[i]!=' '){
                word+=str[i];
                i++;
            }
            if(word!="")
                st.push(word);
        }

        string res;
        while(st.size() != 1){ 
            res.append(st.top());
            res+=' ';
            st.pop();
        }
        res.append(st.top()); 
        return res;  
    }
};