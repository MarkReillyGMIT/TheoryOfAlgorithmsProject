#include <stdio.h>

void bin_print(unsigned int i){
    // Number of bits in an integer
    int j = sizeof(int) * 8;

    // Temporary variable
    int k;

    // Loop over the number of bits in i.
    for(j--; j >=0; j--){
        //
        k = ((1 << j ) & i) ? 1 : 0;
        // Print k.
        printf("%d", k);

    }
}


// Standard main signiture.
int main(int argc, char *argv[]){
    //set i to literal value
    unsigned int i = 0x0f0f0f0f;//1;//0xf1;//241

    //What we're printing
    printf("Original: \t");
    // Print i in binary.
    bin_print(i);
    //End Line
    printf("\t%x\t%u\n\n", i, i);
    
    //32
    int j = sizeof(unsigned int) * 8;

    for(j--; j>0; j--){
        // 1 shifted left j times.
        bin_print(1 << j);printf("\n");
        //i
        bin_print(i); printf("\n");
        printf("-------------------------------- &\n");
        // (1 shifted left j times) bitwise logical and i.
        bin_print((1<<j)& i); printf("\n\n");
    }
    //Everything is ok, if returned zero.
    return 0;
}
