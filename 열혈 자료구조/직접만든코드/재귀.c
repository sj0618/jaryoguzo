#include <stdio.h>

int Search(int ar[],int first,int last,int target){
    if(first>last){
        return -1;
    }
    int mid = (first+last) /2 ;
    if(ar[mid]==target){
        return mid;
    }
    else if(target<ar[mid]){
        return Search(ar,first,mid-1,target);
    }
    else{
        return Search(ar,mid+1,last,target);
    }
}
int main(){
    int arr[]= {1,3,5,7,9};
    int idx;
    idx = Search(arr,0,(sizeof(arr)/sizeof(int))-1,7);
    if(idx==-1){
        printf("탐색 실패");
    }
    else{
        printf("%d",idx);
    }
}