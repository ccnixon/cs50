#include <stdio.h>
#include <string.h>
#include <stdint.h>
const int BLOCK_SIZE = 512;

int main(void)
{
    FILE* file = fopen("card.raw", "r");
    
    if (file == NULL)
    {
        fclose(file);
        printf("Error reading file\n");
        return 1;
    }
    
    int filenumber = 0;
    FILE* outfile = NULL;
    uint8_t buffer[BLOCK_SIZE];
    
    while(fread(buffer, BLOCK_SIZE, 1, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            
            char filename[8];
            sprintf(filename, "%03d.jpg", filenumber);
            
            outfile = fopen(filename, "w");
            
            filenumber++;
        }
        
        if (outfile != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    
    if (outfile != NULL)
    {
        fclose(outfile);
    }
    
    fclose(file);
    return 0;
    
}