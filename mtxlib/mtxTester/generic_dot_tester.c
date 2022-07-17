/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_dot_tester.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:23:50 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/12 20:27:25 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

float	arr[4][3] = {{1, 2, 3}, {5, 6, 7}, {9, 8, 7}, {6, 5, 4}};

int	unit_test_failure(char *origin)
{
	printf(RED_BC"\n ¡~^~ UNIT_TEST < "YELLOW_BC"%s"RED_BC" > FAILURE ~^~!\n"WHITE_C, origin);
	return (0);
}

int	unit_test_success(char *origin)
{
	printf(GREEN_BC"\n ¡~~~ UNIT_TEST < "YELLOW_BC"%s"GREEN_BC" > SUCCESS ~~~!\n"WHITE_C, origin);
	return (1);
}

int	test1_a_dot_b_malloc_out(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	eye = mtx_identity(3, NULL, DTYPE_F);
	if (!mtx || !eye)
		return (unit_test_failure(title));
	
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_dot(mtx, eye, NULL);
	if (!res)
		return (unit_test_failure(title));
	else
		printf("Resulting output array\n");
	mtx_print(res);
	mtx_display_info(res);

	mtx_clear_list(3, mtx, eye, res);
	return (unit_test_success(title));
}

int	test2_a_dot_b_initialized_out(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	eye = mtx_identity(3, NULL, DTYPE_F);
	if (!mtx || !eye)
		return (unit_test_failure(title));
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_create_empty(4, 3, DTYPE_F);
	
	if (!mtx_dot(mtx, eye, res))
		return (unit_test_failure(title));
	else
		printf("Resulting output array\n");
	mtx_print(res);
	mtx_display_info(res);
	mtx_clear_list(3, mtx, eye, res);
	return (unit_test_success(title));
}

int	test3_a_dot_b_init_mismatch_shape_out(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	eye = mtx_identity(3, NULL, DTYPE_F);
	if (!mtx || !eye)
		return (unit_test_failure(title));
	
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_create_empty(3, 4, DTYPE_F);

	if (!mtx_dot(mtx, eye, res))
		return (unit_test_success(title));
	
	mtx_clear_list(3, mtx, eye, res);
	printf("TEST SHOULD HAVE FAILED BUT DIDN'T\n");
	return (unit_test_failure(title));
}

int	test4_mismatch_input_mtx_malloc_out(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	eye = mtx_identity(4, NULL, DTYPE_F);
	if (!mtx || !eye)
		return (unit_test_failure(title));
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_dot(mtx, eye, NULL);
	if (!res)
		return (unit_test_success(title));

	mtx_clear_list(3, mtx, eye, res);
	printf("TEST SHOULD HAVE FAILED BUT DIDN'T\n");
	return (unit_test_failure(title));
}

