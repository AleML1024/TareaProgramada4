FLAGS = -g -c --std=c++17 -fPIC

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o -o bin/tienda.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o -o bin/producto.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/tienda bin/main.o  bin/producto.o bin/tienda.o
	g++ -shared -o bin/libtienda.so obj/producto.o obj/tienda.o
	mkdir -p bin/include
	cp src/tienda.h  src/producto.h ./bin/include
	
	
	
test:
	mkdir -p bin
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) tests/tienda_tests.cpp -o bin/tienda_tests.o
	g++ $(FLAGS) tests/productos_tests.cpp -o bin/productos_tests.o
	g++ -g -o bin/tests bin/tienda.o bin/producto.o bin/tienda_tests.o bin/productos_tests.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin	
	rm -Rf *.dat
