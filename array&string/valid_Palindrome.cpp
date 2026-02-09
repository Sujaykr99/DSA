// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105

#include <string>

class Solution {
    private:
     bool valid(char ch ){
        if((ch>= 'a' && ch<= 'z')|| (ch>='A'&& ch <= 'Z')|| (ch>='0' && ch<= '9')){
            return 1 ;
        }

         else 
         return 0 ;

     }
public:
    bool isPalindrome(std::string s) {

        int i = 0 ;
        std::string temp = "" ;

        for(int j = 0 ; j< s.length() ; j++){
            if(valid(s[j]))
{
                temp.push_back(s[j] ) ;
            }
        }
        for(int j =0 ; j<temp.length(); j++){
                      temp[j] = tolower(temp[j]) ;
        }
       
       int b = 0 ;
       int e = temp.length()-1 ; 
       while(b<e){
        if(temp[b] != temp[e])
{
            return 0 ;
        }
        else{ 
              b++ ;
              e-- ;}
       }
        return true ;
    }
};