# Makefile for running tests.

EXECS= SHA512
# @ symbol stops the command from being printed to screen. Ref: https://stackoverflow.com/questions/9967105/suppress-echo-of-command-invocation-in-makefile
SHA512:	SHA512.c
	@gcc	-o	SHA512	SHA512.c
# Test Cases
test: SHA512 test.sh
	@./test.sh
# Remove the executables
clean:	
	rm	-f	$(EXECS)