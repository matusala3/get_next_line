#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(ft_strlen(s1) + 1);
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
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
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

char *ft_save_remainder(char *s)
{
    char *remainder;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (!s)
		return (NULL);
    while (s[i] && s[i] != '\n')
        i++;
    if(!s[i])
    {
		free(s);
		return (NULL);
	}
    i++;
    remainder = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
    if (!remainder)
    {
		free(s);
		return (NULL);
	}
    while (s[i])
    {
        remainder[j++] = s[i++];
    }
    remainder[j] = '\0';
	free(s);
    return remainder;
}
size_t	ft_linelen(const char *s)
{
	size_t	len;

    len = 0;
    if (!s || !*s)
		return (0);
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}
char *ft_extract_line(char *s)
{
	char	*line;
	size_t	i;
	size_t	len;

	if (!s || !*s)
		return (NULL);
	len = ft_linelen(s);
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
