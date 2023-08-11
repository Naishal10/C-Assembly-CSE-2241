#Naishal Patel
all: lab5

lab5: encrypt.o
	gcc -O -o $@ $^

encrypt.o: encrypt.s 
	gcc -g -c $< -o $@

lab5.zip: makefile encrypt.s expectedOutput1.txt readme.txt input1.txt
	zip $@ $^

tags: *.c
	ctags -R .

headers: *.c tags
	headers.sh

clean:
	rm -f lab5 *.o tags

%.o: %.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -c $< -o $@
