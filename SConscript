# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/FluxSvc/SConscript,v 1.11 2009/11/10 23:35:11 jrb Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-55-06
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




