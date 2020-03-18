CC=gcc

LIBNAME=Array

CFLAGS = -g

EXECNAME=arrayadt
EXECEXT=.exe

$(EXECNAME)$(EXECEXT) : $(LIBNAME).c $(LIBNAME).h $(EXECNAME).c
	@echo Building project
	$(CC) -o $(EXECNAME)  $(LIBNAME).c $(LIBNAME).h $(EXECNAME).c $(CFLAGS)

run:
	@echo Running $(EXECNAME)$(EXECEXT)
	./$(EXECNAME)$(EXECEXT)

clean:
	@echo Removing $(EXECNAME)$(EXECEXT)
	rm $(EXECNAME)$(EXECEXT)
