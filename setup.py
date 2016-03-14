from distutils.core import setup, Extension

module1 = Extension('aCync', sources = ['aCync_module.c', 'aCync_data.c'])

setup (name = 'aCync',
        version = '1.0',
        description = 'An asynchronous communication for C-based Python3 extensions',
        ext_modules = [module1])
