/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:29:59 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/03 15:47:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdbool.h>

# include <iostream>

# define OK 0
# define KO 255
# define TIMEOUT 32

# define TIMEOUT_DELAY 5

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

typedef struct s_test {
	std::string	function;
	std::string	test_name;
	int			(*test_add)(void);
	int			status;
	std::string	filename;
	std::string	expected_output;
	struct s_test	*next;
}	t_test;

/* LAUNCH_TESTS.C */

int		launch_tests(t_test **test);
void	execute_test(t_test **test);
int		create_threads(t_test **test);
void	*execute(void *add);

/* LIBFT.C */

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);

/* LOGFILES.C */

std::string	filename_to_str(std::string file);
void	output_redirection(int *fd, int *stdout_backup, t_test *test);
void	exit_child(t_test **test, int *fd, int *stdout_backup, int status);

/* OUTPUT.C */

void	check_stdout_output(t_test *test, int fd);
void	print_test_output(t_test *test, int test_number, int log_file);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar(char c);
int		display_results(int count_of_succeeded_tests,
			int total_number_of_tests);

/* RESULT_FILE.C */

int		create_log_file(t_test *test);

/* TEST_LST_UTILS.C */

t_test	*ft_lasttest_lst(t_test *test);
void	ft_addtest_lst(t_test **test, t_test *new_test);
void	ft_cleartest_lst(t_test **test, bool opt);
t_test	*ft_newtest_lst(char *function, char *test_name,
			void *test_add, char *expected_output);
void	load_test(t_test **test, char *function, char *test_name,
			void *function_add, char *expected_output);

/* TIMEOUT.C */

void	*execute(void *add);
size_t	get_time(void);
int		check_timeout(size_t init_time);

#endif
