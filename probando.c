#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

char * contenidoIdPalabraIndiceInvertido(palabraIndiceInvertido * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> id;
}

int contenidoFrecuenciaPalabraIndiceInvertido(palabraIndiceInvertido * nodo){
	if(!nodo){
		return -1;
	}
	return nodo -> frecuencia;
}

palabraIndiceInvertido * siguientePalabraIndiceInvertido(palabraIndiceInvertido * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> siguiente;
}

palabraIndiceInvertido * crearPalabraIndiceInvertido(char * nuevoId, int nuevaFrecuencia, palabraIndiceInvertido * nuevaPalabraIndiceInvertido){
	palabraIndiceInvertido * nuevo = NULL;
	nuevo =(palabraIndiceInvertido *)malloc(sizeof(palabraIndiceInvertido));

	nuevo -> id = (char *)malloc(sizeof(char)*10);
	nuevo -> siguiente = (palabraIndiceInvertido *)malloc(sizeof(palabraIndiceInvertido));

	nuevo -> id = nuevoId;
	nuevo -> frecuencia = nuevaFrecuencia;
	nuevo -> siguiente = nuevaPalabraIndiceInvertido;

	return nuevo;
}

palabraIndiceInvertido * anularPalabraIndiceInvertido(palabraIndiceInvertido * raiz){
	if(raiz == NULL){
		return raiz;
	} 
	raiz -> siguiente = anularPalabraIndiceInvertido(siguientePalabraIndiceInvertido(raiz));
	free(contenidoIdPalabraIndiceInvertido(raiz));
	raiz -> id = NULL;
	free(raiz);
	raiz = NULL;
	return raiz;
}

palabraIndiceInvertido * insertarPalabraIndiceInvertido(palabraIndiceInvertido * cabecera, char * nuevoId, int nuevoFrecuencia){
	palabraIndiceInvertido * nuevo = crearPalabraIndiceInvertido(nuevoId, nuevoFrecuencia, NULL);

	if(cabecera == NULL){
		return nuevo;
	}

	palabraIndiceInvertido * indice = cabecera;
	while(indice -> siguiente != NULL){
		indice = indice -> siguiente;
	}
	indice -> siguiente = nuevo;
	indice -> siguiente -> siguiente = NULL;
	return cabecera;
}

int buscarPalabraIndiceInvertido(palabraIndiceInvertido * cabecera, char * idBusqueda){
	palabraIndiceInvertido * indice = cabecera;
	int recorrido = 0;
	while(indice != NULL){
		if(indice -> id == idBusqueda){
			return recorrido;
		}
		recorrido = recorrido + 1;
		indice = indice -> siguiente;
	}
	return -1;
}

palabraIndiceInvertido * obtenerPalabraIndiceInvertido(palabraIndiceInvertido * p, int posicion){
	palabraIndiceInvertido * indice = p;
	int recorrido = 0;
	while(recorrido < posicion){
		indice = indice -> siguiente;
		recorrido = recorrido + 1;
	}
	return indice;
}

palabraIndiceInvertido * contenidoPalabraIndiceInvertidoIndex(Index * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> palabraIndice;
}

//Funcion: Retorna la palabra
//Entrada: Puntero a cualquier nodo del arbol indice invertido
//Salida: puntero a char que contiene la palabra
char * contenidoPalabraIndex(Index * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> palabra;
}

//Funcion: Retorna el hijo izquierdo de un nodo de un arbol
//Entrada: Puntero a cualquier nodo del arbol indice invertido
//Salida: Puntero a arbol que es el hijo izqueirdo de un nodo cualquiera
Index * hijoIzquierdoIndex(Index * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> hijoIzquierdoIndex;
}

//Funcion: Retorna el hijo derecho de un nodo de un arbol
//Entrada: Puntero a cualquier nodo del arbol indice invertido
//Salida: Puntero a arbol que es el derecho izqueirdo de un nodo cualquiera
Index * hijoDerechoIndex(Index * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> hijoDerechoIndex;
}

//Funcion: Crea un nuevo nodo para el arbol
//Entrada: Puntero a char que contiene a la palabra, puntero al nodo cabecera de la lista enlazada de la palabra, puntero al arbol hijo derecho y puntero al arbol hijo izqueirdo
//Salida: Puntero a arbol
Index * crearIndex(char * nuevaPalabra, palabraIndiceInvertido * nuevaPalabraIndiceInvertido,  Index * nuevoHijoDerecho, Index * nuevoHijoIzquierdo){
	Index * nuevoIndex = NULL;
	nuevoIndex = (Index *)malloc(sizeof(Index));
	nuevoIndex -> palabra = (char *)malloc(sizeof(char) * 50);
	nuevoIndex -> palabraIndice = (palabraIndiceInvertido *)malloc(sizeof(palabraIndiceInvertido));
	nuevoIndex -> hijoIzquierdoIndex = (Index *)malloc(sizeof(Index));
	nuevoIndex -> hijoDerechoIndex = (Index *)malloc(sizeof(Index));

	nuevoIndex -> palabra = nuevaPalabra;
	nuevoIndex -> palabraIndice = nuevaPalabraIndiceInvertido;
	nuevoIndex -> hijoIzquierdoIndex = nuevoHijoIzquierdo;
	nuevoIndex -> hijoDerechoIndex = nuevoHijoDerecho;
	
	return nuevoIndex;
}

