INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = clang++
CPPFLAGS = -Wall -std=c++11 -g 

all: $(BIN)/testdiccionario

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxyfile

	
# ************ Compilación de módulos ************

testdiccionario: 
$(BIN)/testdiccionario : $(OBJ)/testdiccionario.o 
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o

$(OBJ)/testdiccionario.o : $(INC)/diccionario.h $(SRC)/testdiccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp 

$(OBJ)/diccionario.o: $(INC)/diccionario.h $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f -r $(BIN)/* doc/html/* doc/latex/*
