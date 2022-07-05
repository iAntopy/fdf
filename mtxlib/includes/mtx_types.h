/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:14:49 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 15:55:12 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	MTX_TYPES_H
# define MTX_TYPES_H

enum	mtx_data_types
{
	DTYPE_I = 0,
	DTYPE_F = 1
};

enum	mtx_axis_IDs
{
	WHOLE = -1,
	ROWWISE = 0,
	COLWISE = 1
};

typedef unsigned char U_CHAR;
typedef unsigned int U_INT;

typedef struct s_mtx_base
{
	int		ndims;
	int		dtype;
	int		shape[MAX_DIMS];
	int		strides[MAX_DIMS];
	void	*arr;
	void	*swap;
	void	**view_ptr;
	int		is_view;
	size_t	offset;
	int		is_transposed;
}	t_mtx;

typedef struct s_math_opp
{
	void	*a;	// mtx a offset arr ptr;
	void	*b;	// mtx b offset arr ptr;
	void	*o;	// mtx out offset arr ptr;
	int	*as;	// mtx a strides
	int	*bs;	// mtx b strides
	int	*os;	// mtx b strides
	int	r;	// mtx a nb of rows
	int	c;	// mtx b nb of cols
	void	*av;	// mtx a value ptr
	void	*bv;	// mtx b value ptr
	void	*ov;	// mtx out value ptr
	void	(*opp)();	// math opp to execute
	float	(*oppf)(float);	// math opp to execute with float return
	int		(*oppi)(int);	// math opp to execute with int return
}	t_mopp;

typedef struct s_cumul_opp
{
	void	*a;	// mtx a offset arr ptr;
	void	*o;	// mtx out offset arr ptr;
	int	*as;	// mtx a strides
	int	*os;	// mtx b strides
	int	r;	// mtx a nb of rows
	int	c;	// mtx b nb of cols
	void	*av;	// mtx a value ptr
	void	*ov;	// mtx out value ptr
	void	(*init_opp)();	// opp to exec either at start of cumulative opperation (eg.: set ov = 1 for prod, set ov = INT_MAX for min opp, to INT_MIN for max opp)
	void	(*cumul_opp)();	// cumulative opp to execute in row/col or whole array where result is accumulated at output. (eg.: out += av for sum, out *= for prod)
	void	(*post_opp)();	// optional post opperation at the end of the rowwise/colwise opperation. (eg.: out /= (row_len) or \= col_len for mean). If post_opp is NULL, no post opp will be performed (eg.: sum and prod have no post_opp).
}	t_copp;

typedef struct s_quaternion_base
{
	float	uv[4];
	float	q[4];
	float	rot_mtx[4][4];
}	t_quat;

typedef void (*UFUNC_SIDED)(t_mtx *, t_mtx *);
typedef void (*MOPP_FUNC)(t_mtx *, t_mtx *, t_mtx *);

#endif
