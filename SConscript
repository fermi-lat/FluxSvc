# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/SConscript,v 1.17 2011/12/12 20:48:50 heather Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-56-01
Import('baseEnv')
Import('listFiles')
Import('packages')
#progEnv = baseEnv.Clone()   no programs here for now.  See subpkg test_FluxSvc
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='FluxSvc', toBuild='component')

FluxSvc = libEnv.ComponentLibrary('FluxSvc',
                                  listFiles(['src/*.cxx']) )

libEnv.Tool('registerTargets', package = 'FluxSvc',
            libraryCxts = [[FluxSvc, libEnv]],
            includes = listFiles(['FluxSvc/*.h']),
            data = listFiles(['data/*'], recursive = True),
            jo=['src/defaultOptions.txt'])
# omitted jo in test_FluxSvc subpkg for now




