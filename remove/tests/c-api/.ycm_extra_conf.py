
#
# This file is used by YouCompleteMe to provide flags to clangd to assist in
# code completion. It is not used by the build system. Please refrain from
# modifying this file as it can cause issues with code completion and possibly
# result in a broken build.
#

def Settings( **kwargs ):
    return {
            'flags': [

                    # Tell clangd to use c

                    '-x',
                    'c',

                    ],
            }
