#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;
	size_t len;

	i = 0;
	len = 0;
	if(!s1)
		return (NULL);
	while (s1[len] != '\0')
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);

	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s1_len = 0;
	s2_len = 0;
    if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}

    if (!s2)
    {
		free(s1);
	    return (NULL);
	}
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;
	res = malloc(s1_len + s2_len + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while(s1[j])
	{
		res[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

void ft_save_leftovers(char *buffer, char *leftovers)
{
	size_t	i = 0;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
	{
		*leftovers = buffer[i++];
		leftovers++;
	}
	*leftovers = '\0';
}

char *ft_read_to_buffer(int fd, char *leftovers)
{
	char *buffer;
	int        num_bytes_read;
	char temp_buff[BUFFER_SIZE + 1];

	num_bytes_read = 1;
	if(leftovers)
		buffer = ft_strdup(leftovers);
	else
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	while (num_bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		num_bytes_read = read(fd, temp_buff, BUFFER_SIZE);
		if (num_bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		temp_buff[num_bytes_read] = '\0';
		buffer = ft_strjoin_free(buffer, temp_buff);
		if (!buffer)
			return (NULL);
	}
	return(buffer);
}

char *ft_extract_line(char *s)
{
	char	*line;
	size_t	i;
	size_t	len;

	len = 0;
	if (!s || !*s)
		return (NULL);
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}