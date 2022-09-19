/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsaglam <ilsaglam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:50:31 by ilsaglam          #+#    #+#             */
/*   Updated: 2022/09/19 13:03:36 by ilsaglam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_intsize(int n)
{
	int	x;

	x = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		x++;
	}
	while (n > 9)
	{
		n = n / 10;
		x++;
	}
	if (n <= 9)
		x++;
	return (x);
}

int	ft_uintsize(unsigned int n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		x++;
	}
	while (n > 9)
	{
		n = n / 10;
		x++;
	}
	if (n <= 9)
		x++;
	return (x);
}

char	*ft_lower9(int n)
{
	char	*dest;

	dest = malloc(sizeof(char) * 3);
	if (!dest)
		return (0);
	n = n * -1;
	dest[0] = '-';
	dest[1] = 48 + n;
	dest[2] = 0;
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;

	i = ft_intsize(n);
	if (n < 0 && i == 2)
		return (dest = ft_lower9(n));
	else
		dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	if (n < 0 || n == -2147483648)
	{
		dest[--i] = ((n % 10) * -1) + '0';
		n = (n / 10) * -1;
		dest[0] = '-';
	}
	while (n > 9)
	{
		dest[--i] = (n % 10) + '0';
		n = n / 10;
	}
	dest[--i] = n + '0';
	return (dest);
}

char	*ft_uitoa(unsigned int n)
{
	char	*dest;
	int		i;

	i = ft_uintsize(n);
	if (n < 0 && i == 2)
		return (dest = ft_lower9(n));
	else
		dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	if (n < 0)
	{
		dest[--i] = ((n % 10) * -1) + '0';
		n = (n / 10) * -1;
		dest[0] = '-';
	}
	while (n > 9)
	{
		dest[--i] = (n % 10) + '0';
		n = n / 10;
	}
	dest[--i] = n + '0';
	return (dest);
}
