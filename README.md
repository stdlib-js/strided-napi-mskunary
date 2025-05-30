<!--

@license Apache-2.0

Copyright (c) 2020 The Stdlib Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

-->


<details>
  <summary>
    About stdlib...
  </summary>
  <p>We believe in a future in which the web is a preferred environment for numerical computation. To help realize this future, we've built stdlib. stdlib is a standard library, with an emphasis on numerical and scientific computation, written in JavaScript (and C) for execution in browsers and in Node.js.</p>
  <p>The library is fully decomposable, being architected in such a way that you can swap out and mix and match APIs and functionality to cater to your exact preferences and use cases.</p>
  <p>When you use stdlib, you can be absolutely certain that you are using the most thorough, rigorous, well-written, studied, documented, tested, measured, and high-quality code out there.</p>
  <p>To join us in bringing numerical computing to the web, get started by checking us out on <a href="https://github.com/stdlib-js/stdlib">GitHub</a>, and please consider <a href="https://opencollective.com/stdlib">financially supporting stdlib</a>. We greatly appreciate your continued support!</p>
</details>

# mskunary

[![NPM version][npm-image]][npm-url] [![Build Status][test-image]][test-url] [![Coverage Status][coverage-image]][coverage-url] <!-- [![dependencies][dependencies-image]][dependencies-url] -->

> C API for registering a Node-API module exporting a strided array interface for applying a unary callback to an input strided array according to a mask strided array.

<!-- Section to include introductory text. Make sure to keep an empty line after the intro `section` element and another before the `/section` close. -->

<section class="intro">

</section>

<!-- /.intro -->

<!-- Package usage documentation. -->

<section class="installation">

## Installation

```bash
npm install @stdlib/strided-napi-mskunary
```

</section>

<section class="usage">

## Usage

```javascript
var headerDir = require( '@stdlib/strided-napi-mskunary' );
```

#### headerDir

Absolute file path for the directory containing header files for C APIs.

```javascript
var dir = headerDir;
// returns <string>
```

</section>

<!-- /.usage -->

<!-- Package usage notes. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->

<section class="notes">

</section>

<!-- /.notes -->

<!-- Package usage examples. -->

<section class="examples">

## Examples

```javascript
var headerDir = require( '@stdlib/strided-napi-mskunary' );

console.log( headerDir );
// => <string>
```

</section>

<!-- /.examples -->

<!-- C interface documentation. -->

* * *

<section class="c">

## C APIs

<!-- Section to include introductory text. Make sure to keep an empty line after the intro `section` element and another before the `/section` close. -->

<section class="intro">

</section>

<!-- /.intro -->

<!-- C usage documentation. -->

<section class="usage">

### Usage

```c
#include "stdlib/strided/napi/mskunary.h"
```

#### stdlib_strided_napi_mskunary( env, info, \*obj )

Invokes a strided array interface which applies a unary callback to an input strided array according to a mask strided array and based on provided JavaScript arguments.

```c
#include "stdlib/strided/base/function_object.h"
#include <node_api.h>

// ...

static const struct StridedFunctionObject obj = {...};

// ...

/**
* Receives JavaScript callback invocation data.
*
* @param env    environment under which the function is invoked
* @param info   callback data
* @return       Node-API value
*/
napi_value addon( napi_env env, napi_callback_info info ) {
    stdlib_strided_napi_mskunary( env, info, &obj );
    return NULL;
}

// ...
```

The function accepts the following arguments:

-   **env**: `[in] napi_env` environment under which the function is invoked.
-   **info**: `[in] napi_callback_info` callback data.
-   **obj**: `[in] struct StridedFunctionObject*` strided array [function object][@stdlib/strided/base/function-object].

```c
void stdlib_strided_napi_mskunary( napi_env env, napi_callback_info info, const struct StridedFunctionObject *obj );
```

#### STDLIB_STRIDED_NAPI_MODULE_MSKUNARY( obj )

Macro for registering a Node-API module exporting a strided array interface for applying a unary callback to an input strided array according to a mask strided array.

```c
#include "stdlib/strided/base/function_object.h"

// ...

// Create a strided function object:
static const struct StridedFunctionObject obj = {...};

// ...

// Register a Node-API module:
STDLIB_STRIDED_NAPI_MODULE_MSKUNARY( obj );
```

