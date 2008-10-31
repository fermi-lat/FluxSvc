# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/FluxSvc/FluxSvcLib.py,v 1.1 2008/08/15 21:42:34 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['FluxSvc'])
    env.Tool('celestialSourcesLib')
def exists(env):
    return 1;
