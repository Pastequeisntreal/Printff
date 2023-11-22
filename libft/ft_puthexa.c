/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:36:08 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/16 15:36:08 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stddef.h>

int	ft_puthexa_fd(unsigned int nb, int fd, t_alpha_type alpha_type)
{
	char	c;
	int		res;

	res = 0;
	if (nb >= 16)
		res += ft_puthexa_fd(nb / 16, fd, alpha_type);
	if (nb % 16 >= 10)
		c = nb % 16 - 10 + 'A' + alpha_type;
	else
		c = nb % 16 + '0';
	res += write(fd, &c, 1);
	return (res);
}

int	ft_putmem_fd(unsigned long nb, int fd)
{
	char	c;
	int		res;

	res = 0;
	if (nb >= 16)
		res += ft_putmem_fd(nb / 16, fd);
	if (nb % 16 >= 10)
		c = nb % 16 - 10 + 'a';
	else
		c = nb % 16 + '0';
	res += write(fd, &c, 1);
	return (res);
}

int	p_option(unsigned long nb)
{
	if (!nb)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_putmem_fd(nb, 1));
}
