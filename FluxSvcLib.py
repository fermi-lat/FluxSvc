# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/FluxSvc/FluxSvcLib.py,v 1.2 2008/10/31 15:58:41 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['FluxSvc'])
    env.Tool('celestialSourcesLib')
    env.Tool('f2cLib')
    env.Tool('tipLib')
    env.Tool('fluxLib')
    env.Tool('TriggerLib')
    env.Tool('addLibrary', library = env['clhepLibs'])
def exists(env):
    return 1;
