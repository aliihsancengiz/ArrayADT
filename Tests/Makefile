CC=g++

GTESTINSTALLDIR=C:/tdd/googletest-master
GTESTINCLUDE_PATH=$(GTESTINSTALLDIR)/googletest/include
GTESTLINK_PATH=$(GTESTINSTALLDIR)/build/lib

GTESTLIBS=-lgtest -lgtest_main

TestFileName=testArrayAdt

EXECEXTENSION=.exe

$(TestFileName)$(EXECEXTENSION) : ../Array.h ../Array.c
	$(CC) $(TestFileName).cpp -I $(GTESTINCLUDE_PATH) -L $(GTESTLINK_PATH) $(GTESTLIBS) -o $(TestFileName)

run:
	./$(TestFileName).exe