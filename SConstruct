# scons script for cm2

import os

AddOption("--test",
          action="store_true", dest="run_tests", default=True,
          help="Compile and run unit tests [default]")
AddOption("--no-test",
          action="store_false", dest="run_tests",
          help="Don't compile and run unit tests")
AddOption("--debug-build",
          action="store_true", dest="debug",
          help="Compile with debug information and warnings")
AddOption("--release",
          action="store_false", dest="debug", default=False,
          help="Compile without debug information and warnings [default]")
AddOption("--doxygen",
          action="store_true", dest="run_doxygen", default=True,
          help="Generate the reference documents [defualt]")
AddOption("--no-doxygen",
          action="store_false", dest="run_doxygen",
          help="Don't generate the reference documents")
AddOption("--configure",
          action="store_true", dest="run_config", default=False,
          help="Run the build configuration process and quit")

env = Environment(ENV = os.environ)

var= Variables();
var.AddVariables(
    BoolVariable('HAS_DOXYGEN', '', False),
    ('WHICH_PATH', '', 'python %s' % os.path.normpath("tools/which.py")),
    )
var.Update(env)

if not GetOption('clean') and not GetOption('help'):
    def CheckProgram(context, name):
        context.Message( 'Checking for %s...' % name )
        # TODO append the OS executable path (ie. add ".(exe|bat)" for windows)
        ret = context.TryAction( '%s %s' % (env['WHICH_PATH'], name) )[0]
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
            print "\tUsing local header 'include/cm2/stdint.h'"
            env.AppendUnique( CPPDEFINES = [ 'USE_MSVC_STDINT' ] )
        else:
            print "!! You need 'stdint.h' to compile this library"
            Exit(1)

    if not conf.CheckHeader('float.h'):
        print "!! You need 'float.h' to compile this library"
        Exit(1)

    if GetOption('run_doxygen'):
        if conf.CheckProgram( 'doxygen' ):
            env['HAS_DOXYGEN'] = True
        else:
            print "\tCannot find doxygen on your system, make sure it is in your PATH"

    env = conf.Finish()

    env.AppendUnique( CPPDEFINES = [ env['PLATFORM'].upper() ] )
    env.AppendUnique( LIBPATH = [ '#lib' ] )

# end ( not GetOption('clean') and not GetOption('help') )

global_env = env
Export( 'global_env' )

SConscript( 'src/SConscript' )

if GetOption('run_tests') or GetOption('clean'):
    SConscript( [ 'googletest.SConscript', 'tests/SConscript' ] )

if env['HAS_DOXYGEN'] :
    doxygen_sources = Glob( 'include/cm2/*.hpp')
    doxygen_sources.extend( Glob( 'Doxyfile' ) )
    env.Command( 'docs/html/index.html', doxygen_sources, "doxygen" )

