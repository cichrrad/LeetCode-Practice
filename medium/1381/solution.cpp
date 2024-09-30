class CustomStack {
public:
    std::vector<int> stackVector;
    int capacity;

    CustomStack(int maxSize){
        capacity = maxSize;
    }
    
    void push(int x) {
        if(stackVector.size()<capacity){
            stackVector.push_back(x);
        }
    }
    
    int pop() {
        if(!stackVector.empty()){
            int ret = stackVector[stackVector.size()-1];
            stackVector.pop_back();
            return ret;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        k = std::min(k,(int)stackVector.size());
        for(int i = 0; i<k ; i++){
            stackVector[i] +=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
