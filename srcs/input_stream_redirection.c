/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stream_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:07:06 by ablaamim          #+#    #+#             */
/*   Updated: 2022/06/20 13:15:31 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	input_stream_redirection(const char *io_stream)
{
	int	file_descriptor;

	file_descriptor = open(io_stream, O_RDONLY);
	if (file_descriptor < 0)
	{
		variadic_error_printer(2, "Minishell : %s : No such file or \
				directory\n");
		exit_value_set(EXIT_SUCCESS);
	}
	return (file_descriptor);
}