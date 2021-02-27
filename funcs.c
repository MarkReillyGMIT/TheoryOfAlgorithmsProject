#include <stdio.h>
#include <inttypes.h>

#define WORD uint32_t
#define PF PRIX32
//Creating CH function 

WORD CH(WORD x, WORD y, WORD z){

    return (x&y)^(~x&z);
}


int main(int argc, char *argv[]){

    WORD x = 0xf0f0f0f0;
    WORD y = 0xf0f0f0f;
    WORD z = 0xf0f0f0f0;

    WORD ans = CH(x,y,z);

    printf("Ch(%" PF ", %" PF ", %" PF ")=%" PF "\n", x,y,z, ans);


    return 0;
}