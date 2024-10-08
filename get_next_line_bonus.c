/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:49:25 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/10 12:44:17 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_memory(t_minfo *input)
{
	free (input->mem);
	input->mem = NULL;
	return (NULL);
}

char	*output_one_line(t_minfo *input)
{
	char	*ret_line;
	char	*tmp_memory;

	if (*input->mem == '\0')
		return (free_memory(input));
	else if (input->sts == END && !input->ptr_nl)
		return (input->mem);
	tmp_memory = ft_strdup(input->ptr_nl + 1);
	if (!tmp_memory)
		return (free_memory(input));
	*(input->ptr_nl + 1) = '\0';
	ret_line = ft_strdup(input->mem);
	if (!ret_line)
		return (free_memory(input));
	free(input->mem);
	input->mem = tmp_memory;
	input->ptr_nl = ft_strchr(input->mem, '\n');
	if (!input->ptr_nl)
		input->sts = CONTINUE;
	return (ret_line);
}

void	read_buffer(int fd, char *buff, t_minfo *input)
{	
	ssize_t	buf_size;
	char	*tmp_mem;

	buf_size = read(fd, buff, BUFFER_SIZE);
	if (buf_size == -1)
	{
		input->sts = ERROR;
		return ;
	}
	else if (buf_size == 0)
		input->sts = END;
	buff[buf_size] = '\0';
	tmp_mem = ft_strjoin(input->mem, buff);
	if (!tmp_mem)
	{
		input->sts = ERROR;
		return ;
	}
	free(input->mem);
	input->mem = tmp_mem;
	input->ptr_nl = ft_strchr(input->mem, '\n');
	if (input->ptr_nl)
		input->sts = RETURN;
}

char	*get_next_line(int fd)
{
	static t_minfo	input[FD_MAX - 1];
	char			*buff;

	if (fd < 0 || FOPEN_MAX < fd || BUFFER_SIZE <= 0 || input[fd].sts == END)
		return (NULL);
	if (!input[fd].mem)
	{
		input[fd].mem = ft_strdup("");
		if (!input[fd].mem)
			return (NULL);
	}
	while (input[fd].sts == CONTINUE)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (free_memory(&input[fd]));
		read_buffer(fd, buff, &input[fd]);
		free(buff);
		buff = NULL;
	}
	if (input[fd].sts == ERROR)
		return (free_memory(&input[fd]));
	return (output_one_line(&input[fd]));
}
