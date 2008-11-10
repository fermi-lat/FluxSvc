# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/SConscript,v 1.3 2008/11/02 01:30:10 glastrm Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-55-01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('FluxSvcLib', depsOnly = 1)
libEnv.Tool('tipLib')
libEnv.Tool('f2cLib')

# The oldnames library below comes from the macro f2c_linkopts coming from f2c/cmt/requirements.  
# I added it to this file because of the -import=f2c in the requirements file for this SConscript.

FluxSvc = libEnv.SharedLibrary('FluxSvc', listFiles(['FluxSvc/*.cxx','src/Dll/*.cxx','src/*.cxx']))


progEnv.Tool('FluxSvcLib')


progEnv.Tool('registerObjects', package = 'FluxSvc', libraries = [FluxSvc], includes = listFiles(['FluxSvc/*.h']))