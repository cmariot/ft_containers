/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_test.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:37:09 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/09 22:54:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

static void	exit_child(t_test **test, int *fd, int *stdout_backup, int status)
{
	clear_test_list(test);
	close(*fd);
	dup2(*stdout_backup, 1);
	close(*stdout_backup);
	exit(status);
}

/* Use a function ptr to launch the test function. */

static void	*execute(void *ptr)
{
	t_test	*test;

	test = (t_test *)ptr;
	test->status = (*test).test_add();
	return (test);
}

/*
 * Create a thread which call the execute function.
 * The process continue and goes into an infinite loop : 
 *	- If current_time > TIMEOUT_TIME -> break
 *	- Or if the test_status is different than default value -> break
 */

static int	create_threads(t_test **test)
{
	pthread_t	thread_id;
	size_t		init_time;

	init_time = get_time();
	if (pthread_create(&thread_id, NULL, &execute, *test))
	{
		std::cerr << "Error : Thread creation failed." << std::endl;
		return (42);
	}
	while (1)
	{
		if (check_timeout(init_time))
		{
			pthread_cancel(thread_id);
			pthread_join(thread_id, NULL);
			return (TIMEOUT);
		}
		else if ((*test)->status != -2)
			break ;
		usleep(500);
	}
	pthread_join(thread_id, NULL);
	return ((*test)->status);
}

/*
 * Create a tmp file and redirect the STDOUT output into this file.
 */

static int	output_redirection(int *fd, int *stdout_backup, t_test *test)
{
	*fd = open((char *)std::string(test->filename).c_str(), O_RDWR | O_CREAT | O_TRUNC, 0640);
	if (*fd == -1)
	{
		std::cerr << "Error, file opening failed." << std::endl;
		return (1);
	}
	*stdout_backup = dup(1);
	dup2(*fd, 1);
	return (0);
}

/*
 * Fork the process :
 *
 *	- in the child : STDOUT redirection in a tmp file & create a thread
 *	  (one for the execution, one for the timer)
 *
 *	- in the parent : wait the exxit status of the child
 */

int	execute_test(t_test **test, std::ofstream &log_file)
{
	pid_t	pid;
	int		status;
	int		fd;
	int		stdout_backup;

	pid = fork();
	if (pid == -1)
	{
		std::cerr << "Error, fork failed." << std::endl;
		return (1);
	}
	else if (pid == 0)
	{
		if (output_redirection(&fd, &stdout_backup, *test))
		{
			clear_test_list(test);
			close(fd);
			return (1);
		}
		status = create_threads(test);
		log_file.close();
		exit_child(test, &fd, &stdout_backup, status);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			(*test)->status = WEXITSTATUS(status);
		else if WIFSIGNALED(status)
			(*test)->status = WTERMSIG(status);
	}
	return (0);
}
