#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 512




int main(int argc, char* argv[])
{
    //ensure proper usage
    if(argc != 2)
    {
       printf("Usage: ./recover image");
        return 1;
    }

    //designate file to read
    char *infile = argv[1];



    //Open Memory card file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // create buffer
    unsigned char buffer[BUFFER_SIZE];

    int fileNumber = 0;

    FILE* img = NULL;

    //set to 1 once we find first jpeg
    int found_jpeg = 0;


    while (fread(buffer, BUFFER_SIZE, 1 , inptr) ==1)
    {
        if(buffer[0] == 0xff && buffer[1]== 0xd8 && buffer[2] == 0xff &&
		(buffer[3] & 0xf0) == 0xe0)
		{
		    //if another file is already open, close that file.
		    if(found_jpeg == 1)
		    {
		        fclose(img);
		    }
		    else
		    {
		        found_jpeg = 1;
		    }
            //array for filename
            char filename[8];
		    //generate file name
		    sprintf(filename , "%03d.jpg" , fileNumber);
		    //open a new file
		    img = fopen(filename, "a");
		    //increment file number
		    fileNumber++;

		}

         if (found_jpeg == 1)
        {
	    //write block to JPEG file
	    fwrite(buffer, BUFFER_SIZE, 1, img);
        }
    }

    fclose(inptr);
    fclose(img);


    return 0;

}