/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsaglam <ilsaglam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:11:32 by ilsaglam          #+#    #+#             */
/*   Updated: 2022/09/19 14:48:03 by ilsaglam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_hexlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			n = n / 16;
			i++;
		}
	}
	return (i);
}

int	ft_print_hex(unsigned int n, char format)
{
	if (n == 0)
		ft_print_char('0');
	else
		ft_puthex(n, format);
	return (ft_hexlen(n));
}

void	ft_puthex(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_print_char(n + '0');
		else
		{
			if (format == 'x')
				ft_print_char((n - 10) + 'a');
			else if (format == 'X')
				ft_print_char((n - 10) + 'A');
		}
	}
}
