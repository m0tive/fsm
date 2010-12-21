# scons script for cm2

import os

opt = Variables();
opt.AddVariables(
    BoolVariable('DEBUG', 'Compile a debug version', 'True'),
    )

HAS_DOXYGEN = False
whichPath = 'python %s' % os.path.normpath("tools/which.py")

AddOption("--test",
          action="store_true", dest="run_tests", default=True,
          help="Compile and run unit tests [default]")
AddOption("--no-test",
          action="store_false", dest="run_tests",
          help="Don't compile and run unit tests")
AddOption("--build-debug",
          action="store_true", dest="debug",
          help="Compile with debug information and warnings")
AddOption("--no-debug",
          action="store_false", dest="debug", default=False,
          help="Compile without debug information and warnings [default]")

env = Environment(ENV = os.environ)
opt.Update(env)

if not GetOption('clean') and not GetOption('help'):
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

    if not conf.CheckHeader('float.h'):
        print "!! You need 'float.h' to compile this library"
        Exit(1)

    HAS_DOXYGEN = conf.CheckProgram( 'doxygen' )

    env = conf.Finish()

    env.AppendUnique( CPPDEFINES = [ env['PLATFORM'].upper() ] )
    env.AppendUnique( LIBPATH = [ '#lib' ] )

# end ( not BUILD_CLEAN )

global_env = env
Export( 'global_env' )

SConscript( 'src/SConscript' )

if GetOption('run_tests') :
    SConscript( [ 'googletest.SConscript', 'tests/SConscript' ] )

if HAS_DOXYGEN :
    doxygen_sources = Glob( 'include/cm2/*.hpp')
    doxygen_sources.extend( Glob( 'Doxyfile' ) )
    env.Command( 'docs/html/index.html', doxygen_sources, "doxygen" )

