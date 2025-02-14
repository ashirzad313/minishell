/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:16:21 by ashirzad          #+#    #+#             */
/*   Updated: 2024/06/26 18:53:49 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip(const char **str, int *count)
{
	if (*(*str - 1) && *(*str - 1) == ' ')
		*count += 1;
	if (*(*str) != '\0')
	{
		(*str)++;
		return (1);
	}
	return (0);
}

int	ft_sep2(char c)
{
	if (c == '$')
		return (1);
	else if (c == '\'')
		return (1);
	else if (c == '\"')
		return (1);
	return (0);
}

void	double_dollor(const char **str, int *count)
{
	while (*(*str) && *(*str) == '$' && *(*str + 1) == '$')
	{
		(*str) += 2;
		*count += 1;
	}
}

int	dollor_len(const char	**str)
{
	if (*(*str) == '$' && *(*str + 1) && *(*str + 1) == '$')
	{
		(*str) += 2;
		return (1);
	}
	return (0);
}
