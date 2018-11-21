#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "lab8.h"
}

TEST(quick_sort, EspecificoArrayDoisElementosUmaTroca)
{
	int v[2] = { 1, 0 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1 };

	quick_sort(v, 0, sizeof(v)/sizeof(int) - 1);

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(quick_sort, EspecificoArrayQuatroElementosExigeOrdenacaoRecursiva)
{
	int v[4] = { 1, 0, 3, 2 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1, 2, 3 };

	quick_sort(v, 0, sizeof(v)/sizeof(int) - 1);

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

static void quick_sort_testes(int v[], int tam)
{
	quick_sort(v, 0, tam-1);
}

#define FUNCAO_ORDENACAO quick_sort_testes

#include "testes_ordenacao.h"