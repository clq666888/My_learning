objects := demo.o my_function.o

demo: $(objects)
	gcc $(objects) -o demo	

demo.o: demo.c my_function.h
	gcc -c demo.c -o demo.o

my_function.o: my_function.c my_function.h
	gcc -c my_function.c -o my_function.o

# demo.o: my_function.h 

# my_function.o: my_function.h 

clean:
	-rm demo.o my_function.o demo.c demo.s demo.i


