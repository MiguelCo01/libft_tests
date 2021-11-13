# LIBFT TESTER

Simple LIBFT TESTER
/Core - includes tester code
/tests - includes all libft tests

grademe.sh - bash runner
my_config.sh - runner configuration

# How to
Include test on the test folder
Run grademe.sh --tests-only for results

# Add Tests

To add a new Test Block Create a Block Folder under Tests
and add a _setup.sh file

This file must have at least the variable
{PART}_REQUIRED_FUN including all the functions needed for this test block

To add a new Test, add a .c file in the Block Folder

## Basic Test.c File

#include "core.h"

int main(void)
{
	setup(argc, argv);
	describe("Suite name");
		it("test description);
		// Test code
	end_describe():
	return (test_results());
}


# Todos
[ ] include Forbidden Function Check
[ ] include per block compilation code
[ ] incllude single test run
[ ] correct norminete
[ ] Auto Install Lib BSD
