/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:35:51 by bportell          #+#    #+#             */
/*   Updated: 2025/05/06 13:19:27 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	command_one(int pfd[], char *argv[], char *envp[])
{
	int		fd_in;
	char	**cmd;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("ERROR: can not open the infile!\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd_in, STDIN_FILENO);   /*entrada do cmd 1 = file1*/
	dup2(pfd[1], STDOUT_FILENO); /*saida do cmd 1 = escrever no pipe*/
	close(pfd[0]);               /*fecha os ficheiros de leitura*/
	close(pfd[1]);
	close(fd_in);
	cmd = ft_split(argv[2], ' ');
	if (!cmd)
	{
		perror("ERROR: can not split/read command one!\n");
		exit(EXIT_FAILURE);
	}
	execve(get_cmd_path(cmd[0], envp), cmd, envp);
	perror("ERROR: can not execute command one!\n");
	exit(EXIT_FAILURE);
}

void	command_two(int pfd[], char *argv[], char **envp)
{
	int		fd_out;
	char	**cmd;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror("ERROR: can not open/write in outfile!\n");
		exit(EXIT_FAILURE);
	}
	dup2(pfd[0], STDIN_FILENO);  /*entrada = pipe*/
	dup2(fd_out, STDOUT_FILENO); /*saida = outfile*/
	close(pfd[0]);
	close(pfd[1]);
	close(fd_out);
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
	{
		perror("ERROR: can not slipt/read command two!\n");
		exit(EXIT_FAILURE);
	}
	execve(get_cmd_path(cmd[0], envp), cmd, envp);
	perror("ERROR: can not execute command two!");
	exit(EXIT_FAILURE);
}
char	*get_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*tmp;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':'); /*+ 5 para ignorar o path=*/
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
			return (free_split(paths), full_path);
		free(full_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
