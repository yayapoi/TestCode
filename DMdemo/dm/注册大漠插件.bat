@echo off
echo %cd%
echo %~dp0
Regsvr32 %~dp0\dm.dll