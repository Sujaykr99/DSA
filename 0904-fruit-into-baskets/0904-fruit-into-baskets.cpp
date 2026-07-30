class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int numfruits = 0;
        unordered_map<int, int> mpp;

        while (right < fruits.size()) {

            mpp[fruits[right]]++;

            while (mpp.size() > 2) {
                
                mpp[fruits[left]]-- ;

                //erase tab tak karenge jab tak window se usse type se sare fruits haat na jaye or uski frequency == 0 na ho jaye 

                if(mpp[fruits[left]]==0){
                    mpp.erase(fruits[left]) ;
                }

                left++;
            }
            numfruits  = max(numfruits,right - left + 1) ; 
            right++;
        }
        return numfruits;
    }
};