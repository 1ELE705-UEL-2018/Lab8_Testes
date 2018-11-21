#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
#include "lab8.h"
}

TEST(bubble_sort, EspecificoArrayDoisElementosUmaTroca)
{
	int v[2] = { 1, 0 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1 };

	bubble_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(bubble_sort, EspecificoArrayVazio)
{
	bubble_sort(NULL, 0);
}

TEST(bubble_sort, EspecificoArrayUmElemento)
{
	int v[2] = { 0, 1 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1 };

	bubble_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(bubble_sort, EspecificoArrayDoisElementosEmOrdem)
{
	int v[2] = { 0, 1 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1 };

	bubble_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(bubble_sort, EspecificoArrayTresElementosUmaPassadaDuasTrocas)
{
	int v[3] = { 2, 0, 1 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1, 2 };

	bubble_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

TEST(bubble_sort, EspecificoArrayTresElementosDuasPassadas)
{
	int v[3] = { 2, 1, 0 };
	int v_depois[sizeof(v)/sizeof(int)] = { 0, 1, 2 };

	bubble_sort(v, sizeof(v)/sizeof(int));

	ASSERT_TRUE(ArraysMatch(v_depois, v));
}

#define FUNCAO_ORDENACAO bubble_sort

#include "testes_ordenacao.h"