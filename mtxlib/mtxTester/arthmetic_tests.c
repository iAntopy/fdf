
#include "mtxlib.h"

float	arr[4][3] = {{1, 2, 3},{10, 20, 30},{111, 222, 333},{1111, 2222, 3333}};
float	arr2[4][3] = {{10, 20, 30},{1, 2, 3},{9, 8, 7},{90, 80, 70}};


void	_mtx_opp_scalar_test(char *OPP_NAME, t_mtx *mtx, float sc, t_mtx *out, void (*opp)(t_mtx *, float, t_mtx *), void(*ropp)(float, t_mtx *, t_mtx *))
{
	printf("\n%s TEST : \n", OPP_NAME);
	printf("mtx :\n");
	mtx_print(mtx);
	printf("sc : %f\n", sc);
	if (OPP_NAME[0] == 'R')
		ropp(sc, mtx, out);
	else
		opp(mtx, sc, out);
	printf("%s m + s RESULT : \n", OPP_NAME);
	mtx_print(out);
}

void	_mtx_iopp_scalar_test(char *OPP_NAME, t_mtx *mtx, float sc, void (*iopp)(t_mtx *, float), void (*riopp)(float, t_mtx *))
{
	printf("\n%s TEST : \n", OPP_NAME);
	printf("mtx :\n");
	mtx_print(mtx);
	printf("sc : %f\n", sc);
	if (OPP_NAME[0] == 'R')
		riopp(sc, mtx);
	else
		iopp(mtx, sc);
	printf("%s m + s RESULT : \n", OPP_NAME);
	mtx_print(mtx);
}

void	_mtx_opp_line_test(char *OPP_NAME, t_mtx *mtx, t_mtx *line, t_mtx *out, void (*opp)(t_mtx *, t_mtx *, t_mtx *), void(*ropp)(t_mtx *, t_mtx *, t_mtx *))
{
	printf("\n%s TEST : \n", OPP_NAME);
	printf("mtx :\n");
	mtx_print(mtx);
	printf("line :\n");
	mtx_print(line);
	if (OPP_NAME[0] == 'R')
		ropp(line, mtx, out);
	else
		opp(mtx, line, out);
	printf("%s m + s RESULT : \n", OPP_NAME);
	mtx_print(out);
}

void	_mtx_iopp_line_test(char *OPP_NAME, t_mtx *mtx, t_mtx *line, void (*iopp)(t_mtx *, t_mtx *), void (*riopp)(t_mtx *, t_mtx *))
{
	printf("\n%s TEST : \n", OPP_NAME);
	printf("mtx :\n");
	mtx_print(mtx);
	printf("line :\n");
	mtx_print(line);
	if (OPP_NAME[0] == 'R')
		riopp(line, mtx);
	else
		iopp(mtx, line);
	printf("%s m + s RESULT : \n", OPP_NAME);
	mtx_print(mtx);
}

void	_mtx_opp_mtx_test(char *OPP_NAME, t_mtx *m1, t_mtx *m2, t_mtx *out, void (*opp)(t_mtx *, t_mtx *, t_mtx *))
{
	printf("\n%s TEST : \n", OPP_NAME);
	printf("m1 :\n");
	mtx_print(m1);
	printf("m2 :\n");
	mtx_print(m2);
	opp(m1, m2, out);
	printf("%s m + s RESULT : \n", OPP_NAME);
	mtx_print(out);
}

void	_mtx_iopp_mtx_test(char *OPP_NAME, t_mtx *m1, t_mtx *m2, void (*iopp)(t_mtx *, t_mtx *))
{
	printf("\n%s TEST : \n", OPP_NAME);
	printf("m1 :\n");
	mtx_print(m1);
	printf("m2 :\n");
	mtx_print(m2);
	iopp(m1, m2);
	printf("%s m + s RESULT : \n", OPP_NAME);
	mtx_print(m1);
}

