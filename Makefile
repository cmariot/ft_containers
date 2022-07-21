all :
	@make -C unit_tests/vector --no-print-directory
	@make -C unit_tests/map --no-print-directory
	@ ./unit_tests/vector/vector_tests
	@ ./unit_tests/map/map_tests

fclean :
	@make fclean -C unit_tests/vector --no-print-directory
	@make fclean -C unit_tests/map --no-print-directory
	@rm -f *.log

re :
	@make re -C unit_tests/vector --no-print-directory
	@make re -C unit_tests/map --no-print-directory

leaks :
	@make leaks -C unit_tests/vector --no-print-directory
	@make leaks -C unit_tests/map --no-print-directory

showleaks :
	@make showleaks -C unit_tests/vector --no-print-directory
	@make showleaks -C unit_tests/map --no-print-directory
