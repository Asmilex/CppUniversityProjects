INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = clang++
CPPFLAGS = -Wall -std=c++17 -O2

all: $(BIN)/testdiccionario $(BIN)/testletras $(BIN)/cantidad_letras dependencias

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxyfile
	
# ************ Compilación de módulos ************

dependencias:
$(OBJ)/letras.o : $(INC)/letras.h $(INC)/diccionario.h $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/letras.o $(SRC)/letras.cpp

$(OBJ)/diccionario.o: $(INC)/diccionario.h $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp

testdiccionario: 
$(BIN)/testdiccionario : $(OBJ)/testdiccionario.o 
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o

$(OBJ)/testdiccionario.o : $(INC)/diccionario.h $(SRC)/testdiccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp 

testletras: 
$(BIN)/testletras : $(OBJ)/testletras.o
	$(CXX) -o $(BIN)/testletras $(OBJ)/testletras.o

$(OBJ)/testletras.o : $(INC)/letras.h $(SRC)/testletras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/testletras.o $(SRC)/testletras.cpp 

cantidad_letras:
$(BIN)/cantidad_letras : $(OBJ)/cantidad_letras.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o

$(OBJ)/cantidad_letras.o : $(INC)/letras.h $(SRC)/cantidad_letras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp 


# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f -r $(BIN)/* doc/html/* doc/latex/*
	
