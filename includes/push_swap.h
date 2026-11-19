/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:50:50 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/10 15:36:04 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_mode
{
	ADAPTIVE,
	MEDIUM,
	COMPLEX,
	SIMPLE
}	t_mode;

typedef struct s_node
{
    int     value;
    int     index;
    struct  s_node *next;
}   t_node;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

void	free_split(char **tokens);
void    get_index(t_node **stack_a);
void	free_stacks(t_node **a, t_node **b);
long	ft_atol(const char *s);
long	count_inversions(t_node a);
char	*strategy_name(t_mode mode, t_node a);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_a, t_node **stack_b);
void    swap(t_node **stack);
void    sa(t_node **stack_a);
void    sb(t_node **stack_b);
void    ss(t_node **stack_a, t_node **stack_b);
void    rotate(t_node **stack);
void    ra(t_node **stack_a);
void    rb(t_node **stack_b);
void    rr(t_node **stack_a, t_node **stack_b);
void    rrotate(t_node **stack);
void    rra(t_node **stack_a);
void    rrb(t_node **stack_b);
void    rrr(t_node **stack_a, t_node **stack_b);
void    find_max(t_node **stack_a, t_node **stack_b, int total);
void    sort_medium(t_node **stack_a,t_node **stack_b);
void	emit_op(int op, char *name);
int		*parse_args(int argc, char **argv, int start, int *size);
int		parse_flags(int argc, char **argv, t_mode *mode, int *bench);
int		is_valid_number(char *s);
int		in_int_range(long n);
int		has_duplicate(int *tab, int size);
int		stack_init(t_node **a, int *tab, int size);
int		is_sorted(t_node *a);
int		count_nodes(t_node *a);
void	free_stack(t_node **s);
int		*op_counts(void);
int		print_error(void);
int		get_disorder(t_node a);
int 	ft_sqrt(int nb);
void	sort_radix(t_node **a, t_node **b);
t_node 	*find_min(t_node **stack);
int 	get_position(t_node **stack, t_node *target);
int 	get_total(t_node **stack);
void    sort_simple(t_node **stack_a, t_node **stack_b);
void	sort_stack(t_node **a, t_node **b, t_mode mode);
void	run_sort(t_node **a, t_node **b, t_mode mode, int bench);
void	print_bench(long inv, long pairs, char *strategy);

#endif
