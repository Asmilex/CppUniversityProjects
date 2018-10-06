
void aniadir(char * & array, int & util, char caracter){
    redimensionar(array, util, 1);
    array[util-1] = caracter;
}
