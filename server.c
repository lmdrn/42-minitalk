/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:40:42 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/11 20:25:45 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* byte = 0^7 + 2^6 + 0^5 + 0^4 + 2^3 + 0^2 + 0^1 + 0^0; */
void	signal_handler(int signal)
{
	static int	byte;
	static int	index;

	index = 0;
	byte = 0;
	printf("signal : %d\n", signal);
	if (signal == SIGUSR1)
	{
		byte = byte + (0 * index);
		ft_printf("it's a zero!\n");
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("it's a one!\n");
		byte = byte + (2 * index);
	}
	else if (signal == SIGINT)
	{
		ft_printf("Exiting Server...\n");
		exit(0);
	}
	index++;
	if (index == 8)
	{
		ft_putchar_fd((char)byte, 1);
	}
	index = 0;
}

void	set_signal_action(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
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
	sleep(1);
	ft_printf("Launching server...\n");
	sleep(1);
	printf("Server launched!\n");
	set_signal_action();
	sleep(1);
	ft_printf("Server's PID is : %d\n", server_pid);
	while (1)
		pause();
	return (0);
}
