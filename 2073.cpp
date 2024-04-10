class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q ; 
        for(int i = 0 ; i<tickets.size() ; i++){
            q.push(i) ; 
        }
        int timeneeded = 0 ; 
        while(!q.empty()){
            timeneeded++ ; 
            int id = q.front() ; 
            q.pop() ; 
            tickets[id]-- ; 
            
            if(k==id && tickets[id]==0 ) return timeneeded ; 
            if(tickets[id] != 0 ) q.push(id) ;
        }
 

        return timeneeded ;  
    }
};