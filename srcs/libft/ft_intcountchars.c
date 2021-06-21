/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intcountchars.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 12:55:11 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/06/10 14:01:10 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intcountchars(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
