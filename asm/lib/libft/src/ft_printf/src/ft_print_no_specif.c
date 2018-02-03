/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_no_specif.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:01:21 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:01:47 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	make_str_no_specif(t_struc *temp, char **str)
{
	(MINUS == 1) ? ZERO = 0 : 0;
	(ZERO == 1) ? put_zero_beg(temp, str, MINWIDTH) : 0;
	if (MINUS == 1)
		((*str)[0] = ONECH);
	else
		((*str)[MINWIDTH - 1] = ONECH);
}

char	*make_output_no_specif(t_struc *temp)
{
	char	*str;

	if (ONECH == '\0')
		return (NULL);
	MINWIDTH = DISCHNUM;
	(WIDTH > DISCHNUM) ? (MINWIDTH = WIDTH) : 0;
	if (!(str = (char*)malloc(sizeof(char) * (MINWIDTH + 1))))
		return (NULL);
	str = ft_memset(str, ' ', MINWIDTH);
	str[MINWIDTH] = '\0';
	make_str_no_specif(temp, &str);
	return (str);
}

void	ft_print_no_specif(t_struc *temp, va_list arg)
{
	char	*str;

	DISCHNUM = 1;
	str = make_output_no_specif(temp);
	(void)arg;
	if (str != NULL)
		write(1, str, MINWIDTH);
	free(str);
}
