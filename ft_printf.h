/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirci <gdemirci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:31:22 by gdemirci          #+#    #+#             */
/*   Updated: 2024/12/04 18:53:37 by gdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	ft_print_string(char *str);
int	ft_print_int(int num);
int	ft_print_hex(unsigned int num, char format);
int	ft_print_point(unsigned long num, int sign);
int	ft_print_unsigned(unsigned int num);

#endif