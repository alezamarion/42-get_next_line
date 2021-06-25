/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:07:33 by azamario          #+#    #+#             */
/*   Updated: 2021/06/23 21:02:02 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_line_break(char *s_line)
{
	int	i;

	i = 0;
	if (s_line == 0)
		return (-1);
	while (s_line[i] != '\0')
	{
		if (s_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	return_line(char **save, char **line)
{
	int		i;
	char	*tmp;

	i = find_line_break(*save);
	if (i >= 0)
	{
		*line = ft_substr(*save, 0, i);						//4. Allocates and eturns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
		tmp = ft_substr(*save, i + 1, ft_strlen(*save));	//4. ft_strlen -> pega após o '\n'até o final
		free(*save);
		*save = tmp;
		tmp = NULL;
		return (1);
	}
	else
	{
		*line = ft_substr(*save, 0, ft_strlen(*save));						//4. Allocates and eturns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	char		*tmp;
	static char	*save;
	ssize_t		ret;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0) 			// tratamento de erros | read 0 para procurar erros sem mover o cursor
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';								//já copiou arquivo para buffer, agora coloca o null
		if (save == NULL)								//coloca o buffer no save
			save = ft_strdup(buffer);					//1. allocates memory to copy of str s1, does the copy, returns pointer to it.

		else
		{
			tmp = ft_strjoin(save, buffer);				//2. alocates and returns a new string, result of concatenation of ’s1’ and ’s2’.
			free(save);									//save não era null, já tinha algo da passagem anterior, strjoin
			save = tmp;
		}
		if (ft_strchr(save, '\n'))						//3. locates first occurrence of c (converted to a char) in the string pointed to by s. Terminating null character is considered part of the string: if c is `\0', the functions locate the terminating `\0'.
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (return_line(&save, line));
}
