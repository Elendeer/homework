<!--
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 21:16:31
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 21:44:43
 * @Description  :
-->

# C-source-code Style Analyzer

## Introduce

This tool is used to analyze the style of C source code.
Infact it's kind of useless, because I am not seriously
wrote it for using it, but for ~~finishing my homework~~
testing cross-platform code.

So, this code can be builded both in MSWin and GNU/Linux. But
may have some problems in some different distributions
because I have not test all.

## Usage

```shell
csa [options] [file || relative path of file || abslute path of file]

Options:
  -s, -src      show source codes program read.
  -token        show tokens lexer read from the source code.
  -t            testing mode, does exactly the same thing as using
                -src -token.
  -h, -help     show this help message and exit.
```

Example:

```shell
csa -h
csa -src test.c
csa -token ../test.c
```

With file input, it will show a style assessment result which
is completely nonsense,  as I think.

## Build

On GNU/Linux, use 'make'.

On MSWin, use 'mingw32-make.exe', *mingw* is needed.
