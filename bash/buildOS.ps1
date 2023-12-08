Set-Location C:\Users\ioanu\OneDrive\Documents\Programs\OS
docker build buildenv -t os-buildenv
docker run --rm -it -v "${pwd}:/root/env" myos-buildenv
