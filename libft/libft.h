/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:27:53 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/22 15:10:08 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

typedef enum e_alpha_type
{
	CAPITALIZE,
	LOWER = 32
}	t_alpha_type;

int		ft_puthexa_fd(unsigned int nb, int fd, t_alpha_type alpha_type);
int		ft_putunbr_fd(unsigned int nb, int fd);
int		ft_putchar_fd(unsigned char c, int fd);
int		ft_putendl_fd(const char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char const *s, int fd);
int		ft_putmem_fd(unsigned long nb, int fd);
int		p_option(unsigned long nb);

#endif