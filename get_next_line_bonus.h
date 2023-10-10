/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:37:27 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/10 17:32:23 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		init_list(t_list **list, int fd);
int		find_new_line(t_list *list);
void	fill_list(t_list **list, char *str);
int		count_chars(t_list *list);
void	my_strcpy(char *str, t_list *list);
void	clean_list(t_list **list);
t_list	*ft_lstlast(t_list *lst);
void	clear_mem(t_list **list, t_list *rest_node, char *str);

#endif
