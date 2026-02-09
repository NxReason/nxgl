if (!(Test-Path build)) { mkdir build }
cd build

cmake -G "MinGW Makefiles" ..
mingw32-make

if ($? ) {
  Write-Host "--- Launching App ---" -ForegroundColor Green
  ./vsgl
} else {
  Write-Host "--- Build Failed ---" -ForegoundColor Red
}

cd ..