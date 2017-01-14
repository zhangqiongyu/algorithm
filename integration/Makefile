object=main.o integration.o
integral:$(object)
	g++ -o integral $(object)
main.o:main.cpp
	gcc -c main.cpp
integration.o:integration.cpp
	gcc -c integration.cpp
.PHONY:clean
clean:
	rm $(object) integral