//Funcion: Elimina y libera memoria a un arbol
//Entrada: Puntero a arbol que es la raiz del ABO
//Salida: NULL
Index * anularIndex(Index * raiz){
	if(raiz == NULL){
		return raiz;
	}
	raiz -> hijoIzquierdoIndex = anularIndex(hijoIzquierdoIndex(raiz));
	raiz -> hijoDerechoIndex = anularIndex(hijoDerechoIndex(raiz));
	free(raiz -> palabra);
	raiz -> palabra = NULL;
	free(raiz);
	raiz = NULL;
	return raiz;
}

//Funcion: Busca una palabra en el indice invertido
//Entrada: Puntero a arbol que es la raiz del ABO, puntero a char que es la palabra por buscar
//Salida: Puntero a arbol que contiene la palabra buscaada o NULL si no lo encuentra
Index * buscarIndex(Index * raiz, char* palabra){
	Index* indice = raiz;

	while(indice != NULL){
		char* palabraActual = contenidoPalabraIndex(indice);
		if(strcmp(palabra, palabraActual) == 0){
			return indice;
		}
		if(strcmp(palabra, palabraActual) < 0){
			indice = hijoIzquierdoIndex(indice);
		}
		else{
			indice = hijoDerechoIndex(indice);
		}
	}
	return NULL;
}



//Funcion:
//Entrada:
//Salida:
Index * insertarIndex(Index* raiz, char* palabra, palabraIndiceInvertido * palabraIndice){
	Index * nodo = crearIndex(palabra, palabraIndice, NULL, NULL);
	if(raiz == NULL){
		return nodo;
	}

	if(hijoIzquierdoIndex(raiz) == NULL && strcmp(palabra, contenidoPalabraIndex(raiz)) < 0){
		raiz -> hijoIzquierdoIndex = nodo;
		return raiz;
	}

	if(hijoDerechoIndex(raiz) == NULL && strcmp(palabra, contenidoPalabraIndex(raiz)) > 0){
		raiz -> hijoDerechoIndex = nodo;
		return raiz;
	}

	if(strcmp(palabra, contenidoPalabraIndex(raiz)) < 0){
		raiz -> hijoIzquierdoIndex = insertarIndex(hijoIzquierdoIndex(raiz), palabra, palabraIndice);
		return raiz;
	}

	if(strcmp(palabra, contenidoPalabraIndex(raiz)) > 0){
		raiz -> hijoDerechoIndex = insertarIndex(hijoDerechoIndex(raiz), palabra, palabraIndice);
		return raiz;
	}
	return raiz;
}

char * contenidoPalabraStopWords(StopWords * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> palabra;
}


//Funcion: Retorna el hijo izquierdo de un nodo de un arbol
//Entrada: Puntero a cualquier nodo del arbol indice invertido
//Salida: Puntero a arbol que es el hijo izqueirdo de un nodo cualquiera
StopWords * hijoIzquierdoStopWords(StopWords * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> hijoIzquierdoStopWords;
}

//Funcion: Retorna el hijo derecho de un nodo de un arbol
//Entrada: Puntero a cualquier nodo del arbol indice invertido
//Salida: Puntero a arbol que es el derecho izqueirdo de un nodo cualquiera
StopWords * hijoDerechoStopWords(StopWords * nodo){
	if(!nodo){
		return NULL;
	}
	return nodo -> hijoDerechoStopWords;
}

//Funcion: Crea un nuevo nodo para el arbol
//Entrada: Puntero a char que contiene a la palabra, puntero al nodo cabecera de la lista enlazada de la palabra, puntero al arbol hijo derecho y puntero al arbol hijo izqueirdo
//Salida: Puntero a arbol
StopWords * crearStopWords(char * nuevaPalabra, StopWords * nuevoHijoDerecho, StopWords * nuevoHijoIzquierdo){
	StopWords * nuevoArbol = NULL;
	nuevoArbol = (StopWords *)malloc(sizeof(StopWords));
	nuevoArbol -> palabra = (char *)malloc(sizeof(char) * 50);
	nuevoArbol -> hijoIzquierdoStopWords = (StopWords *)malloc(sizeof(StopWords));
	nuevoArbol -> hijoDerechoStopWords = (StopWords *)malloc(sizeof(StopWords));

	nuevoArbol -> palabra = nuevaPalabra;
	nuevoArbol -> hijoIzquierdoStopWords = nuevoHijoIzquierdo;
	nuevoArbol -> hijoDerechoStopWords = nuevoHijoDerecho;
	
	return nuevoArbol;
}

//Funcion: Elimina y libera memoria a un arbol
//Entrada: Puntero a arbol que es la raiz del ABO
//Salida: NULL
StopWords * anularArbolStopWords(StopWords * raiz){
	if(raiz == NULL){
		return raiz;
	}
	raiz -> hijoIzquierdoStopWords = anularArbolStopWords(hijoIzquierdoStopWords(raiz));
	raiz -> hijoDerechoStopWords = anularArbolStopWords(hijoDerechoStopWords(raiz));
	free(raiz -> palabra);
	raiz -> palabra = NULL;
	free(raiz);
	raiz = NULL;
	return raiz;
}

