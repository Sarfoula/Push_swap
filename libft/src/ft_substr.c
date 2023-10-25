/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:30:40 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:54:58 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;

	if (start > ft_strlen(s) + 1)
	{
		start = ft_strlen(s) + 1;
		len = 0;
	}
	else if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	buf = malloc(sizeof(char) * len + 1);
	if (!(buf))
		return (NULL);
	ft_memcpy(buf, &s[start], len);
	buf[len] = '\0';
	return (buf);
}
