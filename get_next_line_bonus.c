/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:36:57 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/10 18:13:21 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (lst != NULL)
	{
		aux = lst;
		lst = lst->next;
	}
	return (aux);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	del((*lst)->str_buf);
	free(*lst);
	*lst = NULL;
}

int	init_list(t_list **list, int fd)
{
	char	*str;
	int		read_bytes;

	while (!find_new_line(*list))
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return (1);
		read_bytes = read(fd, str, BUFFER_SIZE);
		if (read_bytes < 1)
		{
			free(str);
			return (0);
		}
		str[read_bytes] = '\0';
		fill_list(list, str);
	}
	return (0);
}

void	clean_list(t_list **list)
{
	t_list	*rest_node;
	t_list	*last_node;
	char	*str;
	int		i;
	int		j;

	rest_node = malloc(sizeof(t_list));
	str = malloc(BUFFER_SIZE + 1);
	if (!str || !rest_node)
	{
		free(rest_node);
		free(str);
		return (ft_lstclear(list, free));
	}
	last_node = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		str[j++] = last_node->str_buf[i];
	str[j] = '\0';
	rest_node->str_buf = str;
	rest_node->next = NULL;
	clear_mem(list, rest_node, str);
}

char	*get_next_line(int fd)
{
	static t_list	*list[OPEN_MAX];
	char			*str;
	int				len_str;
	int				flag;

	if (fd < 0 || fd >= OPEN_MAX || read(fd, &str, 0) < 0 || BUFFER_SIZE < 1)
		return (ft_lstclear(&list[fd], free), NULL);
	flag = init_list(&list[fd], fd);
	if (list[fd] == NULL || flag == 1)
		return (ft_lstclear(&list[fd], free), NULL);
	len_str = count_chars(list[fd]);
	str = malloc(len_str + 1);
	if (!str)
		return (ft_lstclear(&list[fd], free), NULL);
	my_strcpy(str, list[fd]);
	clean_list(&list[fd]);
	return (str);
}
/*
int main(void)
{
	int fd;
	int line = 1;
	char *lines;
	fd = open("example.txt", O_RDONLY);
	
	printf("\nline%d->%s", line++, lines = get_next_line(fd));
	printf("\nline%d->%s", line++, lines = get_next_line(fd));
	printf("\nline%d->%s", line++, lines = get_next_line(fd));
	printf("\nline%d->%s", line++, lines = get_next_line(fd));
	return (0);
}
*/
