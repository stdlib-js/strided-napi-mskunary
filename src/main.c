/**
* @license Apache-2.0
*
* Copyright (c) 2020 The Stdlib Authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "stdlib/strided/napi/mskunary.h"
#include "stdlib/strided/base/function_object.h"
#include "stdlib/strided/napi/addon_arguments.h"
#include <node_api.h>
#include <stdint.h>
#include <assert.h>

/**
* Invokes a strided array interface which applies a unary callback to an input strided array according to a mask strided array and based on provided JavaScript arguments.
*
* ## Notes
*
* -   This function expects that the callback `info` argument provides access to the following JavaScript arguments:
*
*     -   `N`: number of indexed elements
*     -   `dtypeX`: `X` data type (enumeration constant)
*     -   `X`: input array
*     -   `strideX`: `X` stride length
*     -   `dtypeMask`: `Mask` data type (enumeration constant)
*     -   `Mask`: mask array
*     -   `strideMask`: `Mask` stride length
*     -   `dtypeY`: `Y` data type (enumeration constant)
*     -   `Y`: destination array
*     -   `strideY`: `Y` stride length
*
* @param env    environment under which the function is invoked
* @param info   callback data
* @param obj    strided array function object
*/
void stdlib_strided_napi_mskunary( napi_env env, napi_callback_info info, const struct StridedFunctionObject *obj ) {
	napi_status status;

	// Total number of input arguments:
	int64_t nargs = 10;

	// Number of input strided array arguments (including the mask strided array):
	int64_t nin = 2;

	// Get callback arguments:
	size_t argc = 10;
	napi_value argv[ 10 ];
	status = napi_get_cb_info( env, info, &argc, argv, NULL, NULL );
	assert( status == napi_ok );

	// Check whether we were provided the correct number of arguments:
	int64_t argc64 = (int64_t)argc;
	if ( argc64 < nargs ) {
		status = napi_throw_error( env, NULL, "invalid invocation. Insufficient arguments." );
		assert( status == napi_ok );
		return;
	}
	if ( argc64 > nargs ) {
		status = napi_throw_error( env, NULL, "invalid invocation. Too many arguments." );
		assert( status == napi_ok );
		return;
	}
	// Process the provided arguments:
	uint8_t *arrays[ 3 ];
	int64_t strides[ 3 ];
	int64_t shape[ 1 ];
	int32_t types[ 3 ];

	napi_value err;
	status = stdlib_strided_napi_addon_arguments( env, argv, nargs, nin, arrays, shape, strides, types, &err );
	assert( status == napi_ok );

	// Check whether processing was successful:
	if ( err != NULL ) {
		status = napi_throw( env, err );
		assert( status == napi_ok );
		return;
	}
	// Resolve the strided array function satisfying the input array types:
	int64_t idx = stdlib_strided_function_dispatch_index_of( obj, types );

	// Check whether we were able to successfully resolve a strided array function:
	if ( idx < 0 ) {
		status = napi_throw_type_error( env, NULL, "invalid arguments. Unable to resolve a strided array function supporting the provided array argument data types." );
		assert( status == napi_ok );
		return;
	}
	// Retrieve the strided array function:
	StridedArrayFcn fcn = obj->functions[ idx ];

	// Retrieve the associated function data:
	void *clbk = obj->data[ idx ];

	// Evaluate the strided array function:
	fcn( arrays, shape, strides, clbk );

	return;
}
