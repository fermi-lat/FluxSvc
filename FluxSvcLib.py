# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/FluxSvc/FluxSvcLib.py,v 1.6 2009/11/10 23:35:11 jrb Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['FluxSvc'])
        if env['PLATFORM']=='win32' and env.get('CONTAINERNAME','')=='GlastRelease':
	    env.Tool('findPkgPath', package = 'FluxSvc') 
    env.Tool('TriggerLib')
    env.Tool('ntupleWriterSvcLib')
    env.Tool('EventLib')
    env.Tool('GlastSvcLib')
    env.Tool('celestialSourcesLib')
    env.Tool('fluxLib')
    env.Tool('astroLib')
    env.Tool('tipLib')
    env.Tool('facilitiesLib')
    env.Tool('addLibrary', library = env['clhepLibs'])
    env.Tool('addLibrary', library = env['gaudiLibs'])
def exists(env):
    return 1;
