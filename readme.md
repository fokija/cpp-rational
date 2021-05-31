Go to build dir and execute:
`conan install .. --build missing -s compiler=gcc -s compiler.libcxx=libstdc++11`

Then:
`cmake ..`

Then:
`make`