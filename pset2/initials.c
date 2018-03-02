#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // ask user for input
    string s = get_string();
    
    if( s != NULL)
    {
        //Print out first intitial and Capitilize 
        printf("%c", toupper(s[0]));
        
    }
    //find and print the second initial
    
    for (int i = 1, len = strlen(s); i < len; i++)
    {
        if(isspace(s[i]))
        {
            printf("%c", toupper(s[i+1]));
        }
    
    }
    
     printf("\n");   
    
}