#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcion: Registra el contenido del archivo "Entrada.in"
//Entrada: Distribuvion de colonias (char**)
void leerArchivo(char ** distribucionDeColonia){

	FILE * archivo;
	archivo = fopen("Entrada.in", "r");
	if(archivo == NULL){
		printf("Archivo no encontrado");
	}
	else{
		fscanf(archivo, "%s", *distribucionDeColonia);
	}
}

void escribirArchivo(char ** distribucionDeColonia){
	FILE * archivo;
	archivo = fopen("Salida.out","a");
	fprintf(archivo, "%s" ,*distribucionDeColonia);
	fprintf(archivo, "%s" ,  "\n");
	fclose(archivo);
}

//Funcion: Cuenta la cantidad de cada colonia en la distribucion
//Entrada: Distribución de colonias (char**), cantidades de las colonias 1, 2 y 3 (int *)
void contarColoniasDeCadaTipo(char ** distribucionDeColonia, int * cantidadColonia1, int * cantidadColonia2, int * cantidadColonia3){
	*cantidadColonia1 = 0;
	*cantidadColonia2 = 0;
	*cantidadColonia3 = 0;
	int indice = 0;
	while((*distribucionDeColonia)[indice] != '\0'){
		if((*distribucionDeColonia)[indice] == '1'){
			*cantidadColonia1 = *cantidadColonia1 + 1;
		}
		if((*distribucionDeColonia)[indice] == '2'){
			*cantidadColonia2 = *cantidadColonia2 + 1;
		}
		if((*distribucionDeColonia)[indice] == '3'){
			*cantidadColonia3 = *cantidadColonia3 + 1;
		}
		indice = indice + 1;
	}
}

//Funcion: Verifica si se llego a la solucion final
//Entrada: Cantidades de las colonias 1, 2 y 3 (int *)
//Salida: 1 o 0, donde 1 representa que se llego a la solucion final y 0 que no (int)
int verificarSiEsSolucionFinal(int *cantidadColonia1, int * cantidadColonia2, int * cantidadColonia3){
	if(*cantidadColonia1 == 0 && *cantidadColonia2 == 0){
		return 1;
	}
	else if(*cantidadColonia1 == 0 && *cantidadColonia3 == 0){
		return 1;
	}
	else if(*cantidadColonia2 == 0 && *cantidadColonia3 == 0){
		return 1;
	}
	return 0;
}

//Funcion: Indentifica cuales son las colonias mas numerosas
//Entrada: Cantidades de las colonias 1, 2 y 3 (int *), Colonia mas numerosa, segunda mas numerosa y menos numerosa (int *) 
void identificarColoniasMasNumerosas(int * cantidadColonia1, int * cantidadColonia2, int * cantidadColonia3, int * primeraColoniaMasNuemerosa, int * segundaColoniaMasNumerosa, int * coloniaMenosNumerosa){
	if(*cantidadColonia1 >= *cantidadColonia2 && *cantidadColonia1 >= *cantidadColonia3){
		*primeraColoniaMasNuemerosa = 1;
		if(*cantidadColonia2 >= *cantidadColonia3){
			*segundaColoniaMasNumerosa = 2;
			*coloniaMenosNumerosa = 3;
		}
		else{
			*segundaColoniaMasNumerosa = 3;
			*coloniaMenosNumerosa = 2;
		}
	}
	else if(*cantidadColonia2 >= *cantidadColonia3){
		*primeraColoniaMasNuemerosa = 2;
		if(*cantidadColonia1 >= *cantidadColonia3){
			*segundaColoniaMasNumerosa = 1;
			*coloniaMenosNumerosa = 3;
		}
		else{
			*segundaColoniaMasNumerosa = 3;
			*coloniaMenosNumerosa = 1;
		}
	}
	else{
		*primeraColoniaMasNuemerosa = 3;
		if(*cantidadColonia1 >= *cantidadColonia2){
			*segundaColoniaMasNumerosa = 1;
			*coloniaMenosNumerosa = 2;
		}
		else{
			*segundaColoniaMasNumerosa = 2;
			*coloniaMenosNumerosa = 1;
		}
	}
}

//Funcion: Verifica que sea posible unir las dos colonias mas numerosas
//Entrada: Distribucion de colonias (char**), colonia mas numerosa (int*), sgunda colonia mas numerosa (int *)
//Salida: 1 o 0, donde 1 significa que es posible y 0 que no (int)
int verificarUnionDeLasColoniasNumerosas(char ** distribucionDeColonia, int * primeraColoniaMasNuemerosa, int * segundaColoniaMasNumerosa){
	char primeraColoniaMasNuemerosaChar = *primeraColoniaMasNuemerosa + '0';
	char segundaColoniaMasNumerosaChar = *segundaColoniaMasNumerosa + '0';
	int indice = 0;
	while((*distribucionDeColonia)[indice + 1] != '\0'){
		if(((*distribucionDeColonia)[indice] == primeraColoniaMasNuemerosaChar && (*distribucionDeColonia)[indice + 1] == segundaColoniaMasNumerosaChar) || ((*distribucionDeColonia)[indice] == segundaColoniaMasNumerosaChar && (*distribucionDeColonia)[indice + 1] == primeraColoniaMasNuemerosaChar)){
			return 1;
		}
		indice = indice + 1;
	}
	return 0;
}

