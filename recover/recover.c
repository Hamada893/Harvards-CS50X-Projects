#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define JPEG_HEADER_SIZE 4

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }
    unsigned char buffer[BLOCK_SIZE];
    FILE *output = NULL;
    int jpegCount = 0;
    char filename[8];

    while (fread(buffer, sizeof(unsigned char), BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            if (output != NULL)
            {
                fclose(output);
                output = NULL;
            }
            sprintf(filename, "%03d.jpg", jpegCount);
            output = fopen(filename, "w");
            if (output == NULL)
            {
                printf("Could not create %s.\n", filename);
                return 3;
            }
            jpegCount++;
        }
        if (output != NULL)
        {
            fwrite(buffer, sizeof(unsigned char), BLOCK_SIZE, output);
        }
    }
    if (output != NULL)
    {
        fclose(output);
    }
    fclose(input);

    return 0;
}
