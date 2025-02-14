/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:52:52 by ashirzad          #+#    #+#             */
/*   Updated: 2024/06/26 12:33:59 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2, int n)
{
	char	*str;

	if (n == 4)
		str = ft_strdup(s2);
	else
		str = ft_strjoin(s1, s2);
	if (n != 3)
		free(s1);
	if (n > 1)
		free(s2);
	return (str);
}
