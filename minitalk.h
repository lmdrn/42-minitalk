/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:41:32 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/20 08:59:26 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

/* -------- PROTOTYPES DE FUNCTIONS -------- */

/* -- ARGS -- */
void	no_inputs(void);

/* -- UTILS -- */
void	ft_putchar(char c);
int		ft_isspace(char c);
int		ft_atoi(const char *str);

#endif
