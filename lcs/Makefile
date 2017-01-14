object=main.o lcs.o
lcs:$(object)
	g++ -o lcs $(object)
main.o:main.cpp
	gcc -c main.cpp
lcs.o:lcs.cpp
	gcc -c lcs.cpp
.PHONY:clean
clean:
	rm $(object) lcs
