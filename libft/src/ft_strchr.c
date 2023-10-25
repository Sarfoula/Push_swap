/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:33:31 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:54:00 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(char *s, int c)
{
	size_t			i;
	unsigned char	needle;

	i = 0;
	needle = (unsigned char)c;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == needle)
			return (s + i);
		i++;
	}
	return (NULL);
}
