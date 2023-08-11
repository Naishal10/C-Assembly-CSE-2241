#Naishal Patel

# Makefile for lab 1-4.
# change the last dependency for each new lab

all: lab3


#this entry has to change for lab 2 - 4
#NEVER compile .c files with this rule - it lacks needed compile time flags
#There is an entry below that turns .c files into .o files


lab3: main.o mkfile.c blank.o fedit.o search.o cat.o cd.o cp.o file.o help.o ls.o mkdir.o mv.o pwd.o rm.o rmdir.o  freeDirectory.o helper.o dirprint.o
	gcc -g -o $@ $^

main.o: main.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

cat.o: cat.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

cd.o: cd.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

cp.o: cp.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

file.o: file.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

mkfile.o: mkfile.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

help.o: help.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

ls.o: ls.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

mkdir.o: mkdir.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

mv.o: mv.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

pwd.o: pwd.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

rm.o: rm.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

rmdir.o: rmdir.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

dirprint.o: dirprint.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

freeDirectory.o: freeDirectory.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

helper.o: helper.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

blank.o: blank.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

fedit.o: fedit.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

search.o: search.c lab3headers.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@
#this is where you create an entry to build your zip file
#it will also update with new labs


lab3.zip: makefile *.c *.h readme.txt
	zip $@ $^
	#optional below here - remove old install folder
	rm -rf install
	#create install folder
	mkdir install
	#unzip to install folder
	unzip lab3.zip -d install
	make -C install -r lab3
	rm -rf install

#this entry stays for C code labs

tags: *.c
	ctags -R .

# this entry stays for C code labs
headers: *.c tags
	headers.sh

clean:
	rm -f lab3 *.o tags

#this entry takes care of C files depending on header files
#It has the flags for compiling the c code
#It you don't like makefiles, consider typing the following line a few
#thousand times this semester and reconsider.
#Be sure that this one doesn't get an inserted line break anywhere

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@