//Funcion: Busca una palabra en el indice invertido
//Entrada: Puntero a arbol que es la raiz del ABO, puntero a char que es la palabra por buscar
//Salida: Puntero a arbol que contiene la palabra buscaada o NULL si no lo encuentra
StopWords * buscarArbolStopWords(StopWords * raiz, char* palabra){
	StopWords* indice = raiz;

	while(indice != NULL){
		char* palabraActual = contenidoPalabraStopWords(indice);
		if(strcmp(palabra, palabraActual) == 0){
			return indice;
		}
		if(strcmp(palabra, palabraActual) < 0){
			indice = hijoIzquierdoStopWords(indice);
		}
		else{
			indice = hijoDerechoStopWords(indice);
		}
	}
	return NULL;
}

//Funcion:
//Entrada:
//Salida:
StopWords * insertarArbolStopWords(StopWords* raiz, char* palabra){
	StopWords * nodo = crearStopWords(palabra, NULL, NULL);
	if(raiz == NULL){
		return nodo;
	}

	if(hijoIzquierdoStopWords(raiz) == NULL && strcmp(palabra, contenidoPalabraStopWords(raiz)) < 0){
		raiz -> hijoIzquierdoStopWords = nodo;
		return raiz;
	}

	if(hijoDerechoStopWords(raiz) == NULL && strcmp(palabra, contenidoPalabraStopWords(raiz)) > 0){
		raiz -> hijoDerechoStopWords = nodo;
		return raiz;
	}

	if(strcmp(palabra, contenidoPalabraStopWords(raiz)) < 0){
		raiz -> hijoIzquierdoStopWords = insertarArbolStopWords(hijoIzquierdoStopWords(raiz), palabra);
		return raiz;
	}

	if(strcmp(palabra, contenidoPalabraStopWords(raiz)) > 0){
		raiz -> hijoDerechoStopWords = insertarArbolStopWords(hijoDerechoStopWords(raiz), palabra);
		return raiz;
	}
	return raiz;
}

StopWords * loadStopWords(char * pathStopWordsFile, code *statusCode){
	char * aux = NULL;
	StopWords * arbolStopWords = NULL;
	FILE *archivo;
	archivo = fopen(pathStopWordsFile, "r");
	if(archivo == NULL){
		*statusCode = ERR_FILE_NOT_FOUND;
		printf("Archivo no encontrado");
		return NULL;
	}

	else{
		while(!feof(archivo)){
			aux = (char *)malloc(sizeof(char) * 50);
			fscanf(archivo, "%s", aux);
			arbolStopWords = insertarArbolStopWords(arbolStopWords,aux);
		}
	}
	fclose(archivo);
	return arbolStopWords;
}

void inorden(Index * T, FILE * nuevoArchivo){
	if(T != NULL){
		inorden(hijoIzquierdoIndex(T), nuevoArchivo);
		char * palabra = contenidoPalabraIndex(T);
		palabraIndiceInvertido * lista = contenidoPalabraIndiceInvertidoIndex(T);
		fprintf(nuevoArchivo,"%s ->	", palabra );
		palabraIndiceInvertido * listaAux = lista;
		while(siguientePalabraIndiceInvertido(listaAux) != NULL){
			char * idDocumento = contenidoIdPalabraIndiceInvertido(listaAux);
			int frecuenciaDocumento = contenidoFrecuenciaPalabraIndiceInvertido(listaAux);
			fprintf(nuevoArchivo, "%s %d , ", idDocumento, frecuenciaDocumento);
			listaAux = siguientePalabraIndiceInvertido(listaAux);
		}
		char * idDocumento = contenidoIdPalabraIndiceInvertido(listaAux);
		int frecuenciaDocumento = contenidoFrecuenciaPalabraIndiceInvertido(listaAux);
		fprintf(nuevoArchivo,"%s %d *", idDocumento, frecuenciaDocumento);
		fprintf(nuevoArchivo,"\n");
		inorden(hijoDerechoIndex(T), nuevoArchivo);
	}
}

