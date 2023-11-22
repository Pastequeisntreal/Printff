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
	int		save;
	int		res;

	res = 0;
	if (nb >= 16)
	{
		save = ft_puthexa_fd(nb / 16, fd, alpha_type);
		if (save < 0)
			return (-1);
		res += save;
	}
	if (nb % 16 >= 10)
		c = nb % 16 - 10 + 'A' + alpha_type;
	else
		c = nb % 16 + '0';
	save = write(fd, &c, 1);
	if (save < 0)
		return (-1);
	res += save;
	return (res);
}

int	ft_putmem_fd(unsigned long nb, int fd)
{
	char	c;
	int		save;
	int		res;

	res = 0;
	if (nb >= 16)
	{
		save = ft_putmem_fd(nb / 16, fd);
		if (save < 0)
			return (-1);
		res += save;
	}
	if (nb % 16 >= 10)
		c = nb % 16 - 10 + 'a';
	else
		c = nb % 16 + '0';
	save = write(fd, &c, 1);
	if (save < 0)
		return (-1);
	res += save;
	return (res);
}

int	p_option(unsigned long nb)
{
	if (!nb)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_putmem_fd(nb, 1));
}
