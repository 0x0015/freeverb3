/*
 * Copyright (C) 2002-2004 Erik de Castro Lopo <erikd@mega-nerd.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef COMMON_C_H_INCLUDED
#define COMMON_C_H_INCLUDED

#ifdef HAVE_STDINT_H
#include <stdint.h>
#elif (SIZEOF_LONG == 4)
typedef	long int32_t;
#elif (SIZEOF_LONG == 4)
typedef	long int32_t;
#endif

#define	SRC_MAX_RATIO (256)
#define SRC_MAX_RATIO_STR "256"
#define	SRC_MIN_RATIO_DIFF (1e-20)

#define	MAX(a,b) (((a) > (b)) ? (a) : (b))
#define	MIN(a,b) (((a) < (b)) ? (a) : (b))

#define	ARRAY_LEN(x) ((long)(sizeof(x) / sizeof((x)[0])))
#define OFFSETOF(type,member) ((int) (&((type*) 0)->member))

#define	MAKE_MAGIC(a,b,c,d,e,f)	((a) + ((b) << 4) + ((c) << 8) + ((d) << 12) + ((e) << 16) + ((f) << 20))

#ifdef __GNUC__
#define WARN_UNUSED      __attribute__ ((warn_unused_result))
#else
#define WARN_UNUSED
#endif

enum
{	SRC_FALSE	= 0,
	SRC_TRUE	= 1,

	SRC_MODE_PROCESS	= 555,
	SRC_MODE_CALLBACK	= 556
} ;

enum
{	SRC_ERR_NO_ERROR = 0,

	SRC_ERR_MALLOC_FAILED,
	SRC_ERR_BAD_STATE,
	SRC_ERR_BAD_DATA,
	SRC_ERR_BAD_DATA_PTR,
	SRC_ERR_NO_PRIVATE,
	SRC_ERR_BAD_SRC_RATIO,
	SRC_ERR_BAD_PROC_PTR,
	SRC_ERR_SHIFT_BITS,
	SRC_ERR_FILTER_LEN,
	SRC_ERR_BAD_CONVERTER,
	SRC_ERR_BAD_CHANNEL_COUNT,
	SRC_ERR_SINC_BAD_BUFFER_LEN,
	SRC_ERR_SIZE_INCOMPATIBILITY,
	SRC_ERR_BAD_PRIV_PTR,
	SRC_ERR_BAD_SINC_STATE,
	SRC_ERR_DATA_OVERLAP,
	SRC_ERR_BAD_CALLBACK,
	SRC_ERR_BAD_MODE,
	SRC_ERR_NULL_CALLBACK,
	SRC_ERR_NO_VARIABLE_RATIO,
	SRC_ERR_SINC_PREPARE_DATA_BAD_LEN,

	/* This must be the last error number. */
	SRC_ERR_MAX_ERROR
} ;

const char* sinc_get_name (long src_enum) ;
const char* sinc_get_description (long src_enum) ;
const char* linear_get_name (long src_enum) ;
const char* linear_get_description (long src_enum) ;
const char* zoh_get_name (long src_enum) ;
const char* zoh_get_description (long src_enum) ;

#include <math.h>

#define STRINGIZEx(x) #x
#define STRINGIZE(x) STRINGIZEx(x)

#ifdef DEBUG
#define SR2_UNDENORMAL(v)						\
  if((std::fpclassify(v)!=FP_NORMAL)&&(std::fpclassify(v)!=FP_ZERO))              \
    {fprintf(stderr, "^[" STRINGIZE(v) "=%d]",std::fpclassify(v));v=0;}
#else
#define SR2_UNDENORMAL(v)						\
  if(std::fpclassify(v) != FP_NORMAL&&std::fpclassify(v) != FP_ZERO){v=0;}
#endif

#endif	/* COMMON_H_INCLUDED */
