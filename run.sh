export GCC_BINARY_DIR=$1

if [ -z "$GCC_BINARY_DIR" ]; then
	export FLAGS=
else
	export FLAGS="-DCMAKE_C_COMPILER=${GCC_BINARY_DIR}/gcc -DCMAKE_CXX_COMPILER=${GCC_BINARY_DIR}/g++"
fi

rm -rf pybind11
git clone git@github.com:pybind/pybind11.git

rm -rf build 
mkdir build
cd build  

cmake $FLAGS ..
make 
./example
