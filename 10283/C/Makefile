.PHONY : all doc clean

MAINNAME = 10283
CXX = gcc
CPPFLAGS = -g 

all : $(MAINNAME)

$(MAINNAME) : $(MAINNAME).o
	$(CXX) $(CPPFLAGS)  $< -o $@

%.o : %.c
	$(CXX) $(CPPFLAGS) -c  $< -o $@ 


clean:
	@ rm -f *.o *~ core $(MAINNAME)

INPUT = ../input
test:	$(MAINNAME)
	@ echo "input:"
	@ cat $(INPUT)
	@ echo "output:"
	@ cat $(INPUT) | ./$(MAINNAME)