/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:20:13 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/14 03:06:00 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCH_H
#define CATCH_H

typedef struct	s_scale
{
	char			*tone;
	char			*semi;
	struct s_scale	*next;
}	t_scale;

extern void	ft_get_acorde(char *line, t_scale *head, int fd);
#endif
