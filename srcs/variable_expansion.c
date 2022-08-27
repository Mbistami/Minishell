/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:28:35 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/27 16:17:21 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	verify_next_char(char c)
{
	//printf("verify_next_char -> verified\n");
	return (c == '\0' || (ft_isalnum(c) == 0x0  && c != '?'));
}

char		*allocate_new_argument(char *arg, int len_var_name, char *var_val)
{
	char	*new_arg;
	int		len_var_val;

	
	len_var_val = ft_strlen(var_val);
	new_arg = garbage_malloc(sizeof(*new_arg) * (ft_strlen(arg) - len_var_name + len_var_val));
	return (new_arg);
}

char	*new_argument(char **argv, int len_var_name, int i, char *var_val)
{
	char	*new_arg;
	int		j;
	int		k;

	//printf("new_argument -> VAR IS NEW\n");
	j = 0x0;
	new_arg = allocate_new_argument(*argv, len_var_name, var_val);
	while (j < i)
	{
		new_arg[j] = (*argv)[j];
		++j;
	}
	k = 0x0;
	while (var_val[k])
		new_arg[j++] = var_val[k++];
	i = i + len_var_name + 1;
	while ((*argv)[i] != '\0')
		new_arg[j++] = (*argv)[i++];
	new_arg[j] = '\0';
	//garbage_free((void **) argv);
	return (new_arg);
}

bool	variable_expansion(t_simple_cmd *cmd, int const i)
{
	int		j;
	bool	in_squotes;
	bool	in_dquotes;

	j = 0x0;
	in_squotes = false;
	in_dquotes = false;
	while (cmd->argv[i] != 0x0 && cmd->argv[i][j] != '\0')
	{
		if (cmd->argv[i][j] == '$' && in_squotes == false)
		{
			//printf("variable_expansion -> DOLLAR FOUND\n");
			if (verify_next_char(cmd->argv[i][j + 1]) == true)
				cmd->argv[i] = new_argument(&cmd->argv[i], 0, j++, "$");
			else
				if (expand_single_variable(cmd, i, &j, in_dquotes) == false)
					return (false);
		}
		else
		{
			substitute_quotes_state(cmd->argv[i][j], &in_squotes, &in_dquotes);
			++j;
		}
	}
	return (true);
}
