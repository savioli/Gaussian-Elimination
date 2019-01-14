SRC=main.cpp
PROGRAM_NAME = main

${PROGRAM_NAME}: Matrix.o GaussianElimination.o main.o
	g++ -o ${PROGRAM_NAME} Matrix.o GaussianElimination.o main.o

GaussianElimination.o: GaussianElimination.cpp
	g++ -o GaussianElimination.o -c GaussianElimination.cpp

Matrix.o: Matrix.cpp
	g++ -o Matrix.o -c Matrix.cpp

main.o: main.cpp GaussianElimination.h Matrix.h
	g++ -o main.o -c main.cpp

clean:
	rm -rf *.o

mrproper: clean
	rm -rf main

run:
	@$(MAKE) && ./$(PROGRAM_NAME) $(ARGS)
