/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:44:03 by mokariou          #+#    #+#             */
/*   Updated: 2024/11/15 17:49:49 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exc1(int infile, char **av, int fd[2], char **env)
{
	char	**cmd_path;
	char	*cmd_name;

	cmd_path = ft_split(av[3], ' ');
	if (!cmd_path)
		exit(1);
	cmd_name = find_cmd(cmd_path[0], env, av);
	if (!cmd_name)
	{
		ft_free(cmd_path);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	if (execve(cmd_name, cmd_path, env) == -1)
	{
		perror("Error executing command");
		ft_free(cmd_path);
		exit(1);
	}
}

void	exc2(int outfile, char **av, int fd[2], char **env)
{
	char	**cmd_path;
	char	*cmd_name;

	cmd_path = ft_split(av[3], ' ');
	if (!cmd_path)
		exit(1);
	cmd_name = find_cmd(cmd_path[0], env, av);
	if (!cmd_name)
	{
		ft_free(cmd_path);
		exit(1);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	if (execve(cmd_name, cmd_path, env) == -1)
	{
		perror("Error executing command");
		ft_free(cmd_path);
		exit(1);
	}
}

int	excute(char **env, char **av, int fds[2])
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (close(fd[1]), close(fd[0]), 1);
	if (pid == 0)
		exc1(fds[0], av, fd, env);
	pid2 = fork();
	if (pid2 < 0)
		return (close(fd[1]), close(fd[0]), 1);
	if (pid2 == 0)
		exc2(fds[1], av, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	fds[2];

	fds[0] = open(av[1], O_RDONLY);
	if (fds[0] < 0)
		return (1);
	fds[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fds[1] < 0)
		return (close(fds[0]), 1);
	if (ac != 5)
		return (ft_printf("ERROR : args\n"), 1);
	if (excute(env, av, fds) == -1)
		return (1);
	return (0);
}
