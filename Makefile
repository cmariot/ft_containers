all :
	@make test -C unit_tests/vector --no-print-directory

fclean :
	@make fclean -C unit_tests/vector --no-print-directory

re :
	@make re -C unit_tests/vector --no-print-directory

leaks :
	@make leaks -C unit_tests/vector --no-print-directory

showleaks :
	@make showleaks -C unit_tests/vector --no-print-directory
