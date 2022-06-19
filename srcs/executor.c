/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:20:46 by ablaamim          #+#    #+#             */
/*   Updated: 2022/06/20 00:50:35 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * Function to save history input from stdin in my CLI, without termcaps.
*/

void	ft_add_history(char *line)
{
	add_history(line);
}

/*
 * initialize my AST, lex and parse [Syntax analyzer + Recursive descent 
 * parser] the input read, Build my ASY and execute it.
*/

void	ft_executor(char *line, bool inline_mode)
{
	t_node	*ast;

	ast = 0x0;
	if (line != 0x0)
	{
		ft_add_history(line);
		ast = ft_lexer_parser_program(line);
		{
			if (ast != 0x0)
			{
				printf("\n\n================> EXECUTION GONE PRRRRR : <=================\n\n");
				execute_ast_data(ast, inline_mode);
				/*
				 * TO DO : FREE AST DATA.
				 * [CASE CLOSED]
				*/
				ast_clearing(&ast);
			}
		}
	}
	else
	{
		/*
		 * TO DO : SIGNAL HANDLING
		*/
		variadic_error_printer(2, "ERROR : HANDLE SIGNALS");
		exit(EXIT_FAILURE);
	}
}
