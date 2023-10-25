/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:03:32 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:52:17 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buf;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	buf = malloc(count * size);
	if (!(buf))
		return (NULL);
	ft_bzero(buf, size * count);
	return (buf);
}
