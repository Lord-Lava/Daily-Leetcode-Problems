class Bitset {
    vector<int>bit;
    int cnt;
    bool fl;
public:
    
    Bitset(int size) {
        bit.resize(size);
        cnt = 0;
        fl = false;
    }
    
    void fix(int idx) {
        if(!fl){
            if(bit[idx] == 0){
                cnt++;
                bit[idx] = 1;
            }
        }else{
            if(bit[idx] == 1){
                cnt++;
                bit[idx] = 0;
            }
        }
        
    }
    
    void unfix(int idx) {
        if(!fl){
            if(bit[idx] == 1){
                cnt--;
                bit[idx] = 0;
            }
        }else{
            if(bit[idx] == 0){
                cnt--;
                bit[idx] = 1;
            }
        }
        
    }
    
    void flip() {
        fl = !fl;
        cnt = bit.size() - cnt;
    }
    
    bool all() {
        return cnt == bit.size();
    }
    
    bool one() {
        return cnt>0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string s;
        if(!fl){
            for(auto it: bit){
                if(it == 0) s+='0';
                else s+='1';
            }
        }else{
            for(auto it: bit){
                if(it == 0) s+='1';
                else s+='0';
            }
        }
        
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */