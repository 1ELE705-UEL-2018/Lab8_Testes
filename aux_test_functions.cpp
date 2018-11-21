#include <cstdlib>
#include <cstring>

static int compara_int(const void* a, const void* b)
{
	const int* aa = (const int*)a;
	const int* bb = (const int*)b;

	return *aa - *bb;
}

extern "C"
void ordenacao_generica(int v[], int v_esperado[], int tamanho)
{
	memmove(v_esperado, v, tamanho*sizeof(int));
	qsort(v_esperado, tamanho, sizeof(int), compara_int);
}
