/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:31:37 by yallo             #+#    #+#             */
/*   Updated: 2023/08/29 19:52:33 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count(long int nbr)
{
	int	i;
	int	sign;

	i = 1;
	sign = 0;
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i + sign);
}

static char	*fill_array(char *buf, long int nbr, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		buf[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	buf[size] = '\0';
	return (buf);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			size;
	char		*buf;

	nbr = (long int)n;
	size = count(nbr);
	buf = malloc(sizeof(char) * size + 1);
	if (!(buf))
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		fill_array(buf, nbr, size);
		buf[0] = '-';
	}
	else
		fill_array(buf, nbr, size);
	return (buf);
}
