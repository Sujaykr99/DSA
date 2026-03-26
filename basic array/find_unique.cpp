#include<iostream>
using namespace std ;
int findunique(int *arr , int n ){
    int ans = 0 ;
    for(int i = 0 , i <arr.size() ,i++){
        ans = ans ^ arr[i] ;
    }
    return ans ;
    
}

int main(){
    int arr[] = {1, 2, 3, 2, 1} ;
    int n = sizeof(arr) / sizeof(arr[0]) ;
    cout << findunique(arr, n) ;
    return 0 ;
}