int	main(void)
{
	t_mtx	*m1;
	t_mtx	*m2;
	t_mtx	*line;
	t_mtx	*out;
	float	sc;

	sc = 3;
	m1 = mtx_create_array(arr, 4, 3, DTYPE_F);
	m2 = mtx_create_array(arr2, 4, 3, DTYPE_F);
	line = mtx_select_row(m2, 0);
	out = mtx_create_empty(4, 3, DTYPE_F);
	printf("All matrices and views created SUCCESSFULY !\n");
/*
	// mtx scalar opps to output	
	_mtx_opp_scalar_test("ADD", m1, sc, out, _mtx_addf_scalar, NULL);
	_mtx_opp_scalar_test("SUB", m1, sc, out, _mtx_subf_scalar, _mtx_rsubf_scalar);
	_mtx_opp_scalar_test("MUL", m1, sc, out, _mtx_mulf_scalar, NULL);
	_mtx_opp_scalar_test("DIV", m1, sc, out, _mtx_divf_scalar, _mtx_rdivf_scalar);

	// mtx scalar ropps to output	
	_mtx_opp_scalar_test("RSUB", m1, sc, out, _mtx_subf_scalar, _mtx_rsubf_scalar);
	_mtx_opp_scalar_test("RDIV", m1, sc, out, _mtx_divf_scalar, _mtx_rdivf_scalar);

	// mtx scalar iopps in place	
	_mtx_iopp_scalar_test("IADD", m1, sc, _mtx_iaddf_scalar, NULL);
	_mtx_iopp_scalar_test("ISUB", m1, sc, _mtx_isubf_scalar, _mtx_risubf_scalar);
	_mtx_iopp_scalar_test("IMUL", m1, sc, _mtx_imulf_scalar, NULL);
	_mtx_iopp_scalar_test("IDIV", m1, sc, _mtx_idivf_scalar, _mtx_ridivf_scalar);

	// mtx scalar riopps in place
	_mtx_iopp_scalar_test("RISUB", m1, sc, _mtx_isubf_scalar, _mtx_risubf_scalar);
	_mtx_iopp_scalar_test("RIDIV", m1, sc, _mtx_idivf_scalar, _mtx_ridivf_scalar);
*/
	
/*
	// mtx line opps to output	
	_mtx_opp_line_test("ADD", m1, line, out, _mtx_addf_line, NULL);
	_mtx_opp_line_test("SUB", m1, line, out, _mtx_subf_line, _mtx_rsubf_line);
	_mtx_opp_line_test("MUL", m1, line, out, _mtx_mulf_line, NULL);
	_mtx_opp_line_test("DIV", m1, line, out, _mtx_divf_line, _mtx_rdivf_line);

	// mtx line ropps to output	
	_mtx_opp_line_test("RSUB", m1, line, out, _mtx_subf_line, _mtx_rsubf_line);
	_mtx_opp_line_test("RDIV", m1, line, out, _mtx_divf_line, _mtx_rdivf_line);

	// mtx line iopps in place
	_mtx_iopp_line_test("IADD", m1, line, _mtx_iaddf_line, NULL);
	_mtx_iopp_line_test("ISUB", m1, line, _mtx_isubf_line, _mtx_risubf_line);
	_mtx_iopp_line_test("IMUL", m1, line, _mtx_imulf_line, NULL);
	_mtx_iopp_line_test("IDIV", m1, line, _mtx_idivf_line, _mtx_ridivf_line);

	// mtx line riopps in place
	_mtx_iopp_line_test("RISUB", m1, line, _mtx_isubf_line, _mtx_risubf_line);
	_mtx_iopp_line_test("RIDIV", m1, line, _mtx_idivf_line, _mtx_ridivf_line);
*/


	// mtx mtx opps to output	
	_mtx_opp_mtx_test("ADD", m1, m2, out, _mtx_addf_mtx);
	_mtx_opp_mtx_test("SUB", m1, m2, out, _mtx_subf_mtx);
	_mtx_opp_mtx_test("MUL", m1, m2, out, _mtx_mulf_mtx);
	_mtx_opp_mtx_test("DIV", m1, m2, out, _mtx_divf_mtx);

	//mtx mtx opps reverse
	_mtx_opp_mtx_test("SUB reverse", m2, m1, out, _mtx_subf_mtx);
	_mtx_opp_mtx_test("DIV reverse", m2, m1, out, _mtx_divf_mtx);

	// mtx mtx iopps in place
	_mtx_iopp_mtx_test("IADD", m1, m2, _mtx_iaddf_mtx);
	_mtx_iopp_mtx_test("ISUB", m1, m2, _mtx_isubf_mtx);
	_mtx_iopp_mtx_test("IMUL", m1, m2, _mtx_imulf_mtx);
	_mtx_iopp_mtx_test("IDIV", m1, m2, _mtx_idivf_mtx);

	_mtx_iopp_mtx_test("ISUB", m2, m1, _mtx_isubf_mtx);
	_mtx_iopp_mtx_test("IDIV", m2, m1, _mtx_idivf_mtx);

	printf("Clearing all matrices : \n");
	mtx_clear_list(4, m1, m2, out, line);
	return (0);
}
