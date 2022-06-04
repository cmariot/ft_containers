/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:29:59 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/04 14:50:53 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/time.h>

# include <iostream>
# include <iomanip>
# include <fstream>

# define OK 0
# define KO 255
# define TIMEOUT 32
# define TIMEOUT_DELAY 10

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

typedef struct s_test {
	std::string		function;				// Function name
	std::string		test_name;				// Test name
	int				(*test_add)(void);		// Function pointer 
	int				status;					// Exit status
	std::string		filename;				// Log file for this test
	std::string		expected_output;		// If expected != output -> Error
	struct s_test	*next;					// Pointer on the next test
}	t_test;

/* TEST_LST_UTILS.C */

void			load_test(t_test **test, std::string function, std::string test_name,
					void *function_add, std::string expected_output);
void			ft_addtest_lst(t_test **test, t_test *new_test);
t_test			*ft_newtest_lst(std::string *function, std::string *test_name,
					void *test_add, std::string *expected_output);
t_test			*ft_lasttest_lst(t_test *test);
void			ft_cleartest_lst(t_test **test, bool opt);

/* LAUNCH_TESTS.C */

int				launch_tests(t_test **test);
void			execute_test(t_test **test);
int				create_threads(t_test **test);
void			*execute(void *add);

/* LOGFILES.C */

std::string		filename_to_str(std::string file);
void			output_redirection(int *fd, int *stdout_backup, t_test *test);
void			exit_child(t_test **test, int *fd, int *stdout_backup, int status);

/* OUTPUT.C */

std::ofstream	create_log_file(t_test *test);
void			check_stdout_output(t_test *test, int fd);
void			print_test_output(t_test *test, int test_number, std::ofstream &fd, bool cout);
int				display_results(int count_of_succeeded_tests, int total_number_of_tests);

/* TIMEOUT.C */

void			*execute(void *add);
size_t			get_time(void);
int				check_timeout(size_t init_time);

#endif