The macro expects the following arguments:

-   **obj**: `struct StridedFunctionObject` strided array [function object][@stdlib/strided/base/function-object].

When used, this macro should be used **instead of** `NAPI_MODULE`. The macro includes `NAPI_MODULE`, thus ensuring Node-API module registration.

</section>

<!-- /.usage -->

<!-- C API usage notes. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->

<section class="notes">

### Notes

-   The function expects that the callback `info` argument provides access to the following JavaScript arguments:

    -   **N**: number of indexed elements.
    -   **dtypeX**: `X` [data type][@stdlib/strided/dtypes] (enumeration constant).
    -   **X**: input [typed array][mdn-typed-array].
    -   **strideX**: `X` stride length.
    -   **dtypeMask**: `Mask` [data type][@stdlib/strided/dtypes] (enumeration constant).
    -   **Mask**: mask [`Uint8Array`][@stdlib/array/uint8].
    -   **strideMask**: `Mask` stride length.
    -   **dtypeY**: `Y` [data type][@stdlib/strided/dtypes] (enumeration constant).
    -   **Y**: destination [typed array][mdn-typed-array].
    -   **strideY**: `Y` stride length.

</section>

<!-- /.notes -->

<!-- C API usage examples. -->

<section class="examples">

</section>

<!-- /.examples -->

</section>

<!-- /.c -->

<!-- Section to include cited references. If references are included, add a horizontal rule *before* the section. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->

<section class="references">

</section>

<!-- /.references -->

<!-- Section for related `stdlib` packages. Do not manually edit this section, as it is automatically populated. -->

<section class="related">

</section>

<!-- /.related -->

<!-- Section for all links. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->


<section class="main-repo" >

* * *

## Notice

This package is part of [stdlib][stdlib], a standard library for JavaScript and Node.js, with an emphasis on numerical and scientific computing. The library provides a collection of robust, high performance libraries for mathematics, statistics, streams, utilities, and more.

For more information on the project, filing bug reports and feature requests, and guidance on how to develop [stdlib][stdlib], see the main project [repository][stdlib].

#### Community

[![Chat][chat-image]][chat-url]

---

## License

See [LICENSE][stdlib-license].


## Copyright

Copyright &copy; 2016-2025. The Stdlib [Authors][stdlib-authors].

</section>

<!-- /.stdlib -->

<!-- Section for all links. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->

<section class="links">

[npm-image]: http://img.shields.io/npm/v/@stdlib/strided-napi-mskunary.svg
[npm-url]: https://npmjs.org/package/@stdlib/strided-napi-mskunary

[test-image]: https://github.com/stdlib-js/strided-napi-mskunary/actions/workflows/test.yml/badge.svg?branch=main
[test-url]: https://github.com/stdlib-js/strided-napi-mskunary/actions/workflows/test.yml?query=branch:main

[coverage-image]: https://img.shields.io/codecov/c/github/stdlib-js/strided-napi-mskunary/main.svg
[coverage-url]: https://codecov.io/github/stdlib-js/strided-napi-mskunary?branch=main

<!--

[dependencies-image]: https://img.shields.io/david/stdlib-js/strided-napi-mskunary.svg
[dependencies-url]: https://david-dm.org/stdlib-js/strided-napi-mskunary/main

-->

[chat-image]: https://img.shields.io/gitter/room/stdlib-js/stdlib.svg
[chat-url]: https://app.gitter.im/#/room/#stdlib-js_stdlib:gitter.im

[stdlib]: https://github.com/stdlib-js/stdlib

[stdlib-authors]: https://github.com/stdlib-js/stdlib/graphs/contributors

[stdlib-license]: https://raw.githubusercontent.com/stdlib-js/strided-napi-mskunary/main/LICENSE

[mdn-typed-array]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/TypedArray

[@stdlib/strided/base/function-object]: https://github.com/stdlib-js/strided-base-function-object

[@stdlib/array/uint8]: https://github.com/stdlib-js/array-uint8

[@stdlib/strided/dtypes]: https://github.com/stdlib-js/strided-dtypes

</section>

<!-- /.links -->