Index * createIndex(char * pathDocumentsFile, StopWords * sw, code *statusCode){
	Index * indiceInvertido = NULL;
	char * aux = NULL;
	char * aux2 = NULL;
	char * idLectura = NULL;
	FILE *archivo;
	archivo = fopen(pathDocumentsFile, "r");
	if(archivo == NULL){
		*statusCode = ERR_FILE_NOT_FOUND;
		printf("Archivo no encontrado");
		return NULL;
	}
	else{
		aux = (char *)malloc(sizeof(char) * 50);
		aux2 = (char *)malloc(sizeof(char) * 50);
		fscanf(archivo, "%s", aux2);
		while(feof(archivo) == 0){
			idLectura = (char *)malloc(sizeof(char)*5);
			fscanf(archivo, "%s", idLectura);
			fscanf(archivo, "%s", aux2);
			while(strcmp(aux, ".A") != 0){
				aux = (char *)malloc(sizeof(char) * 50);
				fscanf(archivo, "%s", aux);
				Index * indexAux = buscarIndex(indiceInvertido, aux);
				if(buscarArbolStopWords(sw, aux) == NULL && strcmp(aux, ".A") != 0){
					if(indexAux == NULL){
						palabraIndiceInvertido * palabraNueva = NULL;
						palabraNueva = insertarPalabraIndiceInvertido(palabraNueva, idLectura, 1);
						indiceInvertido = insertarIndex(indiceInvertido, aux, palabraNueva );
					}
					else if(buscarPalabraIndiceInvertido(contenidoPalabraIndiceInvertidoIndex(indexAux) , idLectura) == -1){
						palabraIndiceInvertido * palabraAux = contenidoPalabraIndiceInvertidoIndex(indexAux);
						palabraAux = insertarPalabraIndiceInvertido(palabraAux, idLectura, 1);
					}
					else{
						palabraIndiceInvertido * palabraAux = contenidoPalabraIndiceInvertidoIndex(indexAux);
						int posicion = buscarPalabraIndiceInvertido(contenidoPalabraIndiceInvertidoIndex(indexAux) , idLectura);
						palabraIndiceInvertido * documentoEnPalabra = obtenerPalabraIndiceInvertido(palabraAux, posicion);
						documentoEnPalabra -> frecuencia = documentoEnPalabra -> frecuencia + 1;
					}
				}
			}
			while(strcmp(aux, ".B") != 0){
				aux = (char *)malloc(sizeof(char) * 50);
				fscanf(archivo, "%s", aux);
				Index * indexAux = buscarIndex(indiceInvertido, aux);
				if(buscarArbolStopWords(sw, aux) == NULL && strcmp(aux, ".B") != 0){
					if(indexAux == NULL){
						palabraIndiceInvertido * palabraNueva = NULL;
						palabraNueva = insertarPalabraIndiceInvertido(palabraNueva, idLectura, 1);
						indiceInvertido = insertarIndex(indiceInvertido, aux, palabraNueva );
					}
					else if(buscarPalabraIndiceInvertido(contenidoPalabraIndiceInvertidoIndex(indexAux) , idLectura) == -1){
						palabraIndiceInvertido * palabraAux = contenidoPalabraIndiceInvertidoIndex(indexAux);
						palabraAux = insertarPalabraIndiceInvertido(palabraAux, idLectura, 1);
					}
					else{
						palabraIndiceInvertido * palabraAux = contenidoPalabraIndiceInvertidoIndex(indexAux);
						int posicion = buscarPalabraIndiceInvertido(contenidoPalabraIndiceInvertidoIndex(indexAux) , idLectura);
						palabraIndiceInvertido * documentoEnPalabra = obtenerPalabraIndiceInvertido(palabraAux, posicion);
						documentoEnPalabra -> frecuencia = documentoEnPalabra -> frecuencia + 1;
					}
				}
			}
			while(strcmp(aux, ".W") != 0){
				aux = (char *)malloc(sizeof(char) * 50);
				fscanf(archivo, "%s", aux);
				Index * indexAux = buscarIndex(indiceInvertido, aux);
				if(buscarArbolStopWords(sw, aux) == NULL && strcmp(aux, ".W") != 0){
					if(indexAux == NULL){
						palabraIndiceInvertido * palabraNueva = NULL;
						palabraNueva = insertarPalabraIndiceInvertido(palabraNueva, idLectura, 1);
						indiceInvertido = insertarIndex(indiceInvertido, aux, palabraNueva );
					}
					else if(buscarPalabraIndiceInvertido(contenidoPalabraIndiceInvertidoIndex(indexAux) , idLectura) == -1){
						palabraIndiceInvertido * palabraAux = contenidoPalabraIndiceInvertidoIndex(indexAux);
						palabraAux = insertarPalabraIndiceInvertido(palabraAux, idLectura, 1);
					}
					else{
						palabraIndiceInvertido * palabraAux = contenidoPalabraIndiceInvertidoIndex(indexAux);
						int posicion = buscarPalabraIndiceInvertido(contenidoPalabraIndiceInvertidoIndex(indexAux) , idLectura);
						palabraIndiceInvertido * documentoEnPalabra = obtenerPalabraIndiceInvertido(palabraAux, posicion);
						documentoEnPalabra -> frecuencia = documentoEnPalabra -> frecuencia + 1;
					}
				}
			}
			while(strcmp(aux, ".I") != 0 && feof(archivo) == 0){
				aux = (char *)malloc(sizeof(char) * 50);
				fscanf(archivo, "%s", aux);
				Index * indexAux = buscarIndex(indiceInvertido, aux);
				if(buscarArbolStopWords(sw, aux) == NULL && strcmp(aux, ".I") != 0){
					if(indexAux == NULL){
						palabraIndiceInvertido * palabraNueva = NULL;
						palabraNueva = insertarPalabraIndiceInvertido(palabraNueva, idLectura, 1);
						indiceInvertido = insertarIndex(indiceInvertido, aux, palabraNueva );
					}
					else if(buscarPalabraIndiceInvertido(contenidoPalabraIndiceInvertidoIndex(indexAux) , idLectura) == -1){
						palabraIndiceInvertido * palabraAux = contenidoPalabraIndiceInvertidoIndex(indexAux);
						palabraAux = insertarPalabraIndiceInvertido(palabraAux, idLectura, 1);
					}
					else{
						palabraIndiceInvertido * palabraAux = contenidoPalabraIndiceInvertidoIndex(indexAux);
						int posicion = buscarPalabraIndiceInvertido(contenidoPalabraIndiceInvertidoIndex(indexAux) , idLectura);
						palabraIndiceInvertido * documentoEnPalabra = obtenerPalabraIndiceInvertido(palabraAux, posicion);
						documentoEnPalabra -> frecuencia = documentoEnPalabra -> frecuencia + 1;
					}
				}
			}
		}
	}
	free(aux2);
	aux2 = NULL;
	free(aux);
	aux = NULL;
	*statusCode = OK;
	fclose(archivo);
	return indiceInvertido;
}

