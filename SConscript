# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/FluxSvc/SConscript,v 1.10 2009/09/15 15:03:08 heather Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-55-05
Import('baseEnv')
Import('listFiles')
Import('packages')
#progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('FluxSvcLib', depsOnly = 1)

FluxSvc = libEnv.SharedLibrary('FluxSvc', listFiles(['src/*.cxx']))

libEnv.Tool('registerTargets', package = 'FluxSvc',
            libraryCxts = [[FluxSvc, libEnv]],
             includes = listFiles(['FluxSvc/*.h']),
             data = listFiles(['data/*'], recursive = True))




