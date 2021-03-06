#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int lengthOfLongestSubstring(char *s){
    int offset[128];
    int max_len = 0;
    int len = 0;
    int index = 0;

    memset(offset,0xff,sizeof(offset));
    while(*s != '\0'){
        if(offset[*s] == -1){
            len++;
        }else{
            if(index - offset[*s] > len){
                len++;
            }else{
                len = index - offset[*s];
            }
        }
        if(len > max_len){
            max_len = len;
        }
        offset[*s++] = index++;
    }
    return max_len;
    
}

int main(int argc, char const *argv[])
{
    printf("%d\n", lengthOfLongestSubstring("moring"));
    return 0;
}
