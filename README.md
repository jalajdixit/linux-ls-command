# linux-ls-command
Implementing the LS command of linux terminal using system calls with few options

Options supported in my LS command
```
 -l : show long list
 -a : show all hidden files
 -s : show block size
 -i : show inode number
 -r : show reverse list
Apart from these options we can also give multiple paths.
```

* myheaher.h   : header file for project
* makefile     : makefile for project
* lsmain.c     : main() function for LS command
* create.c     : create list of files in directory
* print.c      : print the list on screen
* sortnoprev.c : sort the list for printing
