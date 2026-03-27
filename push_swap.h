/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:04:37 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/27 15:21:47 by afaghaja         ###   ########.fr       */
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
int					*parsing(char *array, int argc);
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
char				*fill(char **argv, int i);
t_list				*lists(int *arr, int size);
int					isvalid(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				valueing(t_bench *count, t_oper *opers);
void				chunk(t_list **a, t_list **b);
void				radix(t_list **a, t_list **b);
int					custom(float dis, t_list **a, t_list **b);
char				*ft_itoa(int n);
int					return_rem(float n);
float				disorder(t_list **a);

#endif
