# scons script for cm2

import os

env = Environment(ENV = os.environ)
BUILD_CLEAN = env.GetOption('clean')

if not BUILD_CLEAN:
  conf_tests = {}
  conf = Configure(env, custom_tests = conf_tests)

  if not conf.CheckCC() :
    print('!! Your compiler and/or environment is not correctly configured.')
    Exit(1)

  env = conf.Finish()
# end ( not BUILD_CLEAN )

global_env = env
Export( 'global_env' )

# Run scripts

