/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:21:46 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/14 00:41:18 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"
#include "hate.h"
#include "get_next_line.h"

extern void	ft_print_winner(t_dict *head, char **data)
{
	float		score[2];
	size_t		i;
	size_t		j;
	t_dict		*tmp;
	static int	k = 1;

	memset(score, 0, sizeof(float) * 2);
	i = -1;
	while (data[++i])
	{
		tmp = head;
		while (tmp)
		{
			j = -1;
			while (data[i][++j])
			{
				if (data[i][j] == tmp->letter)
					score[i] += tmp->value;
			}
			tmp = tmp->next;
		}
	}
	if (score[0] > score[1])
		printf("Case #%d: %s\n", k, data[0]);
	else if (score[1] > score[0])
		printf("Case #%d: %s\n", k, data[1]);
	else
		printf("Case #%d: -\n", k);
	k++;
}

extern void	ft_free_head(t_dict *head)
{
	t_dict *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

extern void	ft_substitute(char	*str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ':')
			str[i] = ',';
		else if (str[i] == '=')
			str[i] = ',';
	}
}

static void	ft_add_back(t_dict *node, t_dict **head)
{
	t_dict	*tmp;

	if (!*head)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}
extern void	ft_create_list_1(char **dict, t_dict **head)
{
	size_t	i;
	t_dict	*node;
	int		num[2];
	char	**tmp;

	i = 0;
	while (dict[i])
	{
		node = calloc(sizeof(t_dict), 1);
		node->letter = dict[i++][0];
		if (strchr(&dict[i][0], '/'))
		{
			tmp = ft_split(dict[i], '/');
			num[0] = atoi(tmp[0]);
			num[1] = atoi(tmp[1]);
			ft_free_d2(tmp);
			node->value = (float)num[0] / (float)num[1];
		}
		else
			node->value = atoi(dict[i]);
		ft_add_back(node, head);
		i++;
	}
}
