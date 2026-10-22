class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end()) ;

        priority_queue<int>pq(s.begin() ,s.end()) ;

        if(pq.size()<=2) {
            return pq.top() ;
            }

         int a ;
    
            pq.pop() ;;
            pq.pop() ;
            
            a = pq.top() ;
        
        
        return a ;
    }
};