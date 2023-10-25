/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:34:32 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:53:28 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	i = 0;
	dst2 = (char *) dst;
	src2 = (char *) src;
	if (dst == 0 && src == 0)
		return (0);
	while (i < size)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
