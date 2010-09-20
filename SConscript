# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/SConscript,v 1.13 2009/12/17 19:40:14 jrb Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-55-07-gr01
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




