#include <stdio.h>
int Factorial(long long num){
    if (num <=0){
        return 1;
    }
    else{
        return num * Factorial(num-1);
    }
}
long long main(){
    long long a = Factorial(9);
    printf("%lld\n",a);
    return 0;
}