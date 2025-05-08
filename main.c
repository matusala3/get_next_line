#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"  

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
 
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("%s", line);  
    //     free(line);
    // }
    // if (line == NULL)
    //     printf("NULL");
    //now call the get_next_line function only 3 times
    for (int i = 0; i < 3; i++)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            printf("No more lines to read or error occurred.\n");
            break;
        }
        printf("LINE: %s", line);  
        free(line);
    }

    close(fd);
    return (0);
}
