/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_puts_width.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:06 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/06/17 14:38:55 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../libft/libft.h"

void	pf_puts_width_zero(t_convert *p)
{
	if (p->precision > -1)
	{
		pf_putzero(p, p->width - p->precision);
		write(1, p->s, p->precision);
		p->count += p->precision;
	}
	else
	{
		pf_putzero(p, p->width - ft_strlen(p->s));
		write(1, p->s, ft_strlen(p->s));
		p->count += ft_strlen(p->s);
	}
}

void	pf_puts_width_precision(t_convert *p)
{
	if (p->precision < (int)ft_strlen(p->s))
	{
		pf_putspaces(p, p->width - p->precision);
		write(1, p->s, p->precision);
		p->count += p->precision;
	}
	else
	{
		pf_putspaces(p, p->width - ft_strlen(p->s));
		write (1, p->s, ft_strlen(p->s));
		p->count += ft_strlen(p->s);
	}
}

void	pf_puts_width(t_convert *p)
{
	if (p->zero)
		pf_puts_width_zero(p);
	else
	{
		if (p->precision > -1)
		{
			pf_puts_width_precision(p);
		}
		else
		{
			pf_putspaces(p, p->width - ft_strlen(p->s));
			write(1, p->s, ft_strlen(p->s));
			p->count += ft_strlen(p->s);
		}
	}
}
