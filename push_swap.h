/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:04:37 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/29 19:45:40 by afaghaja         ###   ########.fr       */
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
int					ft_atoi(const char *nptr, char *array, int *arr, char **splitted_arr);
char				*ft_strdup(const char *s);
int					ft_lstsize(t_list *lst);
int					*parsing(char *array, int *size);
void				pa(t_list **a, t_list **b, t_oper *opers);
void				pb(t_list **a, t_list **b, t_oper *opers);
void				ra(t_list **a, t_oper *opers);
void				rb(t_list **a, t_oper *opers);
void				rr(t_list **a, t_list **b, t_oper *opers);
void				rra(t_list **a, t_oper *opers);
void				rrb(t_list **a, t_oper *opers);
void				rrr(t_list **a, t_list **b, t_oper *opers);
void				sb(t_list **a, t_oper *opers);
void				sa(t_list **a, t_oper *opers);
void				ss(t_list **a, t_list **b, t_oper *opers);
void				basic(t_list **a, t_list **b, t_oper *opers);
void				rotate(t_list **b, int count, t_oper *opers);
int					find_the_element(t_list **b, int v);
void				indexavorel(t_list **a);
void				find_max(t_list **b, t_oper *opers);
char				*fill(char **argv, int i);
t_list				*lists(int *arr, int *size);
int					isvalid(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				valueing(t_bench *count, t_oper *opers, t_list **a, t_list **b);
void				chunk(t_list **a, t_list **b, t_oper *opers);
void				radix(t_list **a, t_list **b, t_oper *opers);
int					custom(float dis, t_list **a, t_list **b, t_oper *opers);
char				*ft_itoa(int n);
int					return_rem(float n);
float				disorder(t_list **a);
void				cleaning(void);
void				pars_free(char *array, int *arr, char **splitted_arr);
float				disorder(t_list **a);
void				three(t_list **a, t_oper *opers);
int					ft_strcmp(const char *s1, const char *s2);
// void				find_min(t_list **b, t_oper *opers);
// void				five(t_list **a, t_list **b, t_oper *opers);

#endif
