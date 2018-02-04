/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:29:02 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:15:53 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define MINUS				temp->flags[0]
# define PLUS				temp->flags[1]
# define SPACE				temp->flags[2]
# define OCT				temp->flags[3]
# define ZERO				temp->flags[4]
# define ONECH				temp->c
# define WIDTH				temp->width
# define PRECIS				temp->precis
# define LENGTH0			temp->length[0]
# define LENGTH1			temp->length[1]
# define SPECIF				temp->specif
# define ISDOT				temp->isdot
# define MINWIDTH			temp->minwidth
# define NUM				temp->num
# define DISCHNUM			temp->dischnum
# define ITOANUM			temp->itoanum
# define UNUM				temp->unum
# define CH					temp->ch
# define TAB				temp->tab

typedef struct				s_struc
{
	char					c;
	int						flags[5];
	int						width;
	int						precis;
	char					length[2];
	char					specif;
	int						minwidth;
	int						isdot;
	long long int			num;
	int						dischnum;
	char					*itoanum;
	unsigned long long int	unum;
	unsigned char			ch;
	char					*tab;
}							t_struc;

int							ft_printf(const char *format, ...);
void						find_flags(char c, t_struc *temp);
int							find_width(char *former, t_struc *temp,
										va_list arg);
int							find_precis(char *former, t_struc *temp,
										va_list arg);
int							find_length(char *former, t_struc *temp);
int							find_specif(char *former, t_struc *temp);
unsigned long long int		find_number_oux(t_struc *temp, va_list arg);
int							get_discharge(long long int width);
void						ft_print_former(t_struc *temp, va_list arg);
void						ft_print_di(t_struc *temp, va_list arg);
void						ft_print_oux(t_struc *temp, va_list arg);
void						ft_print_c(t_struc *temp, va_list arg);
void						ft_print_s(t_struc *temp, va_list arg);
void						ft_print_q(t_struc *temp, va_list arg);
void						ft_print_b(t_struc *temp, va_list arg);
void						ft_print_m(t_struc *temp, va_list arg);
void						ft_print_no_specif(t_struc *temp, va_list arg);
void						put_zero_end(char **str, int n, int len);
void						put_zero_beg(t_struc *temp, char **str, int n);
unsigned long long int		make_buf(int dischnum);
char						*make_output_str_di(t_struc *temp);
char						*make_output_str_u(t_struc *temp);
char						*make_output_str_o(t_struc *temp);
char						*make_output_str_x(t_struc *temp);
char						*uitoa_base(t_struc *temp, int base);
int							valid(char c);
int							nonspec(char c);
int							nonvalid(char c);
int							emptystruc(t_struc *temp, char c);
void						make_former_without_specif(t_struc *temp,
														char **former,
														char *str);
void						make_former(t_struc *temp, char **former,
										char *str);

#endif
