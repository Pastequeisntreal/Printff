/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:34 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/16 15:33:34 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putunbr_fd(unsigned int nb, int fd)
{
	char	c;
	int		res;

	res = 0;
	if (nb >= 10)
		res += ft_putunbr_fd(nb / 10, fd);
	c = nb % 10 + '0';
	res += write(fd, &c, 1);
	return (res);
}
