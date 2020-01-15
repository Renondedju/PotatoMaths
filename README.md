# PotatoMaths

Flexible realtime c++ math library designed with game programming and 3D rendering in mind

## Configuration

Defining the following symbols to modify the behavior of the library: 

- `POTATO_ENABLE_TEMPLATE_PREGEN` -> Enable templated functions pre generation for some common types
> Enabling this can improve compilation times by quite a bit but will increase the size of the binary
> and might prevent the compiler from inlining some functions (and possibly giving up a run-time optimization).
> Enabling the link time optimization flag (-flto on gcc) along with this symbol is a great idea

## Licence

MIT License

Copyright (c) 2019-2020 Basile Combet

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
