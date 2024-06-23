/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:44:29 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/23 16:18:57 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct t_list
{
	int				data;
	int				s_index;
	int				cost_a;
	int				cost_b;
	int				pos;
	struct t_list	*next;
}					t_node;

// main
void				push_swap(t_node **a);

// validate
int					check_dup(char **str);
int					is_valid(char **str);

// utilities
t_node				*lst_last(t_node *lst);
int					is_sorted(t_node *stack);
void				error_exit(int nb);
void				free_array(char ***str);
void				free_lst(t_node **stack);

// create stack
void				build_stack(char **storage, t_node **a);

// sorting index
int					find_len(t_node *stack);
void				sort_array(int **tab, int size);
void				assign_index(int len, t_node **stack, int *sorted_list);
void				sorting_index(t_node **stack);

// operations
void				swap(t_node *stack, char *str);
void				push(t_node **stack_1, t_node **stack_2, char *str);
void				rotate(t_node **stack, char *str, int cost);
void				rev_rotate(t_node **stack, char *str, int cost);
void				sort_three(t_node **stack);

// midpoint
void				midpt_sort(t_node **a, t_node **b);
void				send_to_b(t_node **a, t_node **b, int *total_nodes_to_go);
int					find_midpt(t_node *stack);
void				push_to_b(t_node **a, t_node **b, int *i,
						int *total_nodes_to_go);

// cost
void				find_cost(t_node **a, t_node **b);
int					find_cheapest(t_node **b);

// do both
void				rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
void				rev_rotate_both(t_node **a, t_node **b, int cost_a,
						int cost_b);

// bidirectional moves counter
int					count_forward_moves(t_node *stack, int point);
int					count_backward_moves(t_node *stack, int point);

// target_finder
int					get_target_index(t_node **a, t_node **b);
void				find_min_and_max(int *a_min, int *a_max, t_node *temp);
void				check_min_and_max_diff(int *min_pos_diff, int *max_diff,
						t_node **a, t_node **b);

// order_stack_a
void				sort_stack_a(t_node **stack, int point);

// allocate position
void				assign_pos(t_node **a, t_node **b);

// reorder_both
void				reorder_a_b(int cheapest_pos, t_node **a, t_node **b);

// checker
void				checker(t_node **a, t_node **b);
// void	val_and_use_ins(t_node **a, t_node **b, char *instructions);

#endif
