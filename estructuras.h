#ifndef _ESTRUCTURAS_H_
#define _ESTRUCTURAS_H_


typedef struct Result{
	int idDocumento;
	int multiplicador;
	int ranking;
}Result;

typedef struct Ranking{
	Result * infoDoc;
}Ranking;

typedef struct palabraIndiceInvertido{
	char * id;
	int frecuencia;
	struct palabraIndiceInvertido * siguiente;
}palabraIndiceInvertido;

typedef struct Index{
	palabraIndiceInvertido * palabraIndice;
	char * palabra;
	struct Index * hijoIzquierdoIndex;
	struct Index * hijoDerechoIndex;
}Index;

typedef struct StopWords{
	char * palabra;
	struct StopWords * hijoDerechoStopWords;
	struct StopWords * hijoIzquierdoStopWords;
}StopWords;

typedef enum {
	OK, 
	ERR_FILE_NOT_FOUND, 
	ERR_FILE_NOT_PERM, 
	ERR_RESERVE_MEMORY, 
	NOT_ENOUGH_MEMORY, 
	NOT_SAVE_INDEX, 
	SAVE_INDEX, 
	INDEX_OK,
	INVALID_ID,
	QUERY_OK
} code;
#endif //_ESTRUCTURAS_H_