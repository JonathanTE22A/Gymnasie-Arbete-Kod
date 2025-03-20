@echo off
setlocal EnableDelayedExpansion

set script_path=python matrixnonumpy.py
set output_file=output_log.txt
set num_runs=10

rem Clear the output file
echo. > %output_file%

for /L %%i in (1,1,%num_runs%) do (
    echo Running iteration %%i >> %output_file%
    call %script_path% >> %output_file% 2>&1
    if ERRORLEVEL 1 (
        echo Error occurred in iteration %%i >> %output_file%
    )
    echo. >> %output_file%
)

endlocal
