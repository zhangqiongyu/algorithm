object=main.o MaxLoad.o
load:$(object)
	g++ $(object) -o load
main.o:main.cpp
	gcc -c main.cpp 
MaxLoad.o:MaxLoad.cpp
	gcc -c MaxLoad.cpp
.PHPNY:clean
clean:
	rm $(object) load
