:: Run python scons, if possible

@setlocal

@if not defined SconsPath @set SconsPath=site_scons\local
@if not exist "%SconsPath%\scons.py" @(
    echo.Cannot find scons.py in `%SconsPath%'
    echo.You can get it from:
    echo.    http://www.scons.org/download.php
    echo.or set the correct path in %%SconsPath%%
    goto quit
)

@if not defined PythonPath @(
    for %%I in ("python.exe") do @set PythonPath=%%~dp$PATH:I
)
@if not defined PythonPath @(
    for /f "delims=" %%I in ('dir /b %SYSTEMDRIVE%\python*') do @(
        for %%J in ("%SYSTEMDRIVE%\%%~I") do @set PythonPath=%%~sfJ
    )
)

@if not exist "%PythonPath%\python.exe" @(
    echo.Cannot find python.exe in `%PythonPath%`, try running:
    echo.    python site_scons\local\scons.py %*
    echo.or set the correct path in %%PythonPath%%
    goto quit
)

"%PythonPath%\python.exe" "%SconsPath%\scons.py" %*

:quit
@endlocal

:End
