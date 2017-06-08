/*
 * Este programa muestra el comportamiento de las listas enlazadas
 * */
 
 #include <stdlib.h>
 #include <stdio.h>
 
 typedef struct cancion {
	struct cancion* anterior;		//Estos punteros me ayudaran a determinar el orden de las canciones
	struct cancion* siguiente;
	char* nombre;
	char* artista;
 } cancion;
 
 cancion* primera = NULL;
 cancion* actual = NULL;
 cancion* ultima = NULL;
 
 void agregar(cancion* _cancion){
	_cancion -> anterior = NULL;
	_cancion -> siguiente = NULL;
	if (primera == NULL){
		primera = _cancion;
		ultima = _cancion;
	}else{
		_cancion -> anterior = ultima;
		ultima -> siguiente = _cancion;
		ultima = _cancion;
		
	}
	
 }
 
 
cancion* extraerDesc(){
	if (ultima == NULL){
		return NULL;
	}
	
	cancion* cancion_retorno = ultima;
	ultima = cancion_retorno -> anterior;
	return cancion_retorno;
	
}

cancion* extraerAsc(){
	if(primera == NULL){
		return NULL;
	}
	
	cancion* cancion_retorno = primera;
	primera = cancion_retorno -> siguiente;
	return cancion_retorno;
}
 
 int main(){
	
	 //Forma estatica
	cancion* uno = malloc(sizeof(cancion));
	uno->nombre="Breathe";
	uno->artista="Pink Floyd";
	
	cancion* dos = malloc(sizeof(cancion));
	dos->nombre="Drifters";
	dos->artista="Iron Maiden";
	
	cancion* tres = malloc(sizeof(cancion));
	tres->nombre="Megalomania";
	tres->artista="Black Sabbath";
	
	cancion* cuatro = malloc(sizeof(cancion));
	cuatro->nombre="They Live";
	cuatro->artista="Dystopia";
	
	agregar(uno);
	agregar(dos);
	agregar(tres);
	agregar(cuatro);
	
	printf("Vamos a mostrar en forma FIFO\n");
	
	cancion* i = extraerAsc();
	
	while(i != NULL){
		printf("%s, de %s\n", i->nombre, i->artista);
		i = extraerAsc();
		
	}
	
	printf("Vamos a mostrar en forma LIFO\n");
	
	cancion* j = extraerDesc();
	
	while(j != NULL){
		printf("%s, de %s\n", j->nombre, j->artista);
		j = extraerDesc();
		
	}
	
	
	return 0;
 }