/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:56:05 by hulim             #+#    #+#             */
/*   Updated: 2024/04/14 21:38:12 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bittochar(int sig, siginfo_t *info, void *ucontext);
void	resetbitcountandletter(size_t *bitcount, char *letter);

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	as;

	(void) argv;
	as.sa_sigaction = &bittochar;
	as.sa_flags = SA_SIGINFO;
	sigemptyset(&as.sa_mask);
	if (argc != 1)
	{
		ft_printf("Error: Server doesn't take parameters\n");
		ft_printf("eg: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sigaction(SIGUSR1, &as, NULL);
	sigaction(SIGUSR2, &as, NULL);
	while (1)
		pause();
	return (0);
}

void	resetbitcountandletter(size_t *bitcount, char *letter)
{
	*bitcount = 0;
	*letter = 0;
}

void	bittochar(int sig, siginfo_t *info, void *ucontext)
{
	static char		letter;
	static size_t	bitcount;
	static int		clientpid;
	static int		currpid;

	(void) ucontext;
	if (!clientpid)
		clientpid = info->si_pid;
	currpid = info->si_pid;
	if (currpid != clientpid)
	{
		resetbitcountandletter(&bitcount, &letter);
		clientpid = currpid;
	}
	if (sig == SIGUSR1)
		letter = letter | 1 << bitcount;
	bitcount++;
	if (bitcount == 8)
	{
		write(1, &letter, 1);
		resetbitcountandletter(&bitcount, &letter);
	}
	usleep(400);
	kill(clientpid, SIGUSR1);
}
