/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:40:42 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/14 08:31:27 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*append_letter(char const *s1, char const letter)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j + 1] = letter;
	str[j] = 0;
	free((void *)(s1));
	return (str);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
	{
		nb = nb * ft_recursive_power(nb, power - 1);
	}
	return (nb);
}	

void	signal_handler(int signal)
{
	static int	bit;
	static int	index;
	static char	*final_byte;

	index = 0;
	if (signal == SIGUSR1)
	{
		bit = bit + 0;
		ft_printf("couocn1");
	}
	else if (signal == SIGUSR2)
	{
		bit = bit + (1 * ft_recursive_power(2, index));
		ft_printf("couocn2");
	}
	if (signal == SIGINT)
	{
		ft_printf("Exiting Server...\n");
		exit(0);
	}
	if (index == 8)
	{
		ft_printf("couocn3");
		final_byte = append_letter(final_byte, bit);
		if (bit == '\0')
		{
			ft_printf("couocn4");
			ft_printf("%s\n", final_byte);
			final_byte = 0;
			ft_printf("couocn5");
		}
		index = 0;
		bit = 0;
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
	ft_printf("Server's PID is : %d\n", server_pid);
	while (1)
		pause();
	return (0);
}
