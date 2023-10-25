/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:45:07 by yallo             #+#    #+#             */
/*   Updated: 2023/10/24 11:38:43 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	first(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static int	last(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (set[i] != '\0')
	{
		if (s1[j] == set[i])
		{
			i = 0;
			j--;
		}
		else
			i++;
	}
	return (j + 1);
}

static char	*fill_array(char const *s1, char const *set, char *buf)
{
	int	i;
	int	j;

	i = first(s1, set);
	j = 0;
	while (i < last(s1, set))
	{
		buf[j] = s1[i];
		j++;
		i++;
	}
	buf[j] = '\0';
	return (buf);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*buf;

	size = last(s1, set) - first(s1, set) + 1;
	if (size <= 0)
		size = 1;
	buf = malloc(sizeof(char) * size);
	if (!(buf))
		return (NULL);
	fill_array(s1, set, buf);
	return (buf);
}
