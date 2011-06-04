:: Run python scons, if possible

@set sconsPath=site_scons\local\scons.py
@if not exist %sconsPath% @goto error_no_scons_local

@set tempfile=.pythondir.tmp
@dir /b \python* > %tempfile%

@set /p pythonDir=<%tempfile%
@set pythonPath=%SYSTEMDRIVE%\%pythonDir%\python.exe

@if not exist %pythonPath% @goto error_no_python

%pythonPath% %sconsPath% %*

:: skip the errors...
@goto quit

:error_no_scons_local
@echo Cannot find site_scons\local\scons.py
@echo You can get it from:
@echo     http://www.scons.org/download.php
@goto quit

:error_no_python
@echo Cannot find python directory, try running:
@echo     python site_scons\local\scons.py %*

:quit
