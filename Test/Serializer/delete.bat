for /r %%i in (Debug, release, x64,.vs) do rd /s /q "%%i"
del / s / q / f / a .DS_STORE