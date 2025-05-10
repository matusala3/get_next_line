/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:52:52 by magebreh          #+#    #+#             */
/*   Updated: 2025/05/07 16:12:23 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Duplicates a string by allocating new memory.
 *
 * @param s1 Input string to duplicate.
 * 
 * @return Pointer to the newly allocated duplicate string,
 *         or NULL if input is NULL or allocation fails.
 */
char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!s1)
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

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * @param s Input string to search in.
 * @param c Character to find, passed as int but treated as char.
 * 
 * @return Pointer to the first occurrence of c in s,
 *         or pointer to null terminator if c is '\0',
 *         or NULL if not found or input is NULL.
 */
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
/**
 * @brief Calculates the length of a string.
 *
 * This function counts the number of characters in the given string
 * until it reaches the null terminator '\0'.
 *
 * @param s The input string to measure.
 * @return The number of characters in the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * This function copies n bytes from the memory area pointed to by src
 * to the memory area pointed to by dest. The memory areas must not overlap.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	unsigned char		*s2;

	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (dest);
}

/**
 * @brief Extracts a string until and including '\n' if present.
 * 
 * @param s Input string to extract the line from.
 * @return Newly allocated string with the extracted line.
 *         NULL if input is NULL, empty, or allocation fails.
 */
char	*ft_extract_line(char *s)
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
