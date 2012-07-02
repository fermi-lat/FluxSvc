# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/SConscript,v 1.20 2012/02/16 03:03:47 heather Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-58-00
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




