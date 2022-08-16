/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Asandy <abasifrekesandy@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:37:52 by Asandy            #+#    #+#             */
/*   Updated: 2022/08/16 20:38:38 by Asandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"

void	reciever(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else if (sig == SIGUSR2)
	{
		c = (c << 1) | 0;
	}
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr_fd("PID: ", 1);
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		signal(SIGUSR1, reciever);
		signal(SIGUSR2, reciever);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("Wrong number of arguments : ./server", 2);
	return (0);
}