void saveIndex(Index * indice, char * id, int cantidadDocumentos, code *statusCode){
	if(indice != NULL){
		char nombreArchivo[50] = "indiceId";
		strcat(nombreArchivo, id);
		strcat(nombreArchivo, ".indice");
		FILE* nuevoArchivo = fopen(nombreArchivo, "w");
		if(nuevoArchivo == NULL){
			*statusCode = ERR_FILE_NOT_FOUND;
			printf("\nError al abrir el archivo.");
		}
		else{
			fprintf(nuevoArchivo, "%d\n", cantidadDocumentos);
			inorden(indice, nuevoArchivo);
		}
		fclose(nuevoArchivo);
		*statusCode = SAVE_INDEX;
	}
	else{
		*statusCode = NOT_SAVE_INDEX;
	}
}


Index* loadIndex(char * pathDocumentsFile,StopWords * sw, code *statusCode){
	Index * indiceInvertido = NULL;
	palabraIndiceInvertido * palabraNueva = NULL;
	char * palabra;
	char * idLectura;
	int * frecuencia;
	char * aux = NULL;

	FILE* archivo = NULL;
	archivo = fopen(pathDocumentsFile, "r");

	if(archivo == NULL){
		*statusCode = ERR_FILE_NOT_FOUND;
        printf("\nError al abrir el archivo.");
        return NULL;
    }
    else{
    	aux = (char *)malloc(sizeof(char) * 50);
    	fscanf(archivo, "%s", aux);
    	while(feof(archivo) == 0){
    		palabra = (char *)malloc(sizeof(char) * 50);
    		fscanf(archivo, "%s", palabra);
    		fscanf(archivo, "%s", aux);
    		while(strcmp(aux, "*") != 0){
    			frecuencia = (int *)malloc(sizeof(int));
    			idLectura = (char *)malloc(sizeof(char) * 50);
				fscanf(archivo, "%s", idLectura);
				fscanf(archivo, "%d", frecuencia);
				fscanf(archivo, "%s", aux);
				if(strcmp(aux, "*") != 0 && feof(archivo) == 0){
					palabraNueva = insertarPalabraIndiceInvertido(palabraNueva, idLectura, *frecuencia);
				}
    		}
    		if(feof(archivo) == 0){
    			indiceInvertido = insertarIndex(indiceInvertido, palabra, palabraNueva );
    		}
    	}
    }
    fclose(archivo);
    *statusCode = OK;
    free(aux);
    return indiceInvertido;
}


char * consulta(){
	char * palabra = NULL;
	char * consulta = NULL;
	palabra = (char *)malloc(sizeof(char) * 50);
	consulta = (char *)malloc(sizeof(char) * 50);
	int i = 1;
	printf("   Instrucciones: Para terminar el proceso de escritura escriba: ' .'\n    ");
	scanf("%s", consulta);
	if(strcmp(consulta, ".") != 0){
		consulta  = strcat(consulta, " ");
		while(strcmp(palabra, ".") != 0){
			scanf("%s", palabra);
			if(strcmp(palabra, ".") != 0){
				consulta = (char *)realloc(consulta, sizeof(char) * 50 * i);
				consulta = strcat(consulta, palabra);
				consulta  = strcat(consulta, " ");
				i = i + 1;
			}
		}
	}
	free(palabra);
	return consulta;
}

