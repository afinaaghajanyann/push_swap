/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:06:53 by larevsha          #+#    #+#             */
/*   Updated: 2026/04/01 17:57:26 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *src, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		oper_use_s(t_list **a, t_list **b, char *s, t_oper *opers);
int		oper_use_p(t_list **a, t_list **b, char *s, t_oper *opers);
int		oper_use_r(t_list **a, t_list **b, char *s, t_oper *opers);
int		oper_use_rr(t_list **a, t_list **b, char *s, t_oper *opers);
int		is_val_hertakanutyun(t_list **a, t_list **b);
#endif
