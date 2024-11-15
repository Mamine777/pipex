/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:50:09 by mokariou          #+#    #+#             */
/*   Updated: 2024/11/15 17:52:08 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include "utils/printf/ft_printf.h"
# include "utils/libft/libft.h"

int		open_file(char **av, int file);
char	*find_cmd(char *cmd, char **env, char **av);
void	ft_free(char **strs);
void	exc1(int infile, char **av, int fd[2], char **env);
void	exc2(int outfile, char **av, int fd[2], char **env);
int		excute(char **env, char **av, int fds[2]);

#endif