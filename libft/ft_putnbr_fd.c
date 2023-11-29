/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:43:38 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/27 10:14:55 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	int		res;
	int		save;

	res = 0;
	if (n == -2147483648)
		return ((int)write(fd, "-2147483648", 11));
	if (n < 0)
	{
		if (write(fd, "-", 1) < 0)
			return (-1);
		res++;
		n *= -1;
	}
	if (n >= 10)
	{
		save = ft_putnbr_fd(n / 10, fd);
		if (save < 0)
			return (-1);
		res += save;
	}
	if (ft_putchar_fd((n % 10 + '0'), 0) < 0)
		return (-1);
	res++;
	return (res);
}

/*
#include <stdlib.h>
int main(int argc, char **argv)
{
	argc = 0;
	ft_putnbr_fd(atoi(argv[1]), 1);
}
*/
