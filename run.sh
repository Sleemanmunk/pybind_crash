rm -rf pybind11
git clone git@github.com:pybind/pybind11.git

rm -rf build 
mkdir build
cd build  

cmake -DCMAKE_C_COMPILER=/usr/local/bin/gcc -DCMAKE_CXX_COMPILER=/usr/local/bin/g++  ..
make 
./example
