#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int height;
    //Ask user for height within range
    do 
    {
        printf("height:");
        height = get_int();
    }
    while (height < 0 || height > 23);
  
    //Within range proceed making pyramid
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < height-i-1; j++)
    {
        printf("%s", " ");
    }    
    for(int k = 0; k < i+2; k++)
		{
			printf("#");
		}
		printf("\n");
	}	
	return 0;
    
}