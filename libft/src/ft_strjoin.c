/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:05:00 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:54:31 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	size_buf;

	size_buf = ft_strlen(s1) + ft_strlen(s2) + 1;
	buf = malloc(sizeof(char) * size_buf);
	if (!(buf))
		return (NULL);
	ft_strlcpy(buf, s1, size_buf);
	ft_strlcat(buf, s2, size_buf);
	return (buf);
}
