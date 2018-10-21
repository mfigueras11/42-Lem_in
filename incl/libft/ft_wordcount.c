/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:34:08 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/02 15:55:51 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		if ((str[i] != c && i == 0) || (str[i] != c && (str[i - 1] == c)))
			word_count++;
		i++;
	}
	return (word_count);
}