//Funcion: Funcion que busca el autor del documento dado su identificador
//Entrada: char * que contiene el identificador del documento por buscar y el nombre del archivo que contiene a los documentos
//Salida: char * que contiene al autor del texto
char * buscarAutorArchivo(char * pathDocumentsFile, char * idDocumento){
	char * autorTexto = NULL;
	char * aux = NULL;
	char * aux2 = NULL;
	int i = 1;
	FILE *archivo;
	archivo = fopen(pathDocumentsFile, "r");
	if(archivo == NULL){
		printf("Archivo no encontrado");
		return NULL;
	}
	else{
		aux = (char *)malloc(sizeof(char) * 50);
		aux2 = (char *)malloc(sizeof(char) * 50);
		autorTexto = (char *)malloc(sizeof(char) * 50);
		autorTexto = strcpy(autorTexto, "");
		while(feof(archivo) == 0 && strcmp(aux, ".I") != 0 || strcmp(aux2, idDocumento) != 0){
			aux = strcpy(aux, aux2);
			fscanf(archivo, "%s", aux2);
		}
		if((strcmp(aux, ".I") == 0 && strcmp(aux2, idDocumento) == 0)){
			fscanf(archivo, "%s", aux);
			while(strcmp(aux, ".A") != 0){
				fscanf(archivo, "%s", aux);
			}
			while(strcmp(aux, ".B")!= 0){
				fscanf(archivo, "%s", aux);
				if(strcmp(aux, ".B") != 0){
					autorTexto = (char *)realloc(autorTexto, sizeof(char) * 50 * i);
					autorTexto = strcat(autorTexto, aux);
					autorTexto = strcat(autorTexto, " ");
					i = i + 1;
				}
			}
		}
	}
	free(aux);
	aux = NULL;
	free(aux2);
	aux2 = NULL;
	return autorTexto;

}

//Funcion: Funcion que busca el nombre del documento dado su identificador
//Entrada: char * que contiene el identificador del documento por buscar y el nombre del archivo que contiene a los documentos
//Salida: char * que contiene el titulo del texto
char * buscarTituloArchivo(char * pathDocumentsFile, char * idDocumento){
	char * tituloTexto = NULL;
	char * aux = NULL;
	char * aux2 = NULL;
	int i = 1;
	FILE *archivo;
	archivo = fopen(pathDocumentsFile, "r");
	if(archivo == NULL){
		printf("Archivo no encontrado");
		return NULL;
	}
	else{
		aux = (char *)malloc(sizeof(char) * 50);
		aux2 = (char *)malloc(sizeof(char) * 50);
		tituloTexto = (char *)malloc(sizeof(char) * 50);
		tituloTexto = strcpy(tituloTexto, "");
		while(feof(archivo) == 0 && strcmp(aux, ".I") != 0 || strcmp(aux2, idDocumento) != 0){
			aux = strcpy(aux, aux2);
			fscanf(archivo, "%s", aux2);
		}
		if((strcmp(aux, ".I") == 0 && strcmp(aux2, idDocumento) == 0)){
			fscanf(archivo, "%s", aux);
			while(strcmp(aux, ".A") != 0){
				fscanf(archivo, "%s", aux);
				if(strcmp(aux, ".A") != 0){
					tituloTexto = (char *)realloc(tituloTexto, sizeof(char) * 50 * i);
					tituloTexto = strcat(tituloTexto, aux);
					tituloTexto = strcat(tituloTexto, " ");
					i = i + 1;
				}
			}
		}
	}
	free(aux);
	aux = NULL;
	free(aux2);
	aux2 = NULL;
	return tituloTexto;
}

 
Result crearResult(int nuevoIdDocumento){
	Result nuevo;
	nuevo.multiplicador = 0;
	nuevo.idDocumento = nuevoIdDocumento;
	nuevo.ranking = 0;
	return nuevo;
}

Ranking crearRanking(int cantidadDocumentos){
	Ranking nuevoRanking;
	nuevoRanking.infoDoc = NULL;
	nuevoRanking.infoDoc = (Result *)malloc(sizeof(Result) * cantidadDocumentos);
	int i;
	for(i=0;i<cantidadDocumentos;i++){
		nuevoRanking.infoDoc[i] = crearResult(i);
	}
	return nuevoRanking;
}


Ranking anularRanking(Ranking r){
	free(r.infoDoc);
	r.infoDoc = NULL;
	return r;
}

int cantidadDocumentos(char * pathStopWordsFile){
	char * aux = NULL;
	aux = (char *)malloc(sizeof(char) * 50);
	int numeroDocumentos = 0;

	FILE *archivo;
	archivo = fopen(pathStopWordsFile, "r");
	if(archivo == NULL){
		printf("Archivo no encontrado");
		return 0;
	}
	fscanf(archivo, "%s", aux);
	while(!feof(archivo)){
		fscanf(archivo, "%s", aux);
		while(strcmp(aux, ".I") != 0 && !feof(archivo)){
			fscanf(archivo, "%s", aux);
		}
		numeroDocumentos = numeroDocumentos + 1;
	}
	free(aux);
	return numeroDocumentos;
}

