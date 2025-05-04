#include "get_next_line.h"


char *get_next_line(int fd)
{
    static char *leftover;
    char *buffer;
    ssize_t bytes_read;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(leftover, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        leftover = ft_strjoin_free(leftover, buffer);
        if (!leftover)
        {
            free(buffer);
            return (NULL);
        }
    }
    line = ft_extract_line(leftover);
    leftover = ft_save_remainder(leftover); 
    free(buffer);

    if (!line || *line == '\0')
    {
        free(leftover);
        leftover = NULL;
        return (NULL);
    }

    return (line);
}


