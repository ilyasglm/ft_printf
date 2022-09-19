/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsaglam <ilsaglam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:02:48 by ilsaglam          #+#    #+#             */
/*   Updated: 2022/09/19 14:40:20 by ilsaglam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_print_str(char *str);
int		ft_print_char(char c);
int		ft_print_perc(void);
int		ft_print_nbr(int n);
int		ft_print_unbr(unsigned int n);
int		ft_hexlen(unsigned int n);
int		ft_print_hex(unsigned int n, char format);
void	ft_puthex(unsigned int n, char format);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_lower9(int n);
int		ft_intsize(int n);
int		ft_uintsize(unsigned int n);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_hex_ptr(unsigned long n);
void	ft_puthex_ptr(unsigned long n);
int		ft_strlen(char *str);

#endif