# scons script for cm2

import os

# Defining unit test runner from http://www.scons.org/wiki/UnitTests
def builder_unit_test( target, source, env ):
    app = str( source[0].abspath )
    if os.spawnl( os.P_WAIT, app, app ) == 0:
        open( str( target[0] ), 'w' ).write( "PASSED\n" )
    else:
        return 1

opt = Variables();
opt.AddVariables(
    BoolVariable('DEBUG', 'Compile a debug version', 'False'),
    BoolVariable('TEST', 'Compile and run the unit-tests', 'True'),
    )

HAS_DOXYGEN = False
whichPath = 'python %s' % os.path.normpath("tools/which.py")

env = Environment(ENV = os.environ)
BUILD_CLEAN = env.GetOption('clean')
opt.Update(env)

if not BUILD_CLEAN:
    def CheckProgram(context, name):
        context.Message( 'Checking for %s...' % name )
        # TODO append the OS executable path (ie. add ".(exe|bat)" for windows)
        ret = context.TryAction( '%s %s' % (whichPath, name) )[0]
        context.Result( ret )
        return ret;

    conf_tests = { 'CheckProgram' : CheckProgram }
    conf = Configure(env, custom_tests = conf_tests)

    if not conf.CheckCC() :
        print('!! Your compiler and/or environment is not correctly configured.')
        Exit(1)

    if not conf.CheckCXX() :
        print('!! Your compiler and/or environment is not correctly configured.')
        Exit(1)

    if not conf.CheckFunc('printf') :
        print('!! Your compiler and/or environment is not correctly configured.')
        Exit(1)

    if not conf.CheckHeader('math.h'):
        print "!! You need 'math.h' to compile this library"
        Exit(1)

    if not conf.CheckHeader('stdint.h'):
        if env['CC'] == "cl":
            print "Using local header 'include/cm2/stdint.h'"
            env.AppendUnique( CPPDEFINES = [ 'USE_MSVC_STDINT' ] )
        else:
            print "!! You need 'stdint.h' to compile this library"
            Exit(1)

    HAS_DOXYGEN = conf.CheckProgram( 'doxygen' )

    env = conf.Finish()

    env.AppendUnique( CPPDEFINES = [ env['PLATFORM'].upper() ] )
    env.AppendUnique( LIBPATH = [ '#lib' ] )

# end ( not BUILD_CLEAN )

global_env = env
Export( 'global_env' )

SConscript( 'src/SConscript' )

if env['TEST'] :
    SConscript( [ 'googletest.SConscript' ] )
