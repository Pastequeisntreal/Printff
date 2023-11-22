/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:31:56 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/20 17:08:55 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdarg.h>

int	ft_put_other(char c)
{
	int	res;

	if (c == '%')
	{
		res = ft_putchar_fd('%', 1);
	}
	if (c == 0)
		return (-1);
	return (res);
}

int	ft_put_all_u(unsigned int content, char c)
{
	int		res;

	if (c == 'u')
		res = ft_putunbr_fd(content, 1);
	if (c == 'x')
		res = ft_puthexa_fd(content, 1, LOWER);
	if (c == 'X')
		res = ft_puthexa_fd(content, 1, CAPITALIZE);
	return (res);
}

int	get_flag(va_list var, char c)
{
	int		res;

	if (c == 'c')
		res = ft_putchar_fd((unsigned char)va_arg(var, int), 1);
	else if (c == 's')
		res = ft_putstr_fd(va_arg(var, char *), 1);
	else if (c == 'd' || c == 'i')
		res = ft_putnbr_fd(va_arg(var, int), 1);
	else if (c == 'x' || c == 'u' || c == 'X' || c == 'p')
		res = ft_put_all_u(va_arg(var, unsigned int), c);
	else
		res = ft_put_other(c);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	var;
	int		ret;
	int		res;

	i = 0;
	res = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
			ret = get_flag(var, str[++i]);
		else
			ret = ft_putchar_fd(str[i], 1);
		if (ret < 0)
			return (-1);
		else
			res += ret;
		i++;
	}
	va_end(var);
	return (res);
}
