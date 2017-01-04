$ git clone git://github.com/arkku/ihex

$ curl https://s3.amazonaws.com/mozilla-games/emscripten/releases/emsdk-portable.tar.gz -o emsdk-portable.tar.gz
$ gunzip emsdk-portable.tar.gz
$ tar -xf emsdk-portable.tar
$ cd emsdk_portable
$ ./emsdk update
$ ./emsdk install clang-incoming-64bit emscripten-incoming-64bit sdk-incoming-64bit
$ ./emsdk activate clang-incoming-64bit emscripten-incoming-64bit sdk-incoming-64bit
$ source ./emsdk_env.sh
$ cd ..

$ emcc ihex/kk_ihex_write.c convert.c -s WASM=1 -o ihex.html  -s EXPORTED_FUNCTIONS="['_convert_ihex']"
