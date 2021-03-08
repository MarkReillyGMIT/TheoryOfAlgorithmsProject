#include <stdio.h>
#include <inttypes.h>

#define W 32
#define WORD uint32_t
#define PF PRIX32
#define BYTE uint8_t

union Block
{
    BYTE bytes[64];
    WORD words[16];
};


int main(int argc, char *argv[]){

    //Iterator.
    int i;
    //The current block
    union Block B;
    
    //Section 5.1.1 - Page 11
    //Total number of bits read.
    uint64_t nobits = 0;

    //File pointer for reading
    FILE*f;
    //Open file from command line for reading
    f = fopen(argv[1], "r");

    //Number of bytes read.
    size_t nobytes;
    //Try to read bytes.
    nobytes = fread(B.bytes, 1, 64, f);
    //Tell the command line how many bytes we read.
    printf("Read %ld bytes.\n", nobytes);
    //Update of number of bits read.
    nobits += (8 * nobytes);
    //Print the 16 32-bit words.
    for (i = 0; i < 16; i++)
    {
       printf("%08" PF " ", B.words[i]);
       if (i + 1 % 8 == 0)
       {
           printf("\n");
       }
       
    }
    
    while (!feof(f))
    {

        nobytes = fread(&B.bytes, 1, 64, f);
        //Tell the command line how many bytes we read.
        printf("Read %ld bytes.\n", nobytes);
        nobits += (8 * nobytes);
        for (i = 0; i < 16; i++){
            printf("%08" PF " ", B.words[i]);
            if (i + 1 % 8 == 0)
                printf("\n"); 
        }
    }
    //Close file.
    fclose(f);
    // Print total number of bits read.
    printf("Total number of bits read %ld\n", nobits);
    
    return 0;
}