#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }


    char *infile = argv[1];


    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }


    unsigned char buffer[512];


    int jpeg_count = 0;


    char jpeg_name[8];


    FILE *outptr;

    while (fread(buffer, 512, 1, inptr) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (jpeg_count > 0)
            {

                fclose(outptr);
            }


            sprintf(jpeg_name, "%03i.jpg", jpeg_count);


            outptr = fopen(jpeg_name, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", jpeg_name);
                return 3;
            }


            fwrite(buffer, 512, 1, outptr);


            jpeg_count++;
        }
        else
        {

            if (jpeg_count > 0)
            {

                fwrite(buffer, 512, 1, outptr);
            }
        }
    }


    fclose(outptr);
    fclose(inptr);

    return 0;
}