Ranking query(Index *i, StopWords *sw, char* text, char * pathDocumentsFile, code *statusCode){

	char* ptr;
	char s2[4] = " \n\t";
	int numeroDocumentos = cantidadDocumentos(pathDocumentsFile);
	Ranking rankingg = crearRanking(numeroDocumentos); //en este momento el id del documento coincide con la posicion del array
	int j;
	int id;
	int frecuencia;
	ptr = strtok( text, s2 ); //para separar la consulta por palabras
	Index * auxiliar;
	do{
		if(buscarArbolStopWords(sw, ptr) == NULL){ //No se consideran las palabras contenidas en el arbol StopWords
			auxiliar = buscarIndex(i,ptr); // auxiliar contiene el puntero a Index que contenga la plabra ptr (ptr es una palabra de la consulta)
			palabraIndiceInvertido * indice = contenidoPalabraIndiceInvertidoIndex(auxiliar); //indice contiene un duo id y frecuencia
			while(indice != NULL){ //Para recorrer toda la lista enlazada de duos id y frecuencia
				id = atoi(contenidoIdPalabraIndiceInvertido(indice)); //se recuerda que el id conincide con la posicion
				j = rankingg.infoDoc[id - 1].ranking; // j contiene un valor resultado (ranking)
				frecuencia = contenidoFrecuenciaPalabraIndiceInvertido(indice); //contiene la frecuencia en la que aparece la palabra en el documento
				rankingg.infoDoc[id - 1].ranking = rankingg.infoDoc[id - 1].ranking + frecuencia; // le sumo la frecuencia al valor del ranking 
				if(rankingg.infoDoc[id - 1].ranking - j != 0){
					rankingg.infoDoc[id - 1].multiplicador = rankingg.infoDoc[id - 1].multiplicador + 1; //cada vez que se encuentre una palabra de la consulta en un docuemento, se le suma 1 al multiplicador
				}

				indice = indice -> siguiente;
			}
		}
	}while( (ptr = strtok( NULL, s2 )) != NULL );

	for(j=0;j<numeroDocumentos;j++){
		rankingg.infoDoc[j].ranking = rankingg.infoDoc[j].ranking * rankingg.infoDoc[j].multiplicador;
	} // el valor ranking es multiplicado por el multiplicador
	int k;
	for(k = numeroDocumentos - 1; k>= 1; k--){ //ordenamiento por burbuja, el id ya no coincide con la posicion
		for(j = 0; j<k; j++){
			if(rankingg.infoDoc[j].ranking < rankingg.infoDoc[j + 1].ranking){
				if(k != j){
					Result aux;
					aux = rankingg.infoDoc[k];
					rankingg.infoDoc[k] = rankingg.infoDoc[j];
					rankingg.infoDoc[j] = aux;
				}
			}
		}
	}
	return rankingg;
}

void displayResults(Ranking r, int TopK, char * pathDocumentsFile, code *statusCode){
	int numeroDocumentos = cantidadDocumentos(pathDocumentsFile);
	int i;
	int idint;
	char idstr[30]; 
	if(numeroDocumentos >= TopK && TopK > 0){
		for(i=0; i<TopK;i++){
			idint = r.infoDoc[i].idDocumento + 1;
			sprintf(idstr, "%d", idint);
			printf("Identificador: %d\n", r.infoDoc[i].idDocumento + 1);
			printf("Titulo: %s\n", buscarTituloArchivo(pathDocumentsFile,idstr));
			printf("Autor: %s\n", buscarAutorArchivo(pathDocumentsFile,idstr));
			printf("Ranking: %d\n", r.infoDoc[i].ranking);
			printf("\n");
		}
	}
}

int cantidadDocumentosCargarArchivo(char * pathStopWordsFile){
	int * aux = NULL;
	aux = (int *)malloc(sizeof(int));
	int numeroDocumentos = 0;

	FILE *archivo;
	archivo = fopen(pathStopWordsFile, "r");
	if(archivo == NULL){
		printf("Archivo no encontrado");
		return 0;
	}
	fscanf(archivo, "%d", aux);
	numeroDocumentos = *aux;
	free(aux);
	aux = NULL;
	return numeroDocumentos;
}

