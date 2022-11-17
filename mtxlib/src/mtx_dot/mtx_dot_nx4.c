#include "mtxlib.h"

// Not usable with view output
void	__mtx_dotf_4x4_4x4(float *a, float *b, float *out)
{
//	printf("Starting dot 4x4 ...\n");
	*(out++) = a[0] * b[0] + a[1] * b[4] + a[2] * b[8] + a[3] * b[12];
	*(out++) = a[0] * b[1] + a[1] * b[5] + a[3] * b[9] + a[3] * b[13];
	*(out++) = a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + a[3] * b[14];
	*(out++) = a[0] * b[3] + a[1] * b[7] + a[2] * b[11] + a[3] * b[15];
 	*(out++) = a[4] * b[0] + a[5] * b[4] + a[6] * b[8] + a[7] * b[12];
	*(out++) = a[4] * b[1] + a[5] * b[5] + a[6] * b[9] + a[7] * b[13];
	*(out++) = a[4] * b[2] + a[5] * b[6] + a[6] * b[10] + a[7] * b[14];
	*(out++) = a[4] * b[3] + a[5] * b[7] + a[6] * b[11] + a[7] * b[15];
	*(out++) = a[8] * b[0] + a[9] * b[4] + a[10] * b[8] + a[11] * b[12];
	*(out++) = a[8] * b[1] + a[9] * b[5] + a[10] * b[9] + a[11] * b[13];
	*(out++) = a[8] * b[2] + a[9] * b[6] + a[10] * b[10] + a[11] * b[14];
	*(out++) = a[8] * b[3] + a[9] * b[7] + a[10] * b[11] + a[11] * b[15];
	*(out++) = a[12] * b[0] + a[13] * b[4] + a[14] * b[8] + a[15] * b[12];
	*(out++) = a[12] * b[1] + a[13] * b[5] + a[14] * b[9] + a[15] * b[13];
	*(out++) = a[12] * b[2] + a[13] * b[6] + a[14] * b[10] + a[15] * b[14];
	*(out++) = a[12] * b[3] + a[13] * b[7] + a[14] * b[11] + a[15] * b[15];
//	printf("dot product complet!\n");
}

// Not usable with view output
void	__mtx_dotf_nx4_4x4(int n, float *a, float *b, float *out)
{
	float	a0;
	float	a1;
	float	a2;
	float	a3;

	while (n--)
	{
		a0 = *(a++);
		a1 = *(a++);
		a2 = *(a++);
		a3 = *(a++);
		*(out++) = a0 * b[0] + a1 * b[4] + a2 * b[8] + a3 * b[12];
		*(out++) = a0 * b[1] + a1 * b[5] + a2 * b[9] + a3 * b[13];
		*(out++) = a0 * b[2] + a1 * b[6] + a2 * b[10] + a3 * b[14];
		*(out++) = a0 * b[3] + a1 * b[7] + a2 * b[11] + a3 * b[15];
	}
}
