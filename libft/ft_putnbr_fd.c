/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:43:38 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/09 16:18:27 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		res;

	res = 0;
	if (n == -2147483648)
	{
		res = write(fd, "-2147483648", 11);
		return (res);
	}
	if (n < 0)
	{
		res += write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		res += ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	res += write(fd, &c, 1);
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
