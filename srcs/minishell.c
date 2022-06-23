/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:10:38 by ablaamim          #+#    #+#             */
/*   Updated: 2022/06/23 23:44:21 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Function to free all file descriptors beyond or equal to 3.
*/

void	ft_free_fd(void)
{
	int	fd;

	fd = open("console", O_WRONLY);
	while (fd >= 0)
	{
		if (fd >= 3)
			close(fd);
		break ;
	}
}

/*
 * Entry point of my program, init and launch all process.
 *
 * ===> if argc == 1 (prgm name)
 * - Init env.
 * - recognize inline/Outline mode using istty() fuction 
 * - Free all filedescriptors beyond or equal to 3.
 * - Init my minishell.
 * ===> Else ERROR
*/

int	main(int argc, char **argv, char **env)
{
	if (argc == 1)
	{
		init_bash_env(file_extract(argv[0]), env);
		printf("============================================================\n\n");
		//printf("\n\nLEAKS FREE CODE\n\n");
		//ft_print_env(env);
		ft_free_fd();
		ft_minishell();
	}
	else
	{
		variadic_error_printer(2, "Error, invalid argv\n");
		//write(2, ARGV_ERROR, sizeof(ARGV_ERROR));
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
