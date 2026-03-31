/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:04:37 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/31 16:08:38 by afaghaja         ###   ########.fr       */
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
typedef struct s_vals
{
	t_list			*a;
	t_list			*b;
	t_bench			count;
	t_oper			opers;
	int				alg;
	int				pars;
	int				i;
	int				size;
	int				strat;
	float			dis;
}					t_vals;

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
t_list				*ft_lstnew(int value);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
long long			ft_atoi(char *nptr, char *array, int *arr,
						char **splitted_arr);
char				*ft_strdup(const char *s);
int					ft_lstsize(t_list *lst);
int					*parsing(char *array, int *size, t_vals *vals);
void				pa(t_list **a, t_list **b, t_oper *opers, int n);
void				pb(t_list **a, t_list **b, t_oper *opers, int n);
void				ra(t_list **a, t_oper *opers, int n);
void				rb(t_list **a, t_oper *opers, int n);
void				rr(t_list **a, t_list **b, t_oper *opers, int n);
void				rra(t_list **a, t_oper *opers, int n);
void				rrb(t_list **a, t_oper *opers, int n);
void				rrr(t_list **a, t_list **b, t_oper *opers, int n);
void				sb(t_list **a, t_oper *opers, int n);
void				sa(t_list **a, t_oper *opers, int n);
void				ss(t_list **a, t_list **b, t_oper *opers, int n);
void				basic(t_list **a, t_list **b, t_oper *opers);
void				rotate(t_list **b, int count, t_oper *opers);
int					find_the_element(t_list **b, int v);
void				indexavorel(t_list **a);
void				find_max(t_list **b, t_oper *opers);
char				*fill(char **argv, int i, t_vals *vals);
t_list				*lists(int *arr, int *size, t_vals *vals);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				valueing(t_bench *count, t_oper *opers, t_list **a,
						t_list **b);
void				chunk(t_list **a, t_list **b, t_oper *opers);
void				radix(t_list **a, t_list **b, t_oper *opers);
int					custom(float dis, t_list **a, t_list **b, t_oper *opers);
char				*ft_itoa(int n);
int					return_rem(float n);
float				disorder(t_list **a);
void				cleaning(t_vals *vals);
void				clean_splitted_arr(char **splitted_arr);
void				pars_free(char *array, int *arr, char **splitted_arr,
						t_vals *vals);
float				disorder(t_list **a);
void				three(t_list **a, t_oper *opers);
void				find_min(t_list **b, t_oper *opers);
void				five(t_list **a, t_list **b, t_oper *opers);
void				four(t_list **a, t_list **b, t_oper *opers);
void				two(t_list **a, t_oper *opers);
void				putnbr(int total);
int					bench_pars(char **argv, t_bench *count, int argc);
int					method(t_bench *count);
void				start_sort(t_list **a, t_list **b, int alg, t_oper *opers);
int					start_point(int pars, t_list **a, t_list **b, t_vals *vals);
int					ft_putnbr_printf(int n, int fd);
int					ft_putchar(char c, int fd);
int					ft_putstr_printf(char *s, int fd);
int					ft_putad(void *c, int fd);
int					ft_putunint(unsigned int n, int fd);
int					ft_putx(unsigned int a, int fd);
int					ft_putxx(unsigned int a, int fd);
int					ft_putperc(int fd);
int					ft_printf(const char *str, ...);
void				last_clean(t_list **a, t_list **b, t_vals *vals);
int					main(int argc, char **argv);
void				isbench(int alg, t_oper *opers, int number, float dis);

#endif
