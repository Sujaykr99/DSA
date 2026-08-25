class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int>st ;

        for(int i = 0 ; i < operations.size() ; i++){

            if(operations[i] != "C" &&
                operations[i] != "D" &&
                operations[i] != "+"){
                st.push(stoi(operations[i])) ;
            }
            else{
                
                if(!st.empty()&&operations[i]=="C"){
                    st.pop() ;
                }
                else if(operations[i]=="D" ){
                      int temp = st.top() ;
                      temp = temp*2 ;
                      st.push(temp) ;
                }
                else{

                    int x = st.top() ;
                    st.pop() ;
                    int y = st.top() ;
                    st.push(x) ;

                    st.push(x+y) ;


                }

            }
        }
        int sum = 0 ;

        while(!st.empty()){

          int i = st.top() ;
          sum += i ;
          st.pop() ;

        }
        return sum ;
    }
};