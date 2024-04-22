#include <stdio.h>
int Search(int ar[],int len,int target){

    int first = 0;
    int last = len-1;
    int mid; //가운데 값.

    while (first <= last)               //first가 last보다 작거나 큰 동안.
    {
        mid = (first+last)/2;

        if (target == ar[mid])
        {
            return mid;                 //mid가 찾는값이면 끝
        }
        else
        {
            if(target < ar[mid]){       //
                last= mid - 1;
            }
            else{
                first = mid +1;
            }
        }
    }
return -1;
}
int main(){
    int arr[]= {1,3,5,7,9};
    int idx=0;

    idx = Search(arr,sizeof(arr)/sizeof(int),1);
    if(idx== -1)
        printf("탐색실패\n");
    else
        printf("타겟저장인덱스:%d\n",idx);
    
    return 0;
}