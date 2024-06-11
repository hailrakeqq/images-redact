#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define PNG_SIG_SIZE 8

int check_png_signature(FILE* file){
    unsigned char signature[PNG_SIG_SIZE];
    fread(signature, 1, PNG_SIG_SIZE, file);

    // HEX PNG signature: 89 50 4E 47 0D 0A 1A 0A     
    // DEC PNG signature: 137, 80, 78, 13, 10, 26, 10
    unsigned char png_signature[PNG_SIG_SIZE] = {137, 80, 78, 13, 10, 26, 10};
    for(uint8_t i = 0; i < PNG_SIG_SIZE; i++){
        if(signature[i] != png_signature[i])
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file.png>\n", argv[0]);
        return 1;
    }

    FILE *image = fopen(argv[1], "rb");
    if (!image) {
        perror("Error opening file");
        return 1;
    }

    if(!check_png_signature(image)){
        fprintf(stderr, "Not a valid PNG file\n");
        fclose(image);
        return 1;
    }


    return 0;
}