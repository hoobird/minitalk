/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:27:00 by hulim             #+#    #+#             */
/*   Updated: 2024/04/14 21:33:15 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		sendmsginbits(int pid, char *str);
int		checkpidisnum(char *pid);
int		sendchar(int pid, char c);
void	counter(int signum);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: Client takes 2 parameters\n");
		ft_printf("Server PID and String to send\neg: ./client (pid) (msg)\n");
		return (1);
	}
	signal(SIGUSR1, counter);
	if ((checkpidisnum(argv[1]) == 0)
		|| (sendchar(ft_atoi(argv[1]), 0) == -1))
	{
		ft_printf("Error: Unable to send signal to specified PID\n");
		return (0);
	}
	sendmsginbits(ft_atoi(argv[1]), ft_strjoin(argv[2], "\n"));
	return (0);
}

void	counter(int signum)
{
	static int	count;

	if (signum == SIGUSR1)
		count++;
	return ;
}

int	sendmsginbits(int pid, char *str)
{
	while (*str)
	{
		sendchar(pid, *str);
		str++;
	}
	return (0);
}

int	sendchar(int pid, char c)
{
	size_t	bitcount;
	int		outcome;

	bitcount = 0;
	while (bitcount < 8)
	{
		usleep(500);
		if (1 & (c >> bitcount))
			outcome = kill(pid, SIGUSR1);
		else
			outcome = kill(pid, SIGUSR2);
		if (outcome == -1)
			return (-1);
		bitcount++;
		pause();
	}
	return (outcome);
}

int	checkpidisnum(char *pid)
{
	while (*pid)
	{
		if (*pid < '0' || *pid > '9')
			return (0);
		pid++;
	}
	return (1);
}
