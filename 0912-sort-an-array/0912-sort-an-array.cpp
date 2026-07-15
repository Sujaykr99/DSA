// class Solution {
//     private : 
//     void sort(vector<int>& nums , int n ){
//         if(n==0||n ==1) return ;
//         for(int i = 0 ; i < n-1 ; i++){
//             if(nums[i]>nums[i+1]){
//                 swap(nums[i] ,nums[i+1]) ;

//             }
//         }
        
//      sort(nums , n-1) ;
//     }
// public:

//     vector<int> sortArray(vector<int>& nums) {
           
//            int n = nums.size() ;

//            sort(nums,n) ;

//            return nums ;
//     }
// }; Time Limit Exceeded




class Solution {
    private :
    void merge (vector<int>& arr , int s , int e ){
    int mid = s + (e-s)/2 ; 
    int len2 = e-mid; 
    int len1 = mid-s+1 ; 

    // create the new arr 
    int *first = new int[len1] ;

    int *second = new int[len2] ;

    // copy the array 
    int mainIndexArray = s ; 
    for (int  i = 0; i < len1; i++)
    {
        first[i]= arr[mainIndexArray++] ;
    }
     mainIndexArray = mid+1 ; 
    for (int  i = 0; i < len2; i++)
    {
        second[i]= arr[mainIndexArray++] ;

    }

    // merge 2 sorted array  
    int index1 = 0 ;
    int index2 = 0 ;
    mainIndexArray = s ; 

    while(index1< len1 && index2< len2){
        if(first[index1]<second[index2]){
            arr[mainIndexArray++] = first[index1++] ;

        }
        else {
            arr[mainIndexArray++]= second[index2++] ;
        }
    }
    while(index1<len1){
            arr[mainIndexArray++]= first[index1++] ;
    }

    while(index2<len2){
            arr[mainIndexArray++]= second[index2++] ;
    }

    delete[] first;
    delete[] second;
    
}

private :
     void mergesort (vector<int>& arr, int s , int  e ){
       //base case 
       if (s >= e) return;
       
       int mid = s +(e-s)/2 ;

       // left part 
       mergesort(arr, s , mid) ;

       //right part 
       mergesort(arr , mid+1 , e) ;

       // merge 
       merge(arr , s , e );
    }
public:
    vector<int> sortArray(vector<int>& arr) {
       int s = 0;
       int e = arr.size() - 1;

        mergesort(arr, s, e);

        return arr;

    }
};