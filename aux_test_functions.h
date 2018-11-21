#pragma once

#include "gtest/gtest.h"

template<typename T, size_t size>
::testing::AssertionResult ArraysMatch(const T(&expected)[size],
                                       const T(&actual)[size])
{
	for (size_t i(0); i < size; ++i)
	{
		if (expected[i] != actual[i])
		{
			return ::testing::AssertionFailure() << "array[" << i
				<< "] (" << actual[i] << ") != esperado[" << i
				<< "] (" << expected[i] << ")";
		}
	}

	return ::testing::AssertionSuccess();
}

template<typename T, size_t size>
::testing::AssertionResult PartitionValid(const T(&A)[size], int p, int q, int r)
{
	for (int i = p; i < q; i++)
	{
		if (A[i] > A[q])
		{
			return ::testing::AssertionFailure() << "i(" << i << ") < q(" << q << "), A[i] (" << A[i] << ") > A[q] (" << A[q] << ")";
		}
	}
	
	for (int i = q+1; i <= r; i++)
	{
		if (A[i] < A[q])
		{
			return ::testing::AssertionFailure() << "i(" << i << ") > q(" << q << "), A[i] (" << A[i] << ") < A[q] (" << A[q] << ")";
		}
	}

	return ::testing::AssertionSuccess();
}

extern "C" void ordenacao_generica(int v[], int v_esperado[], int tamanho);
