@echo off
mkdir output
for /f %%i IN (poolids.txt) do wget -nv -O output/%%i.pdf "http://fapt.efanniemae.com/MFSecuritiesLocator/plp/doc/showDoc.do?type=SAMF&poolid=%%i"