//Funcion: Une dos colonias
//Entrada: Distribucion de las colonias (char**), primera colonia que se quiere unir (int *), segunda colonia que se quiere unir (int *) 
void unirColonias(char ** distribucionDeColonia, int * colonia1, int * colonia2, int * coloniaSobrante){
	int seRealizoUnion = 0;
	char colonia1Char = *colonia1 + '0';
	char colonia2Char = *colonia2 + '0';
	char coloniaSobranteChar = *coloniaSobrante + '0';
	int indice = 0;
	while((*distribucionDeColonia)[indice + 1] != '\0' && seRealizoUnion == 0){
		if(((*distribucionDeColonia)[indice] == colonia1Char && (*distribucionDeColonia)[indice + 1] == colonia2Char) || ((*distribucionDeColonia)[indice] == colonia2Char && (*distribucionDeColonia)[indice + 1] == colonia1Char)){
			seRealizoUnion = 1;
			(*distribucionDeColonia)[indice] = coloniaSobranteChar;
			indice = indice + 1;
			while((*distribucionDeColonia)[indice + 1] != '\0'){
				(*distribucionDeColonia)[indice] = (*distribucionDeColonia)[indice + 1];
				indice = indice + 1;
			}
			(*distribucionDeColonia)[indice] = '\0';
		}
		indice = indice + 1;
	}
}
//Funcion: Parte recursiva de la funcion principal.
//Entrada: Distribucion de la colonia (char**), canitidad de colonia 1 (int*), canitidad de colonia 2 (int*), canitidad de colonia 3 (int*), colonia mas numerosa (int*), segunda colonia mas numerosa (int*), colonia menos numerosa (int*)
void algoritmoUnionRecursivo(char ** distribucionDeColonia, int * cantidadColonia1, int * cantidadColonia2, int * cantidadColonia3, int * primeraColoniaMasNuemerosa, int * segundaColoniaMasNumerosa, int * coloniaMenosNumerosa){
	escribirArchivo(distribucionDeColonia);
	contarColoniasDeCadaTipo(distribucionDeColonia, cantidadColonia1, cantidadColonia2, cantidadColonia3);
	if(verificarSiEsSolucionFinal(cantidadColonia1, cantidadColonia2, cantidadColonia3) == 0){
		identificarColoniasMasNumerosas(cantidadColonia1, cantidadColonia2, cantidadColonia3, primeraColoniaMasNuemerosa, segundaColoniaMasNumerosa, coloniaMenosNumerosa);
		if(verificarUnionDeLasColoniasNumerosas(distribucionDeColonia, primeraColoniaMasNuemerosa, segundaColoniaMasNumerosa) == 1){
			unirColonias(distribucionDeColonia, primeraColoniaMasNuemerosa, segundaColoniaMasNumerosa, coloniaMenosNumerosa);
		}
		else{
			unirColonias(distribucionDeColonia, primeraColoniaMasNuemerosa, coloniaMenosNumerosa, segundaColoniaMasNumerosa);
		}
		algoritmoUnionRecursivo(distribucionDeColonia, cantidadColonia1, cantidadColonia2, cantidadColonia3, primeraColoniaMasNuemerosa, segundaColoniaMasNumerosa, coloniaMenosNumerosa);
	}
}


//Funcion: Cuenta la cantidad de caracteres en una cadena de caracteres
//Entrada: Puntero a cadena de caracteres (char**)
//Salida: Entero que representa la cantidad de colonias (int)
int cantidadDeColonias(){
	char aux;
	int respuesta;
	FILE * archivo;
	archivo = fopen("Entrada.in","r");
	while(!feof(archivo)){
		aux = fgetc(archivo);
		respuesta = respuesta + 1;
	}
	fclose(archivo);
	return respuesta;
}

//Funcion: Funcion principal. Encuentra la formacion de colonias con mayor probabilidad de supervivencia posible usando el metodo goloso
void algoritmoUnion(){
	int cantidadDeColoniasInicial = cantidadDeColonias();
	int * cantidadColonia1 = NULL;
	cantidadColonia1 = (int*)malloc(sizeof(int));
	int * cantidadColonia2 = NULL;
	cantidadColonia2 = (int*)malloc(sizeof(int));
	int * cantidadColonia3 = NULL;
	cantidadColonia3 = (int*)malloc(sizeof(int));
	int * primeraColoniaMasNuemerosa = NULL;
	primeraColoniaMasNuemerosa = (int*)malloc(sizeof(int));
	int * segundaColoniaMasNumerosa = NULL;
	segundaColoniaMasNumerosa = (int*)malloc(sizeof(int));
	int * coloniaMenosNumerosa = NULL;
	coloniaMenosNumerosa = (int*)malloc(sizeof(int));
	char ** distribucionDeColonia = NULL;
	distribucionDeColonia = (char**)malloc(sizeof(char*));
	*distribucionDeColonia = (char*)malloc(sizeof(char)*cantidadDeColoniasInicial);
	leerArchivo(distribucionDeColonia);
	FILE * archivo;
	archivo = fopen("Salida.out","w");
	fclose(archivo);
	algoritmoUnionRecursivo(distribucionDeColonia, cantidadColonia1, cantidadColonia2, cantidadColonia3, primeraColoniaMasNuemerosa, segundaColoniaMasNumerosa, coloniaMenosNumerosa);
}

int main(){
	algoritmoUnion();
	return 0;
}