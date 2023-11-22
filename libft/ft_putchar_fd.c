/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:38:26 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/20 11:25:49 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(unsigned char c, int fd)
{
	return (write(fd, &c, 1));
}
/*
int main(void)
{
	ft_putchar_fd('a', 1);
}
*/
