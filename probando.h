
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