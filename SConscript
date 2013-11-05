# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/SConscript,v 1.23 2012/08/18 00:08:44 jrb Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-59-01
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




