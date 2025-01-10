/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:54:37 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/10 15:57:52 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	check_args_quoted(char **args)
{
	int		i;
	long	tmp;

	i = 0;
	if (!args[i])
		ft_error(args, 1);
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error(args, 1);
		if (ft_contains(tmp, args, i))
			ft_error(args, 1);
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error(args, 1);
		i++;
	}
	ft_free(args);
}

static void	check_args_direct(int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
			ft_error(NULL, 0);
		if (ft_contains(tmp, argv, i))
			ft_error(NULL, 0);
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error(NULL, 0);
		i++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		check_args_quoted(args);
	}
	else
	{
		check_args_direct(argc, argv);
	}
}
