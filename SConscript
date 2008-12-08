# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/FluxSvc/SConscript,v 1.3 2008/11/02 01:30:10 glastrm Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: FluxSvc-06-53-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()
tempEnv = baseEnv.Clone()
tempEnv1 = baseEnv.Clone()
libEnv.Tool('FluxSvcLib', depsOnly = 1)
ctype_fix=tempEnv1.SharedObject(source = ['src/flux_c_type_fix.cxx'])
#tempEnv.AppendUnique(LINKFLAGS = ['-Wl,--wrap,__ctype_b'])
libEnv.AppendUnique(SHLINKFLAGS = ['-Wl,--wrap,__ctype_b'])
#libEnv.AppendUnique(FORTRANFLAGS = ['-Wno-globals'])
#libEnv.AppendUnique(CPPDEFINES= ['f2cFortran'])
#libEnv.Tool('tipLib')
#libEnv.Tool('f2cLib')

# The oldnames library below comes from the macro f2c_linkopts coming from f2c/cmt/requirements.  
# I added it to this file because of the -import=f2c in the requirements file for this SConscript.
ExposureAlg = tempEnv.SharedObject(['src/ExposureAlg.cxx'])
FluxAlg_os = tempEnv.SharedObject(['src/FluxAlg.cxx'])
FluxSvc_os = tempEnv.SharedObject(['src/FluxSvc.cxx'])
FluxSvcRandom_os = tempEnv.SharedObject(['src/FluxSvcRandom.cxx'])
OrbitSvc_os = tempEnv.SharedObject(['src/OrbitSvc.cxx'])
PointInfoAlg_os = tempEnv.SharedObject(['src/PointInfoAlg.cxx'])
PointInfo_os = tempEnv.SharedObject(['src/PointingInfo.cxx'])
FluxSvc_dll_os = tempEnv.SharedObject(['src/Dll/FluxSvc_dll.cxx'])
FluxSvc_load_os = tempEnv.SharedObject(['src/Dll/FluxSvc_load.cxx'])

FluxSvc = libEnv.SharedLibrary('FluxSvc', [ExposureAlg,FluxAlg_os,FluxSvc_os,FluxSvcRandom_os,
				OrbitSvc_os,PointInfoAlg_os,PointInfo_os,FluxSvc_dll_os,FluxSvc_load_os] + [ctype_fix])

progEnv.Tool('registerObjects', package = 'FluxSvc', libraries = [FluxSvc],
             includes = listFiles(['FluxSvc/*.h']),
             data = listFiles(['data/*'], recursive = True))



