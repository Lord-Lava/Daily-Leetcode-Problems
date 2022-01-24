class node{
    public:
    int data;
    node* next;
    int min;
    node(int data,int min){
        this->data = data;
        next = NULL;
        this->min = min;
    }
};

class MinStack {
    node* Top;
public:
    MinStack() {
        Top = NULL;
    }
    
    void push(int val) {
        if(Top==NULL){
            Top = new node(val,val);
        }else{
            node* temp = new node(val,min(val,Top->min));
            temp->next = Top;
            Top = temp;
        }
    }
    
    void pop() {
        node* to_delete = Top;
        Top = Top->next;
        delete to_delete;
    }
    
    int top() {
        return Top->data;
    }
    
    int getMin() {
        return Top->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */