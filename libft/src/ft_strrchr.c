/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:05:55 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:54:52 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(char *s, int c)
{
	int				i;
	unsigned char	needle;

	i = ft_strlen(s);
	needle = (unsigned char)c;
	while (i >= 0)
	{
		if (s[i] == needle)
			return (s + i);
		i--;
	}
	return (0);
}
