class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        std::vector<int> ans;
        
        //split at each operator (ignore numbers)
        //-> proccess left and right part of expression
        for(unsigned int i = 0; i<expression.size() ; i++){
            char op = expression[i];
            if(op == '+' ||
               op == '-' ||
               op == '*' ){
                
                //process left and right string recursively
                std::vector<int> l = diffWaysToCompute(expression.substr(0,i));
                std::vector<int> r = diffWaysToCompute(expression.substr(i+1));

                //perform operation on all combinations
                for(const int& a : l){
                    for(const int& b:r){
                        if(op == '+'){
                            ans.push_back(a+b);
                            continue;
                        }
                        
                        if (op == '-'){
                            ans.push_back(a-b);
                            continue;
                        }
                        ans.push_back(a*b);

                    }
                }
            }
        }
        //edge case -> only 1 number
        if (ans.empty()){
            ans.push_back(std::stoi(expression));
        }
        return ans;
    }
};
