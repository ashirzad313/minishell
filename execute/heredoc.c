/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:23:59 by ashirzad          #+#    #+#             */
/*   Updated: 2024/06/26 12:34:32 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_heredoc(t_obj *obj);
char	*ft_run(t_obj *obj, char *stop, int i);
char	*ft_expand(t_obj *obj, char *str);

int	ft_heredoc(t_obj *obj)
{
	t_cmd	*cmd_t;
	t_lexer	*lexer;
	char	*file;
	int		i;

	cmd_t = obj->cmd;
	lexer = NULL;
	i = 0;
	while (cmd_t)
	{
		file = NULL;
		lexer = cmd_t->lexer;
		while (lexer)
		{
			if (lexer->i == HEREDOC)
			{
				file = ft_run(obj, lexer->str, i);
				lexer->str = ft_strjoin2(lexer->str, file, 4);
				i++;
			}
			lexer = lexer->next;
		}
		cmd_t = cmd_t->next;
	}
	return (SUCCESS);
}

char	*ft_run(t_obj *obj, char *stop, int i)
{
	char	*str;
	char	*file;
	int		fd;

	file = ft_strjoin2("h", ft_itoa(i), 3);
	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	while (1)
	{
		str = readline("> ");
		if (str == NULL)
		{
			close(fd);
			break ;
		}
		else if (ft_strcmp(str, stop) == 0)
		{
			free(str);
			close(fd);
			break ;
		}
		str = ft_expand(obj, str);
		write(fd, str, ft_strlen(str));
		free(str);
	}
	return (file);
}

char	*ft_expand(t_obj *obj, char *str)
{
	char	**argv;
	int		i;

	i = 0;
	if (str == NULL || ft_strcmp(str, "") == 0)
		return (ft_strdup(""));
	argv = ft_split(str, ' ');
	free(str);
	str = NULL;
	while (argv[i])
	{
		if (ft_strrchr(argv[i], '$'))
			str = ft_strjoin2(str, get_value(obj, argv[i] + 1), 2);
		else
			str = ft_strjoin2(str, argv[i], 2);
		i++;
	}
	str = ft_strjoin2(str, "\n", 1);
	return (str);
}
