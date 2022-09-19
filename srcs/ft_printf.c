/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsaglam <ilsaglam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:34:37 by ilsaglam          #+#    #+#             */
/*   Updated: 2022/09/19 14:42:56 by ilsaglam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_format_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_print_format(va_list args, char format)
{
	int	ret_val;

	ret_val = 0;
	if (format == 'c')
		ret_val = ft_print_char(va_arg(args, int));
	else if (format == 's')
		ret_val = ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		ret_val = ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		ret_val = ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		ret_val = ft_print_unbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		ret_val = ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		ret_val = ft_print_perc();
	return (ret_val);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret_val;
	va_list	args;

	i = 0;
	ret_val = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_format_check(str[i + 1], "cspdiuxX%"))
		{
			ret_val += ft_print_format(args, str[i + 1]);
			i++;
		}
		else
			ret_val += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (ret_val);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = "Hello";
// 	int integer = -2147483648;
// 	int digit = -2147483648;
// 	unsigned int unsigned_decimal = 4294967295;
// 	unsigned int hex_x = -12848;
// 	int hex_X = -12854;
// 	char c = 'c';
// 	int *ptr = &digit;
// 	ft_printf("-------------------------------------\n");
// 	ft_printf("|    My ft_printf implimentation    |\n");
// 	ft_printf("-------------------------------------\n");
// 	ft_printf("String is: %s\n", str);
// 	ft_printf("Char is: %c\n", c);
// 	ft_printf("Integer is: %i\n", integer);
// 	ft_printf("Digit is: %d\n", digit);
// 	ft_printf("Unsigned is: %u\n", unsigned_decimal);
// 	ft_printf("Hexadecimal x is: %x\n", hex_x);
// 	ft_printf("Hexadecimal X is: %X\n", hex_X);
// 	ft_printf("Pointer is: %p\n", ptr);
// 	ft_printf("Percentage sign: %%\n");
// 	ft_printf("\n");
// 	printf("-------------------------------------\n");
// 	printf("|            Real printf            |\n");
// 	printf("-------------------------------------\n");
// 	printf("String is: %s\n", str);
// 	printf("Char is: %c\n", c);
// 	printf("Integer is: %i\n", integer);
// 	printf("Digit is: %d\n", digit);
// 	printf("Unsigned is: %u\n", unsigned_decimal);
// 	printf("Hexadecimal x is: %x\n", hex_x);
// 	printf("Hexadecimal X is: %X\n", hex_X);
// 	printf("Pointer is: %p\n", ptr);
// 	printf("Percentage sign: %%\n");
// 	return 0;
// }