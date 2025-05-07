#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_extract_line(char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *s1, const char *s2);
char *ft_read_to_buffer(int fd, char *leftovers);
void ft_save_leftovers(char *buffer, char *leftovers);

#endif
