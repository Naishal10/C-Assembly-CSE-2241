#Naishal Patel
all: lab5

lab6: lab6.o
	gcc -O -o $@ $^

lab6.o: lab6.s 
	gcc -g -c $< -o $@

lab6.zip: makefile lab6.s readme.txt
	zip $@ $^

tags: *.c
	ctags -R .

headers: *.c tags
	headers.sh

clean:
	rm -f lab5 *.o tags

%.o: %.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -c $< -o $@

