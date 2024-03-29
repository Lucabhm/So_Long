/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:06:13 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/13 22:22:32 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *buffer, int *byt_size);
char	*strjoin(char *newline, char *buffer);
char	*clean_buffer(char *buffer);
char	*next_line(char *buffer);
char	*ft_strchrg(const char *word, int letter);
size_t	ft_strleng(const char *str);
char	*freeup(char *buffer);
char	*writeline(char *buffer, int fd, int *byt_size);

#endif