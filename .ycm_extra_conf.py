
#
# This file is used by YouCompleteMe to provide flags to clangd to assist in
# code completion. It is not used by the build system. Please refrain from
# modifying this file as it can cause issues with code completion and possibly
# result in a broken build.
#

def Settings( **kwargs ):
    return {
            'flags': [

                    # Tell clangd to use c++

                    '-x',
                    'c++',

                    # Project source paths

                    '-I./src/package_manager/',
                    '-I./src/compiler/',
                    '-I./src/driver/'

                    # LLVM config flags

                    '-I/usr/include',
                    '-std=c++14',
                    '-fno-exceptions',
                    '-D_GNU_SOURCE',
                    '-D__STDC_CONSTANT_MACROS',
                    '-D__STDC_FORMAT_MACROS'
                    '-D__STDC_LIMIT_MACROS',
                    '-L/usr/lib',
                    '-lLLVM-14'
                    ],
            }
