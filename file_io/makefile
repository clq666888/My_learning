CC:=gcc

fopen_test: fopen_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fclose_test: fclose_test.c
	gcc -o fclose_test fclose_test.c
	-./fclose_test
	-rm fclose_test

fputc_test: fputc_test.c
	gcc -o fputc_test fputc_test.c
	-./fputc_test
	-rm fputc_test

fputs_test: fputs_test.c
	$(CC) -o $@ $^
	-./$@
	-rm ./$@

fprintf_test: fprintf_test.c
	$(CC) -o $@ $^
	-./$@
	-rm ./$@

fgetc_test : fgetc_test.c
	$(CC) -o $@ $^
	-./$@
	-rm ./$@

fgets_test: fgets_test.c
	$(CC) -o $@ $^
	-./$@
	-rm ./$@

fscanf_test: fscanf_test.c
	$(CC) -o $@ $^
	-./$@
	-rm ./$@