int	test5_array_a_dot_array_b_inplace_out_to_a(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	eye = mtx_identity(3, NULL, DTYPE_F);
	if (!mtx || !eye)
		return (unit_test_failure(title));
	
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	_mtx_imulf_pscalar(eye, 2);
	printf("Init B eye * 2 :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	printf("Inplace dot result : \n");
	mtx_dot(mtx, eye, mtx);
	mtx_print(mtx);
	mtx_display_info(mtx);

	mtx_clear_list(2, mtx, eye);
	return (unit_test_success(title));
}

int	test6_array_a_dot_array_b_triple_inplace_to_a_swap_test(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	void	*arr_ptr1;
	void	*arr_ptr2;
	void	*arr_ptr3;
	void	*arr_ptr4;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	eye = mtx_identity(3, NULL, DTYPE_F);
	if (!mtx || !eye)
		return (unit_test_failure(title));
	
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	_mtx_imulf_pscalar(eye, 2);
	printf("Init B eye * 2 :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	printf("Inplace dot result : \n");
	
	arr_ptr1 = mtx->arr;

	mtx_dot(mtx, eye, mtx);
	printf("\ninfo after call 1\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	arr_ptr2 = mtx->arr;

	mtx_dot(mtx, eye, mtx);
	printf("\ninfo after call 2\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	arr_ptr3 = mtx->arr;

	mtx_dot(mtx, eye, mtx);
	printf("\ninfo after call 3\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	arr_ptr4 = mtx->arr;

	printf("arr ptrs between dot calls : 1. %p, 2. %p, 3. %p, 4. %p\n", arr_ptr1, arr_ptr2, arr_ptr3, arr_ptr4);

	mtx_clear_list(2, mtx, eye);
	return (unit_test_success(title));
}

int	test7_array_a_dot_array_b_output_to_view(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	t_mtx	*view;
	int	slice[4] = {6, 7, 10, 10};
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	eye = mtx_identity(3, NULL, DTYPE_F);
	
	if (!mtx || !eye)
		return (unit_test_failure(title));
	
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_create_zeros(10, 10, DTYPE_F);
	if (!res)
		return (unit_test_failure(title));
	printf("Zeros filled 10x10 mtx\n");
	printf("res array ptr : %p\n", res->arr);
	mtx_print(res);
	mtx_display_info(res);

	view = mtx_slice_view(res, slice);
	if (!view)
		return (unit_test_failure(title));
	mtx_print(view);
	mtx_display_info(view);

	if (!mtx_dot(mtx, eye, view))
		return (unit_test_failure(title));

	printf("Resulting view output :\n");
	mtx_print(view);
	mtx_display_info(view);

	printf("Resulting 10x10 mtx :\n");
	mtx_print(res);
	mtx_display_info(res);
	
	mtx_clear_list(4, mtx, eye, res, view);
	return (unit_test_success(title));
}

int	test8_array_a_dot_array_b_output_to_inplace_view_of_a(int test_nb, char *title)
{
	t_mtx	*mtx1;
	t_mtx	*mtx2;
	t_mtx	*view;
	int	slice[4] = {0, 1, -1, -1};
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx1 = mtx_create_array(arr, 4, 3, DTYPE_F);
	mtx2 = mtx_create_array(arr, 4, 3, DTYPE_F);
	if (!mtx1 || !mtx2)
		return (unit_test_failure(title));

	mtx_transpose(mtx1);
	printf("Init A matrix :\n");
	printf("mtx1 is transposed %d\n", mtx_istransposed(mtx1));
	mtx_print(mtx1);
	mtx_display_info(mtx1);

	printf("Init B matrix :\n");
	mtx_print(mtx2);
	mtx_display_info(mtx2);

	view = mtx_slice_view(mtx1, slice);
	if (!view)
		return (unit_test_failure(title));
	printf("Sliced view :\n");
	mtx_print(view);
	mtx_display_info(view);

	if (!mtx_dot(mtx1, mtx2, view))
		return (unit_test_failure(title));

	printf("Resulting view output :\n");
	mtx_print(view);
	mtx_display_info(view);

	printf("Resulting A mtx output:\n");
	mtx_print(mtx1);
	mtx_display_info(mtx1);
	
	mtx_clear_list(3, mtx1, mtx2, view);
	return (unit_test_success(title));
}

int	test9_view_a_dot_view_a_inplace_to_view(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*view;
	int	slice[4] = {0, 1, -1, -1};

	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	if (!mtx)
		return (unit_test_failure(title));

	mtx_transpose(mtx);
	printf("Init A matrix :\n");
	printf("mtx is transposed %d\n", mtx_istransposed(mtx));
	mtx_print(mtx);
	mtx_display_info(mtx);

	view = mtx_slice_view(mtx, slice);
	if (!view)
		return (unit_test_failure(title));
	printf("Sliced view :\n");
	mtx_print(view);
	mtx_display_info(view);

	if (!mtx_dot(view, view, view))
		return (unit_test_failure(title));

	printf("Resulting view output :\n");
	mtx_print(view);
	mtx_display_info(view);

	printf("Resulting mtx output :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);
	
	mtx_clear_list(2, mtx, view);
	return (unit_test_success(title));
}
	

int main()
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	int		slice[4] = {0,0,3,3};

	t_mtx	*mtx_view;
	t_mtx	*eye_view;

	printf(YELLOW_BC"\n\n[[ @@@@@@ --- GENERIC DOT PRODUCT TEST SUITE --- @@@@@@ ]]\n"WHITE_C);

	test1_a_dot_b_malloc_out(1, "array a dot array b -> malloced out");
	test2_a_dot_b_initialized_out(2, "array a dot array b -> initialized out");
	test3_a_dot_b_init_mismatch_shape_out(3, "array a dot array b -> mismatched initialized out");
	test4_mismatch_input_mtx_malloc_out(4, "mismatch input mtx -> malloced out");
	test5_array_a_dot_array_b_inplace_out_to_a(5, "array a dot array b -> inplace output to a");
	test6_array_a_dot_array_b_triple_inplace_to_a_swap_test(6, "array a dot array b -> triple inplace out to a");
	test7_array_a_dot_array_b_output_to_view(7, "array a dot array b -> output to array c view");
	test8_array_a_dot_array_b_output_to_inplace_view_of_a(8, "array a dot array b -> out to inplace arr a view");
	test9_view_a_dot_view_a_inplace_to_view(9, "trans arr a view dot trans arr a view -> out to view of a");
	/*
	printf(WHITE_BC"\n --- inplace test --- \n"WHITE_C);
	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	mtx_print(mtx);
	mtx_display_info(mtx);
	
	eye = mtx_identity(3, NULL, DTYPE_F);
	printf("\nResulting eye mtx\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_dot(mtx, eye, NULL);

	mtx_print(res);
	mtx_display_info(res);
	
	*(float *)mtx_index(eye, 2, 2) = 10;

	printf("dot inplace result\n");
	mtx_dot(res, eye, res);
	mtx_print(res);
	mtx_display_info(res);

	printf(WHITE_BC"\n --- inplace through view test --- \n"WHITE_C);

	mtx_clear(&mtx);
	mtx_clear(&eye);
	mtx_clear(&res);
*/
	return (0);
}
