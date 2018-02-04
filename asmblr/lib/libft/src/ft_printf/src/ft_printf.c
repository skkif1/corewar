/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:04:51 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/04 13:42:32 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			check_former(char *former, t_struc *temp, va_list arg)
{
	int		i;
	int		ret;

	i = 0;
	while (former[i])
	{
		ret = 0;
		if ((former[i] == '-' || former[i] == '+' || former[i] == ' ' ||
			former[i] == '#' || former[i] == '0') && former[i])
			find_flags(former[i], temp);
		else if ((former[i] == 'l' || former[i] == 'h' ||
			former[i] == 'j' || former[i] == 'z') && former[i])
			ret = find_length(former + i, temp);
		else if ((former[i] >= '1' && former[i] <= '9' &&
			former[i]) || former[i] == '*')
			ret = find_width(former + i, temp, arg);
		else if (former[i] == '.')
			ret = find_precis(former + i, temp, arg);
		else if (find_specif(former + i, temp))
			break ;
		i += (ret == 0) ? 1 : ret;
	}
	return (i);
}

int			make_struct(char *str, t_struc *temp, va_list arg)
{
	char	*former;
	int		len;
	int		i;

	make_former(temp, &former, str);
	len = ft_strlen(former);
	i = check_former(former, temp, arg);
	if (emptystruc(temp, former[i]))
		return (0);
	else
		ft_print_former(temp, arg);
	free(former);
	return (len);
}

t_struc		*make_empty_struct(void)
{
	t_struc *temp;

	if (!(temp = (t_struc *)malloc(sizeof(t_struc))))
		return (NULL);
	MINUS = '\0';
	PLUS = '\0';
	SPACE = '\0';
	OCT = '\0';
	ZERO = '\0';
	ONECH = '\0';
	WIDTH = 0;
	PRECIS = 0;
	LENGTH0 = '\0';
	LENGTH1 = '\0';
	SPECIF = '\0';
	MINWIDTH = 0;
	NUM = 0;
	DISCHNUM = 0;
	ITOANUM = NULL;
	ISDOT = 0;
	UNUM = 0;
	CH = '\0';
	TAB = NULL;
	return (temp);
}

int			start_printf(const char *format, va_list arg, int ret)
{
	char		*str;
	t_struc		*temp;
	int			i;

	str = (char *)format;
	i = -1;
	while (str[++i])
	{
		while (str[i] != '%' && str[i])
		{
			ft_putchar(str[i++]);
			ret++;
		}
		if (str[i] == '\0')
			break ;
		if (str[i] == '%' && str[i])
		{
			temp = make_empty_struct();
			i += make_struct(str + i + 1, temp, arg);
			ret += MINWIDTH;
			free(temp);
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg;

	va_start(arg, format);
	ret = start_printf(format, arg, 0);
	va_end(arg);
	return (ret);
}
