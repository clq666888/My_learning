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

read_test: read_test.c
	gcc -o read_test read_test.c
	-./read_test
	-rm read_test

write_test: write_test.c
	gcc -o write_test write_test.c
	-./write_test
	-rm write_test

access_test: access_test.c
	gcc -o access_test access_test.c
	-./access_test
	-rm access_test


