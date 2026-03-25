/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:04:37 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/25 16:29:30 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				num;
	struct s_list	*next;
}					t_list;

typedef struct s_oper
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_oper;
typedef struct s_bench
{
	int				simple;
	int				medium;
	int				complex;
	int				adaptive;
	int				bench;
}					t_bench;

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
t_list				*ft_lstnew(int value);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_atoi(const char *nptr);
char				*ft_strdup(const char *s);
int					ft_lstsize(t_list *lst);
void				pars(int argc, char **argv, int *arr);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **a);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **a);
void				rrr(t_list **a, t_list **b);
void				sb(t_list **a);
void				sa(t_list **a);
void				ss(t_list **a, t_list **b);
void				basic(t_list **a, t_list **b);
void				find_max(t_list **b);
void				rotate(t_list **b, int count);
int					find_the_element(t_list **b, int v);
void				indexavorel(t_list **a);
void				rotate(t_list **b, int count);
void				find_max(t_list **b);
char				*fill(char **argv);
t_list				*lists(int *arr, int size);
int					isvalid(char *str);
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
