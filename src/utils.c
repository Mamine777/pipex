/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:49 by mokariou          #+#    #+#             */
/*   Updated: 2024/11/15 17:48:22 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	*find_direc(char *cmd, char **splited)
{
	char	*directoy;
	char	*temp;
	int		i;

	i = 0;
	while (splited[i])
	{
		temp = ft_strjoin(splited[i], "/");
		directoy = ft_strjoin(temp, cmd);
		free(temp);
		if (access(directoy, X_OK) == 0)
			return (directoy);
		free(directoy);
		i++;
	}
	return (NULL);
}

static char	*ft_path(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd(char *cmd, char **env, char **av)
{
	char	*path;
	char	**splited;
	char	*directory;

	(void) av;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	path = ft_path(env);
	if (!path)
		return (NULL);
	splited = ft_split(path, ':');
	directory = find_direc(cmd, splited);
	if (!directory)
	{
		ft_free(splited);
		return (ft_printf("command not found\n"), NULL);
	}
	ft_free(splited);
	return (directory);
}
