class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack ; 

        for(char digit : num ){
            while(!stack.empty() && k>0 && stack.top()> digit ){
                stack.pop() ; 
                k-- ; 
            }
            stack.push(digit) ; 
        }

        // remove remaining k digits from the end of the stack 
        while(k>0 && !stack.empty()){
            stack.pop() ;
            k-- ; 
        }

        // construct the resulting string from the stack // 
        string result ; 
        while(!stack.empty()){
            result += stack.top() ; 
            stack.pop() ; 
        }

        reverse(result.begin() , result.end() ) ; 

        // remove leading zeros
        size_t pos = result.find_first_not_of('0');
        result = (pos == std::string::npos) ? "0" : result.substr(pos);
        
        return result; 
    }
};