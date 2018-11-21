#include <cstdlib>
#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "lab8.h"
}

TEST(merge_sort, EspecificoArrayDoisElementosForaDeOrdem)
{
	int v[2] = { 1, 0 };
	int temp[sizeof(v)/sizeof(int)];
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1 };

	merge_sort(v, temp, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(merge_sort, EspecificoArrayUmElemento)
{
	int v[1] = { 0 };
	int temp[sizeof(v)/sizeof(int)];
	int v_depois[sizeof(v)/sizeof(int)] = { 0 };

	merge_sort(v, temp, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(merge_sort, EspecificoArrayQuatroElementosSomenteMerge)
{
	int v[4] = { 0, 3, 1, 2 };
	int temp[sizeof(v)/sizeof(int)];
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1, 2, 3 };

	merge_sort(v, temp, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(merge_sort, EspecificoArrayQuatroElementosExigeOrdenacaoRecursiva)
{
	int v[4] = { 3, 0, 2, 1 };
	int temp[sizeof(v)/sizeof(int)];
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1, 2, 3 };

	merge_sort(v, temp, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(merge_sort, EspecificoArrayTresElementosExigeOrdenacaoRecursiva)
{
	int v[3] = { 2, 1, 0 };
	int temp[sizeof(v)/sizeof(int)];
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1, 2 };

	merge_sort(v, temp, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

static void merge_sort_testes(int v[], int tam)
{
	int* temp = (int*)malloc(tam*sizeof(int));
	merge_sort(v, temp, tam);
	free(temp);
}

#define FUNCAO_ORDENACAO merge_sort_testes

#include "testes_ordenacao.h"