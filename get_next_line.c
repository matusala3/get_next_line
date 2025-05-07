#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char leftovers[BUFFER_SIZE + 1];
	char *buffer;
	char *line;

	if (fd < 0)
        return (NULL);
	buffer = ft_read_to_buffer(fd, leftovers);
	if(!buffer)
		return(NULL);
	line = ft_extract_line(buffer);
	ft_save_leftovers(buffer, leftovers);
    free (buffer);
	if (!line || *line == '\0')
    {
		free(line);
        line = NULL;
        return (NULL);
    }
    return (line);
}