void menu(){
	code cd;
	int entradaInt;
	int opcion;
	int TopK;
	int numeroDocumentos = -1;
	char * nombreStopWords;
	char * nombreIndex;
	char * consultaBusqueda;
	char * idIndexGuardar;
	char * nombreIndexCargado;
	char * pausa;
	StopWords * sw = NULL;
	Index * indexInvertido = NULL;
	Ranking rankingIndexInvertido;
	Ranking rankingindexCargado;
	Index * indexCargado = NULL;
	printf("\n\n\n---------- BUSCADOR INDICE INVERTIDO ---------");
    do
    {
    	printf( "\n\n   Introduzca opcion (1-6): ");
        printf( "\n   1. Cargar StopWords.");
        printf( "\n   2. Crear un nuevo indice invertido.");
        printf( "\n   3. Hacer una busqueda.");
        printf( "\n   4. Guardar indice invertido actual. ");
        printf( "\n   5. Cargar indice invertido. ");
        printf( "\n   6. Hacer una busqueda con el indice cargado. ");
        printf( "\n   7. Salir." );
        printf( "\n\n   Introduzca opcion (1-7): ");
        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: printf( "\n   Introduzca el nombre del archivo con los StopWords: \n\n\n");
            		if(sw != NULL){
            			anularArbolStopWords(sw);
            		}
                    nombreStopWords = consulta();
                    sw = loadStopWords(nombreStopWords, &cd);
                    if(cd == ERR_FILE_NOT_FOUND){
					printf("No se pudo abrir el archivo de la ruta especificada.\n");
					}
                    if(sw != NULL){
                    	printf("\n    Se ha creado la estructora StopWords con exito\n\n");
                    }
                    break;

            case 2: if(sw != NULL){
            			if(indexInvertido != NULL){
            				anularIndex(indexInvertido);
            			}
            			printf( "\n   Introduzca el nombre del archivo con los documentos: \n\n\n");
                    	nombreIndex = consulta();
                    	indexInvertido = createIndex(nombreIndex, sw, &cd);
                    	if(cd == ERR_FILE_NOT_FOUND){
						printf("No se pudo abrir el archivo de la ruta expecificada.\n");
						}	
                    	if(indexInvertido != NULL){
                    		numeroDocumentos = cantidadDocumentos(nombreIndex);
                    		printf("\n   Se ha creado la estructura Index con exito\n\n");
                    	}
                    	else{
                    		printf("No se ha podido crear la estrucctura Index\n");
                    	}
                    }
                    else{
                    	printf("\nPrimero debe cargar el archivo StopWords con la opcion 1\n");
                    }
                    break;

            case 3: if(indexInvertido!= NULL){
            			if(cd == OK){
            				printf( "\n   Haga una consulta: \n\n\n");
	            			consultaBusqueda = consulta();
            				rankingIndexInvertido = query(indexInvertido, sw, consultaBusqueda, nombreIndex, &cd);
            				if(cd == ERR_FILE_NOT_FOUND){
							printf("Error al abrir el archivo.\n");
							}
							else{
            				printf( "\n   Introduzca la cantidad de resultados de la busqueda: ");
            				scanf("%d", &TopK);
            				printf("\n\n   El resultado de la busqueda es: \n\n\n");
            				displayResults(rankingIndexInvertido, TopK, nombreIndex, &cd);
            				printf("   Para continuar ingrese ' .'\n");
            				scanf("%s", pausa);
            				anularRanking(rankingIndexInvertido);
            				}
                		}
                	}
                	else{
                		printf("\nPrimero debe cargar el archivo que contiene los docuementos para poder crear el indice con la opcion 2\n");
                	}
                	break;
            case 4: if(indexInvertido != NULL){
            			printf("   Introduzca el identificador que desea que tenga el archivo: \n\n\n");
            			idIndexGuardar = consulta();
            			idIndexGuardar[strlen(idIndexGuardar) - 1] = '\0';
            			saveIndex(indexInvertido, idIndexGuardar, numeroDocumentos, &cd);
            			printf("\n   Se ha guardado el indice invertido en el archivo indiceId%s.indice\n", idIndexGuardar);
            			if(cd == SAVE_INDEX){
						printf("Se ha guardado el indice\n");
						}
						else{
							printf("No se ha podido guardar el Indice.\n");
						}
            		}
            		else{
            			printf("No se ha cargado un indice para ser guardado, intente con la opcion 1\n");
            		}
            		break;

            case 5: if(sw != NULL){
            			printf("   Ingrese el nombre del archivo con extension .indice\n\n\n");
            			nombreIndexCargado = consulta();
                    	indexCargado = loadIndex(nombreIndexCargado, sw, &cd);
                    	numeroDocumentos = cantidadDocumentosCargarArchivo(nombreIndexCargado);
                    	if(cd == OK){
						printf("El indice ha sido cargado correctamente.\n");
						}
						else if(cd == ERR_FILE_NOT_FOUND){
						printf("No se ha podido guardar ningun indice.\n");
						}
						else{
							printf("La id ingresada no es valida.\n");
						}
                    }
                    else{
                    	printf("\nPrimero debe cargar el archivo StopWords con la opcion 1\n");
                    }
            		break;
            case 6: if(indexInvertido != NULL){
            			printf( "\n   Haga una consulta: \n\n\n");
	            		consultaBusqueda = consulta();
            			rankingindexCargado = query(indexInvertido, sw, consultaBusqueda, nombreIndex, &cd);
            			printf( "\n   Introduzca la cantidad de resultados de la busqueda: ");
            			scanf("%d", &TopK);
            			printf("\n\n   El resultado de la busqueda es: \n\n\n");
            			displayResults(rankingindexCargado, TopK, nombreIndex, &cd);
            			printf("   Para continuar ingrese ' .'\n");
            			scanf("%s", pausa);
            			anularRanking(rankingindexCargado);
                	}
                	else{
                		printf("\nPrimero debe cargar el archivo que contiene los docuementos para poder crear el indice con la opcion 2\n");
                	}
                	break;
            case 7: rankingIndexInvertido = anularRanking(rankingIndexInvertido);
            		rankingindexCargado = anularRanking(rankingindexCargado);
					sw = anularArbolStopWords(sw);
					free(nombreStopWords);
					free(nombreIndex);
					free(consultaBusqueda);
					free(idIndexGuardar);
					free(nombreIndexCargado);
					nombreStopWords = NULL;
					nombreIndex = NULL;
					consultaBusqueda = NULL;
					idIndexGuardar = NULL;
					nombreIndexCargado = NULL;
					indexInvertido = anularIndex(indexInvertido);
					indexCargado = anularIndex(indexCargado);
        }
    } while ( opcion == 6 || opcion == 5 || opcion == 4 || opcion == 3 || opcion == 2 || opcion == 1 );
}


int main(){
	menu();
	return 0;
}