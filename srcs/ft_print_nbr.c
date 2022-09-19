/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsaglam <ilsaglam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:19:47 by ilsaglam          #+#    #+#             */
/*   Updated: 2022/09/19 14:46:05 by ilsaglam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 0;
	else
	{
		while (n != 0)
		{
			len++;
			n = n / 10;
		}
	}
	return (len);
}

int	ft_print_nbr(int n)
{
	char	*nbr;
	int		ret_val;

	nbr = ft_itoa(n);
	ret_val = ft_print_str(nbr);
	free(nbr);
	if (n < 0)
		return (ret_val);
	return (ret_val);
}

int	ft_print_unbr(unsigned int n)
{
	char	*nbr;
	int		ret_val;

	nbr = ft_uitoa(n);
	ret_val = ft_print_str(nbr);
	free(nbr);
	if (n < 0)
		return (ret_val + 1);
	return (ret_val);
}
