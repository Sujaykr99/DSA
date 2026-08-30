class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int left = 0;
        int right = 0;

        int freq1[26] = {}; // isme s1 ke char jaiga
        int freq2[26] = {};

        for (int i = 0; i < s1.size(); i++) {

            freq1[s1[i] - 'a']++;
        }

        while (right < s2.size()) {

            freq2[s2[right] - 'a']++;

            int window = right - left + 1;

            if (window == s1.size()) {

                bool match = true;

                for (int i = 0; i < 26; i++) {

                    if (freq1[i] != freq2[i]) {

                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }

                freq2[s2[left] - 'a']--;
                left++;
            }

            right++;
        }

        return false;
    }
};