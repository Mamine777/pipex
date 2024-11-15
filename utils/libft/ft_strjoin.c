/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:11:22 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/14 18:45:47 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	o;

	o = 0;
	while (src[o])
	{
		dest[o] = src[o];
		o++;
	}
	dest[o] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	len0;
	size_t	len1;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	len0 = ft_strlen(s1);
	len1 = ft_strlen(s2);
	size = len0 + len1;
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	ft_strcpy(tab, s1);
	ft_strcat(tab, s2);
	return (tab);
}

// #include <stdio.h>

// int main()
// {
//  	// char *s1 = "where is my ";
//  	// char *s2 = "malloc ???";

//     // char *joined = ft_strjoin(s1, s2);

// 	printf("%s\n", ft_strjoin("a", "\0"));
//     // if (joined)
//     // {
//     //     printf("%s\n", joined);
//     //     free(joined); // Free the allocated memory
//     // }
// }