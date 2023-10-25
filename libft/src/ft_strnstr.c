/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:21:30 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:54:49 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(char *str, const char *needle, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return (str);
	while (str[i] && i <= size)
	{
		j = 0;
		while (str[i + j] == needle[j] && str[i + j])
			j++;
		if (j == ft_strlen(needle) && i + j <= size)
			return (str + i);
		i++;
	}
	return (NULL);
}
