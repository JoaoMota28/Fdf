/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:57:13 by jomanuel          #+#    #+#             */
/*   Updated: 2025/04/03 17:01:52 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	conv_hex_to_int(char *str)
{
	unsigned int	res;

	res = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 16 + *str - '0';
		if (*str >= 'A' && *str <= 'F')
			res = res * 16 + *str - 'A' + 10;
		if (*str >= 'a' && *str <= 'f')
			res = res * 16 + *str - 'a' + 10;
		str++;
	}
	return (res);
}
