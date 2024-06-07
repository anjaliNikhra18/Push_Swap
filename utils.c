/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:29:33 by aneekhra          #+#    #+#             */
/*   Updated: 2024/03/14 17:26:40 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *av)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (av[i] == '+')
		i++;
	else if (av[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (is_digit(av[i]))
	{
		num = (num * 10) + (av[i] - '0');
		i++;
	}
	return (num * sign);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		len = 0;
	else if ((len + start) > l)
		len = l - start;
	sub = (char *)malloc((len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && j < l)
	{
		sub[i] = s[j];
		i++;
		j++;
	}
	sub[i] = '\0';
	return (sub);
}

int	count_words(const char *argv, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*argv)
	{
		if (*argv != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*argv == c)
			trigger = 0;
		argv++;
	}
	return (i);
}

char	**ft_get_str(char **str, int index, char *argv, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(argv))
	{
		if (argv[i] != c && index < 0 && i != ft_strlen(argv))
			index = i;
		else if ((argv[i] == c || i == (ft_strlen(argv))) && index >= 0)
		{
			str[j++] = ft_substr(argv, index, (i - index));
			if (!str[j - 1])
			{
				ft_free_strmem(str);
				return (NULL);
			}
			index = -1;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char *argv, char c)
{
	size_t	i;
	int		index;
	char	**str;

	i = count_words(argv, c);
	str = (char **)malloc((i + 1) * sizeof(char *));
	if (!argv || !(str))
		return (NULL);
	index = -1;
	str = ft_get_str(str, index, argv, c);
	if (!str)
		return (NULL);
	return (str);
}
