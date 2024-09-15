/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:51:00 by ashirzad          #+#    #+#             */
/*   Updated: 2024/06/26 17:07:05 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	determine_exit_code(t_obj *obj, int exit_code)
{
	obj->exit_code = exit_code;
	return (exit_code);
}

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	free_tmp_files(void)
{
	char	*file;
	int		i;

	i = 0;
	file = NULL;
	while (1)
	{
		file = ft_strjoin2("h", ft_itoa(i), 3);
		if (unlink(file) == -1)
		{
			free(file);
			break ;
		}
		free(file);
		i++;
	}
}

void	free_tools(t_obj *obj, int n)
{
	if (n == 1)
	{
		free(obj->str);
		free_cmd(&obj->cmd);
		free_tmp_files();
	}
	else
	{
		free_env(&obj->env);
		free(obj->tool.oldpwd);
		free(obj->tool.pwd);
		free(obj->str);
		free_cmd(&obj->cmd);
		free_tmp_files();
	}
}

int	ft_exit(char **argv, t_obj *obj)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i > 2)
	{
		printf("exit: too many args.\n");
		exit(determine_exit_code(obj, Q_ERROR));
	}
	else if (argv[1])
	{
		if (!is_number(argv[1]))
		{
			printf("exit\n");
			printf("minishell: exit: : numeric argument required\n");
			free_tools(obj, 2);
			exit(determine_exit_code(obj, Q_ERROR));
		}
		else
			obj->exit_code = ft_atoi(argv[1]);
	}
	free_tools(obj, 2);
	printf("exit\n");
	exit(obj->exit_code);
}
