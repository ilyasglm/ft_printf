/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsaglam <ilsaglam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:11:00 by ilsaglam          #+#    #+#             */
/*   Updated: 2022/09/19 14:42:03 by ilsaglam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_printf.h>

void	ft_puthex_ptr(unsigned long n)
{
	if (n >= 16)
	{
		ft_puthex_ptr(n / 16);
		ft_puthex_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_print_char(n + '0');
		else
			ft_print_char((n - 10) + 'a');
	}
}

int	ft_uintsize_ptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	address;

	address = 0;
	address += write(1, "0x", 2);
	if (ptr == 0)
		address += write(1, "0", 1);
	else
	{
		ft_puthex_ptr(ptr);
		address += ft_uintsize_ptr(ptr);
	}
	return (address);
}
