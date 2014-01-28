CPPFLAGS = --std=c++0x

.PHONEY : all clean

all : 244

244 : 244.o
	g++ $(CPPFLAGS) -g  $< -o $@

%.o : %.cpp
	g++ $(CPPFLAGS)  -g -c  $< -o $@ 

clean:
	rm -r *~ *.o