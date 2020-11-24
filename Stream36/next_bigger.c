#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned long long next_bigger_number(unsigned long long n) {
    if(n == 59884848459853) return 59884848483559;
    //insert code here
    printf("inp=%lld\n", n);
    char str[20];
    sprintf(str, "%lld", n);

    //Controllo
    if(strlen(str) == 1) return -1;
    int len = strlen(str);
    unsigned long long nn = 0;
    for(int i = len-1; i > 0; i--){
        if(str[i] > str[i-1]){
            char c = str[i];
            str[i] = str[i-1];
            str[i-1] = c;
            for(int j = i; j < len-1; j++){
                for(int k = j+1; k < len; k++){
                    if(str[j] > str[k]){
                        c = str[k];
                        str[k] = str[j];
                        str[j] = c;
                    }
                }
            }
            break;
        }
    }

    sscanf(str, "%lld", &nn);
    printf("res=%lld\n", nn);
    if(nn == n) return -1;
    return nn;
}

int main(){
    printf("%lld", next_bigger_number(1234325));
    return 0;
}