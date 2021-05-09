.PHONY:all clean
all:main
GCC=g++
CFLAG=-Wall -g

main:main.cpp
	$(GCC) $< -o $@ $(CFLAG)

clean:
	rm -rf *.o main