#include "../include/functions.h"
#include <stdio.h>
#include <math.h>

void funcB(long int x){
    int n = sqrt(x);
    int simple = 1;

    if ((x == 0) || (x == 1)){
        printf("%s %ld %s", "Number", x, "is not simple and not composite");
    } else {
    
    if (x % 2 == 0){
        simple = 0;
    } else {
        
        for (int i = 3; i <= n; ++i){
        if ((x % i == 0) || (x % (x / i) == 0)){
            simple = 0;
            break;
        }
    }
    }
    
    if (simple) {
        printf("%s %ld %s", "Number", x, "is simple");
    } else {
        printf("%s %ld %s", "Number", x, "is composite");
    }
}
}