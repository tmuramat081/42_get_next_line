/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:49:25 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/07 17:32:05 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_buffer(int fd, char *buff, t_buff *input)
{	
	ssize_t	buf_size;
	char	*tmp_str;

	buf_size = read(fd, buff, BUFFER_SIZE);
	if (buf_size == -1)
	{
		input->sts = ERROR;
		return ;
	}
	else if (buf_size == 0)
		input->sts = END_OF_FILE;
	buff[buf_size] = '\0';
	tmp_str = ft_strjoin(input->mem, buff);
	free(input->mem);
	input->mem = tmp_str;
	input->ptr_nl = ft_strchr(input->mem, '\n');
	if (input->ptr_nl)
		input->sts = RETURN;
}

char	*output_one_line(t_buff *input)
{
	char	*ret_line;
	char	*tmp_memory;

	if (*input->mem == '\0')
		return (NULL);
	else if (input->sts == END_OF_FILE && !input->ptr_nl)
		return (input->mem);
	tmp_memory = ft_strdup(input->ptr_nl + 1);
	*(input->ptr_nl + 1) = '\0';
	ret_line = ft_strdup(input->mem);
	free(input->mem);
	input->mem = tmp_memory;
	input->ptr_nl = ft_strchr(input->mem, '\n');
	if (!input->ptr_nl && input->sts == RETURN)
		input->sts = CONTINUE;
	return (ret_line);
}

char	*get_next_line(int fd)
{
	static t_buff	input[1024];
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || 1024 < fd || input[fd].sts == END_OF_FILE)
		return (NULL);
	if (!input[fd].mem)
		input[fd].mem = ft_strdup("");
	while (input[fd].sts == CONTINUE)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		read_buffer(fd, buff, &input[fd]);
		if (input[fd].sts == ERROR)
		{
			free(buff);
			return (NULL);
		}
		free(buff);
	}
	return (output_one_line(&input[fd]));
}
