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
	int		save;

	res = 0;
	if (nb >= 10)
	{
		save = ft_putunbr_fd(nb / 10, fd);
		if (save < 0)
			return (-1);
		res += save;
	}
	c = nb % 10 + '0';
	save = write(fd, &c, 1);
	if (save < 0)
		return (-1);
	res += save;
	return (res);
}
