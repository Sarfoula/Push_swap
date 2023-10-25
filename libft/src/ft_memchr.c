/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:33:26 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:53:21 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *haystack, int needle, size_t size)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	n;

	i = 0;
	str = (unsigned char *)haystack;
	n = (char)needle;
	while (i < size)
	{
		if (str[i] == n)
			return (str + i);
		i++;
	}
	return (NULL);
}
