my_ls_out: lsmain.o create.o print.o sortnoprev.o
	cc lsmain.o create.o print.o sortnoprev.o -o my_ls_out

lsmain.o: lsmain.c
	cc -c lsmain.c 

create.o: create.o
	cc -c create.c 

print.o: print.c
	cc -c print.c

sortnoprev.o: sortnoprev.c
	cc -c sortnoprev.c

#Makefile for LS command
