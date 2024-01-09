/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabhm <lucabhm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:36 by lbohm             #+#    #+#             */
/*   Updated: 2023/11/28 19:53:27 by lucabhm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *word, int letter)
{
	int	size;

	size = ft_strlen(word);
	while (size >= 0)
	{
		if (word[size] == (char)letter)
			return ((char *)(word + size));
		size--;
	}
	return (0);
}
