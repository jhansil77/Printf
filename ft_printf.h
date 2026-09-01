/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhannsil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:43:29 by jhannsil          #+#    #+#             */
/*   Updated: 2026/08/19 17:43:30 by jhannsil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "Libft/libft.h"

int	ft_printf(char const *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	int_len(int n);
int	ft_putnbr_base(long long nbr, char *base);
int	ft_print_ptr(void *ptr, char *base);
int	ft_putnbr_base_ul(unsigned long nbr, char *base);

#endif
