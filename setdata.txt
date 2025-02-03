cd /d "%~dp0"
setlocal enabledelayedexpansion
for /L %%i in (1,1,2000) do (
    auto_8ch.exe
    echo !ERRORLEVEL! >> data.txt
    C:\Windows\System32\timeout /t 1 /nobreak >nul
)
endlocal
pause
