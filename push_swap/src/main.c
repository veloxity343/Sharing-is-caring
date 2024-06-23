/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:56:43 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/23 16:02:10 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->s_index;
	second = (*stack)->next->s_index;
	third = (*stack)->next->next->s_index;
	if ((first < second) && (second < third))
		return ;
	else if ((first < second) && (first < third))
	{
		swap(*stack, "sa");
		rotate(stack, "ra", 1);
	}
	else if ((first > second) && (first < third) && (second < third))
		swap(*stack, "sa");
	else if ((first < second) && (first > third))
		rev_rotate(stack, "rra", -1);
	else if ((first > second) && (first > third) && (second < third))
		rotate(stack, "ra", 1);
	else if ((first > second) && (first > third) && (second > third))
	{
		swap(*stack, "sa");
		rev_rotate(stack, "rra", -1);
	}
}

void	push_to_a(t_node **a, t_node **b)
{
	int	cheapest_pos;

	while (*b)
	{
		assign_pos(a, b);
		get_cost(a, b);
		cheapest_pos = get_cheapest(b);
		reorder_a_b(cheapest_pos, a, b);
		push(a, b, "pa");
	}
}

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
	{
		free_lst(a);
		exit(0);
	}
	else if (find_len(*a) == 2)
		swap(*a, "sa");
	else if (find_len(*a) == 3)
		sort_three(a);
	else if (find_len(*a) > 3)
	{
		midpt_sort(a, &b);
		sort_three(a);
	}
	push_to_a(a, &b);
	sort_stack_a(a, 0);
	free_lst(&b);
	return ;
}

static char	*build_string(char *argv[], char **stack)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!argv[i][0])
		{
			free(*stack);
			error_exit(0);
			ft_printf("Empty string for argument %d.", argv[i]);
		}
		*stack = ft_strjoin(*stack, argv[i++]);
		*stack = ft_strjoin(*stack, ' ');
	}
	return (*stack);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	char	*stack;

	if (argc < 2)
		ft_printf("Error: Insufficient arguments. Usage: %s <numbers>\n",
			argv[0]);
	else
	{
		stack = NULL;
		stack = build_string(argv, &stack);
		if (!is_valid(&stack) || !check_dup(&stack))
		{
			error_exit(0);
			ft_printf("Arguments must be unique numbers.\n");
		}
		a = NULL;
		build_stack(&buffer, &a);
		sorting_index(&a);
		push_swap(&a);
		free_lst(&a);
	}
	return (0);
}
