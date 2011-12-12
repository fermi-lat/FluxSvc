# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/FluxSvc/SConscript,v 1.16 2011/05/20 15:31:03 heather Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-56-00
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




