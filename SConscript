# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/FluxSvc/SConscript,v 1.13 2009/12/17 19:40:14 jrb Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-55-07
Import('baseEnv')
Import('listFiles')
Import('packages')
#progEnv = baseEnv.Clone()   no programs here for now.  See subpkg test_FluxSvc
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='FluxSvc', toBuild='component')

FluxSvc = libEnv.SharedLibrary('FluxSvc',
                               listFiles(['src/*.cxx', 'src/Dll/*.cxx']) )

libEnv.Tool('registerTargets', package = 'FluxSvc',
            libraryCxts = [[FluxSvc, libEnv]],
            includes = listFiles(['FluxSvc/*.h']),
            data = listFiles(['data/*'], recursive = True),
            jo=['src/defaultOptions.txt'])
# omitted jo in test_FluxSvc subpkg for now




