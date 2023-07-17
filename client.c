/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:47:16 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/17 13:50:58 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	encrypt_and_send(int pid, char *sentence)
{
	int		index;
	int		letter;

	letter = 0;
	while (sentence[letter] != '\0')
	{
		index = 0;
		while (index < 8)
		{
			if ((int)sentence[letter] & (1 << index))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
			index++;
		}
		letter++;
	}
}

void	no_inputs(void)
{
	ft_printf("---------- ERROR ----------\n");
	ft_printf("Wrong input || No args ! Please fix and try again !\n");
	ft_printf("Usage: ./client <PID> <TEXT>\n");
	ft_printf("---------- ERROR ----------\n");
}

int	main(int ac, char **av)
{
	int		pid;
	char	*sentence;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		sentence = av[2];
		if (!pid || !sentence[0])
			no_inputs();
		encrypt_and_send(pid, sentence);
	}
	else
		no_inputs();
	return (0);
}
