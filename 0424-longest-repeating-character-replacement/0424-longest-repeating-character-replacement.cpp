class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxlen = 0, left = 0, right = 0, maxfreq = 0;

        int mpp[26] = {};
        

        while (right < s.size()) {

            mpp[s[right] - 'A']++;
            maxfreq = max(maxfreq,mpp[s[right] - 'A']);

            if (((right - left + 1) - maxfreq) > k) {
                mpp[s[left] - 'A']--;
                left++;
            }

            if (((right - left + 1) - maxfreq) <= k) {
                maxlen = max(maxlen, right - left + 1) ;
                
                     right++; 
                     }
            }
            return maxlen;
        
    }
};