/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:40:42 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/17 13:51:12 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	signal_handler(int signal)
{
	static int	bit;
	static int	index;

	if (signal == SIGUSR1)
		bit |= (1 << index);
	index++;
	if (signal == SIGINT)
	{
		ft_printf("Exiting Server...\n");
		exit(0);
	}
	if (index == 8)
	{
		ft_putchar(bit);
		bit = 0;
		index = 0;
	}
}

void	set_signal_action(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_handler = &signal_handler;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	ft_printf("Hello! Welcome to Lea's server\n");
	ft_printf("Launching server...\n");
	sleep(1);
	printf("Server launched!\n");
	set_signal_action();
	ft_putchar('\n');
	ft_printf("Server's PID is : %d\n", server_pid);
	while (1)
		pause();
	return (0);
}
