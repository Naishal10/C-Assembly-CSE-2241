
all: lab4

lab4: main.o Stack1.o Stack2.o Queue1.o Queue2.o
	gcc -O -pg -o $@ $^

main.o: main.c lab4.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c $< -o $@

Stack1.o: Stack1.c lab4.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c $< -o $@

Stack2.o: Stack2.c lab4.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c $< -o $@

Queue1.o: Queue1.c lab4.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c $< -o $@

Queue2.o: Queue2.c lab4.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c $< -o $@

lab4.zip: makefile *.c *.h readme.txt gmon.out lab4out
	zip $@ $^
	rm -rf install
	mkdir install
	unzip lab4.zip -d install
	make -C install -r lab4
	rm -rf install

tags: *.c
	ctags -R .

headers: *.c tags
	headers.sh

clean:
	rm -f lab4 *.o tags gmon.out

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c $< -o $@

