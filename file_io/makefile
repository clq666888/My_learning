CC:=gcc

fopen_test: fopen_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fclose_test: fclose_test.c
	gcc -o fclose_test fclose_test.c
	./fclose_test
	-rm fclose_test