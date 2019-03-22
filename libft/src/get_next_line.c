/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:48:51 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/06 16:33:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		ft_verif_fin(char **str, long int ret, char **line)
{
	if (ret != -1 && *str && **str != '\0')
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
		return (1);
	}
	return (0);
}

static int		ft_verif_buff(char **str, char *buff, char **line)
{
	char	*temp;

	if ((temp = ft_strchr(buff, '\n')))
	{
		*temp = '\0';
		if (*str)
		{
			*line = ft_strjoin(*str, buff);
			ft_strdel(str);
		}
		else
			*line = ft_strdup(buff);
		(str) ? *str = ft_strdup(temp + 1) : 0;
		ft_strdel(&buff);
		return (1);
	}
	if (*str)
	{
		temp = ft_strjoin(*str, buff);
		ft_strdel(str);
		*str = temp;
	}
	else
		*str = ft_strdup(buff);
	return (0);
}

static int		ft_verif_str(char **str, char **line)
{
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	if ((temp = ft_strchr(*str, '\n')))
	{
		*temp = '\0';
		*line = ft_strdup(*str);
		temp2 = ft_strdup(temp + 1);
		ft_strdel(str);
		*str = ft_strdup(temp2);
		ft_strdel(&temp2);
		return (1);
	}
	return (0);
}

static t_file	*ft_verif_fd(t_file **liste, int fd)
{
	t_file	*temp2;
	t_file	*temp1;

	temp1 = NULL;
	temp2 = NULL;
	temp2 = *liste;
	while (temp2)
	{
		if (temp2->fd == fd)
			return (temp2);
		temp1 = temp2;
		temp2 = temp2->next;
	}
	if (!(temp2 = (t_file*)ft_lstnew(0, fd)))
		return (NULL);
	if (temp1)
		temp1->next = temp2;
	else
		*liste = temp2;
	temp2->fd = fd;
	return (temp2);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*liste;
	t_file			*file;
	char			*buff;
	long int		ret;

	*line = NULL;
	file = NULL;
	buff = NULL;
	if (fd < 0 || BUFF_SIZE < 1 || !(file = ft_verif_fd(&liste, fd)))
		return (-1);
	if ((file->str) && ft_verif_str(&(file->str), line))
		return (1);
	buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && ret <= BUFF_SIZE)
	{
		buff[ret] = '\0';
		if ((ft_verif_buff(&(file->str), buff, line)))
			return (1);
	}
	ft_strdel(&buff);
	if (ft_verif_fin(&(file->str), ret, line))
		return (1);
	if (ret < 0)
		return (-1);
	return (ret == 0) ? (0) : (1);
}
