# pybind_crash
A project to reproduce pybind's crash

## Prerequisites:
Python 3.x with Pytorch 1.7+
GCC 7.4.0 or 7.5.0 (4.8.5 does not present this bug, other versions are untested)

To reproduce:
  inside pybind_crash folder
  `bash run.sh`
  
  you can provide the directory of your preferred GCC's binaries as argument #1 to run.sh
  `bash run.sh /usr/local/bin/`

## Expected output (GCC 4.8.5):
```
(base) [root@1cf9dda33f79 pybind_crash]# bash run.sh
Cloning into 'pybind11'...
remote: Enumerating objects: 23430, done.
remote: Counting objects: 100% (1305/1305), done.
remote: Compressing objects: 100% (520/520), done.
remote: Total 23430 (delta 814), reused 1055 (delta 714), pack-reused 22125
Receiving objects: 100% (23430/23430), 8.57 MiB | 9.30 MiB/s, done.
Resolving deltas: 100% (16238/16238), done.
Updating files: 100% (236/236), done.
-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- pybind11 v2.10.0 dev1
-- Found PythonInterp: /deployment/envs/bert_sentiment/bin/python (found suitable version "3.9.7", minimum required is "3.6")
-- Found PythonLibs: /deployment/envs/bert_sentiment/lib/libpython3.9.so
-- Performing Test HAS_FLTO
-- Performing Test HAS_FLTO - Success
-- Configuring done
-- Generating done
-- Build files have been written to: /deployment/pybind_crash/build
make: Warning: File `Makefile' has modification time 0.5 s in the future
make[1]: Warning: File `CMakeFiles/Makefile2' has modification time 0.55 s in the future
make[2]: Warning: File `CMakeFiles/example.dir/flags.make' has modification time 0.4 s in the future
Scanning dependencies of target example
make[2]: warning:  Clock skew detected.  Your build may be incomplete.
make[2]: Warning: File `CMakeFiles/example.dir/depend.make' has modification time 0.54 s in the future
[ 50%] Building CXX object CMakeFiles/example.dir/main.cpp.o
[100%] Linking CXX executable example
make[2]: warning:  Clock skew detected.  Your build may be incomplete.
[100%] Built target example
make[1]: warning:  Clock skew detected.  Your build may be incomplete.
make: warning:  Clock skew detected.  Your build may be incomplete.
Pybind Version: v2.9.1
Python Version: 3.9.7
Torch Version: 1.10.2
```

## Observed output (GCC 7.5.0)
```
(base) [root@1cf9dda33f79 pybind_crash]# bash run.sh /usr/local/bin/
Cloning into 'pybind11'...
remote: Enumerating objects: 23430, done.
remote: Counting objects: 100% (1305/1305), done.
remote: Compressing objects: 100% (520/520), done.
remote: Total 23430 (delta 814), reused 1055 (delta 714), pack-reused 22125
Receiving objects: 100% (23430/23430), 8.57 MiB | 7.05 MiB/s, done.
Resolving deltas: 100% (16238/16238), done.
Updating files: 100% (236/236), done.
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/local/bin//gcc
-- Check for working C compiler: /usr/local/bin//gcc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/local/bin//g++
-- Check for working CXX compiler: /usr/local/bin//g++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- pybind11 v2.10.0 dev1
-- Found PythonInterp: /deployment/envs/bert_sentiment/bin/python (found suitable version "3.9.7", minimum required is "3.6")
-- Found PythonLibs: /deployment/envs/bert_sentiment/lib/libpython3.9.so
-- Performing Test HAS_FLTO
-- Performing Test HAS_FLTO - Success
-- Configuring done
-- Generating done
-- Build files have been written to: /deployment/pybind_crash/build
make: Warning: File `Makefile' has modification time 0.49 s in the future
make[1]: Warning: File `CMakeFiles/Makefile2' has modification time 0.53 s in the future
make[2]: Warning: File `CMakeFiles/example.dir/flags.make' has modification time 0.4 s in the future
Scanning dependencies of target example
make[2]: warning:  Clock skew detected.  Your build may be incomplete.
make[2]: Warning: File `CMakeFiles/example.dir/depend.make' has modification time 0.53 s in the future
[ 50%] Building CXX object CMakeFiles/example.dir/main.cpp.o
[100%] Linking CXX executable example
make[2]: warning:  Clock skew detected.  Your build may be incomplete.
[100%] Built target example
make[1]: warning:  Clock skew detected.  Your build may be incomplete.
make: warning:  Clock skew detected.  Your build may be incomplete.
Pybind Version: v2.9.1
Python Version: 3.9.7
Torch Version: 1.10.2
*** Error in `./example': free(): invalid pointer: 0x00000000039d2e08 ***
======= Backtrace: =========
/lib64/libc.so.6(+0x81329)[0x7ff778fe0329]
./example[0x423d6c]
./example[0x41ff5f]
./example[0x41b26d]
./example[0x416ce6]
./example[0x413392]
./example[0x40913f]
./example[0x412b3e]
./example[0x412c1e]
./example[0x405d7d]
/lib64/libc.so.6(__libc_start_main+0xf5)[0x7ff778f81555]
./example[0x405a89]
======= Memory map: ========
00400000-00442000 r-xp 00000000 00:35 5910974512280736                   /deployment/pybind_crash/build/example
00641000-00642000 r--p 00041000 00:35 5910974512280736                   /deployment/pybind_crash/build/example
00642000-00643000 rw-p 00042000 00:35 5910974512280736                   /deployment/pybind_crash/build/example
00643000-00644000 rw-p 00000000 00:00 0
00b9d000-04388000 rw-p 00000000 00:00 0                                  [heap]
7ff6e0000000-7ff6e0021000 rw-p 00000000 00:00 0
7ff6e0021000-7ff6e4000000 ---p 00000000 00:00 0
7ff6e5804000-7ff6e5984000 rw-p 00000000 00:00 0
7ff6e5984000-7ff6e598a000 r--p 00000000 00:35 562949953865638            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/json.cpython-39-x86_64-linux-gnu.so
7ff6e598a000-7ff6e5995000 r-xp 00006000 00:35 562949953865638            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/json.cpython-39-x86_64-linux-gnu.so
7ff6e5995000-7ff6e5999000 r--p 00011000 00:35 562949953865638            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/json.cpython-39-x86_64-linux-gnu.so
7ff6e5999000-7ff6e599a000 ---p 00015000 00:35 562949953865638            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/json.cpython-39-x86_64-linux-gnu.so
7ff6e599a000-7ff6e599b000 r--p 00015000 00:35 562949953865638            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/json.cpython-39-x86_64-linux-gnu.so
7ff6e599b000-7ff6e599c000 rw-p 00016000 00:35 562949953865638            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/json.cpython-39-x86_64-linux-gnu.so
7ff6e59dc000-7ff6e59e8000 r--p 00000000 00:35 562949953865655            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/parsers.cpython-39-x86_64-linux-gnu.so
7ff6e59e8000-7ff6e5a3e000 r-xp 0000c000 00:35 562949953865655            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/parsers.cpython-39-x86_64-linux-gnu.so
7ff6e5a3e000-7ff6e5a4a000 r--p 00062000 00:35 562949953865655            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/parsers.cpython-39-x86_64-linux-gnu.so
7ff6e5a4a000-7ff6e5a4b000 ---p 0006e000 00:35 562949953865655            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/parsers.cpython-39-x86_64-linux-gnu.so
7ff6e5a4b000-7ff6e5a4c000 r--p 0006e000 00:35 562949953865655            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/parsers.cpython-39-x86_64-linux-gnu.so
7ff6e5a4c000-7ff6e5a52000 rw-p 0006f000 00:35 562949953865655            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/parsers.cpython-39-x86_64-linux-gnu.so
7ff6e5a52000-7ff6e5a94000 rw-p 00000000 00:00 0
7ff6e5a94000-7ff6e5a98000 r--p 00000000 00:35 562949953865693            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/testing.cpython-39-x86_64-linux-gnu.so
7ff6e5a98000-7ff6e5aa6000 r-xp 00004000 00:35 562949953865693            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/testing.cpython-39-x86_64-linux-gnu.so
7ff6e5aa6000-7ff6e5aa8000 r--p 00012000 00:35 562949953865693            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/testing.cpython-39-x86_64-linux-gnu.so
7ff6e5aa8000-7ff6e5aa9000 r--p 00013000 00:35 562949953865693            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/testing.cpython-39-x86_64-linux-gnu.so
7ff6e5aa9000-7ff6e5aaa000 rw-p 00014000 00:35 562949953865693            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/testing.cpython-39-x86_64-linux-gnu.so
7ff6e5aaa000-7ff6e5aeb000 rw-p 00000000 00:00 0
7ff6e5b2b000-7ff6e5b6b000 rw-p 00000000 00:00 0
7ff6e5b6b000-7ff6e5b7a000 r--p 00000000 00:35 562949953865611            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/groupby.cpython-39-x86_64-linux-gnu.so
7ff6e5b7a000-7ff6e5c7f000 r-xp 0000f000 00:35 562949953865611            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/groupby.cpython-39-x86_64-linux-gnu.so
7ff6e5c7f000-7ff6e5c96000 r--p 00114000 00:35 562949953865611            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/groupby.cpython-39-x86_64-linux-gnu.so
7ff6e5c96000-7ff6e5c97000 ---p 0012b000 00:35 562949953865611            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/groupby.cpython-39-x86_64-linux-gnu.so
7ff6e5c97000-7ff6e5c98000 r--p 0012b000 00:35 562949953865611            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/groupby.cpython-39-x86_64-linux-gnu.so
7ff6e5c98000-7ff6e5ca3000 rw-p 0012c000 00:35 562949953865611            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/groupby.cpython-39-x86_64-linux-gnu.so
7ff6e5ca3000-7ff6e5d66000 rw-p 00000000 00:00 0
7ff6e5d66000-7ff6e5d6e000 r--p 00000000 00:35 562949953865663            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reshape.cpython-39-x86_64-linux-gnu.so
7ff6e5d6e000-7ff6e5d98000 r-xp 00008000 00:35 562949953865663            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reshape.cpython-39-x86_64-linux-gnu.so
7ff6e5d98000-7ff6e5da0000 r--p 00032000 00:35 562949953865663            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reshape.cpython-39-x86_64-linux-gnu.so
7ff6e5da0000-7ff6e5da1000 ---p 0003a000 00:35 562949953865663            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reshape.cpython-39-x86_64-linux-gnu.so
7ff6e5da1000-7ff6e5da2000 r--p 0003a000 00:35 562949953865663            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reshape.cpython-39-x86_64-linux-gnu.so
7ff6e5da2000-7ff6e5da6000 rw-p 0003b000 00:35 562949953865663            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reshape.cpython-39-x86_64-linux-gnu.so
7ff6e5da6000-7ff6e5e27000 rw-p 00000000 00:00 0
7ff6e5e27000-7ff6e5e2d000 r--p 00000000 00:35 562949953865771            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/indexers.cpython-39-x86_64-linux-gnu.so
7ff6e5e2d000-7ff6e5e45000 r-xp 00006000 00:35 562949953865771            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/indexers.cpython-39-x86_64-linux-gnu.so
7ff6e5e45000-7ff6e5e4b000 r--p 0001e000 00:35 562949953865771            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/indexers.cpython-39-x86_64-linux-gnu.so
7ff6e5e4b000-7ff6e5e4c000 r--p 00023000 00:35 562949953865771            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/indexers.cpython-39-x86_64-linux-gnu.so
7ff6e5e4c000-7ff6e5e4f000 rw-p 00024000 00:35 562949953865771            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/indexers.cpython-39-x86_64-linux-gnu.so
7ff6e5e4f000-7ff6e5e59000 r--p 00000000 00:35 562949953865768            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/aggregations.cpython-39-x86_64-linux-gnu.so
7ff6e5e59000-7ff6e5e97000 r-xp 0000a000 00:35 562949953865768            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/aggregations.cpython-39-x86_64-linux-gnu.so
7ff6e5e97000-7ff6e5ea0000 r--p 00048000 00:35 562949953865768            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/aggregations.cpython-39-x86_64-linux-gnu.so
7ff6e5ea0000-7ff6e5ea1000 ---p 00051000 00:35 562949953865768            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/aggregations.cpython-39-x86_64-linux-gnu.so
7ff6e5ea1000-7ff6e5ea2000 r--p 00051000 00:35 562949953865768            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/aggregations.cpython-39-x86_64-linux-gnu.so
7ff6e5ea2000-7ff6e5ea7000 rw-p 00052000 00:35 562949953865768            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/window/aggregations.cpython-39-x86_64-linux-gnu.so
7ff6e5ea7000-7ff6e5ee8000 rw-p 00000000 00:00 0
7ff6e5ee8000-7ff6e5eea000 r--p 00000000 00:35 562949953851349            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/mmap.cpython-39-x86_64-linux-gnu.so
7ff6e5eea000-7ff6e5eed000 r-xp 00002000 00:35 562949953851349            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/mmap.cpython-39-x86_64-linux-gnu.so
7ff6e5eed000-7ff6e5eef000 r--p 00005000 00:35 562949953851349            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/mmap.cpython-39-x86_64-linux-gnu.so
7ff6e5eef000-7ff6e5ef0000 r--p 00006000 00:35 562949953851349            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/mmap.cpython-39-x86_64-linux-gnu.so
7ff6e5ef0000-7ff6e5ef1000 rw-p 00007000 00:35 562949953851349            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/mmap.cpython-39-x86_64-linux-gnu.so
7ff6e5ef1000-7ff6e5f71000 rw-p 00000000 00:00 0
7ff6e5f71000-7ff6e5f78000 r--p 00000000 00:35 562949953865774            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/writers.cpython-39-x86_64-linux-gnu.so
7ff6e5f78000-7ff6e5f96000 r-xp 00007000 00:35 562949953865774            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/writers.cpython-39-x86_64-linux-gnu.so
7ff6e5f96000-7ff6e5f9d000 r--p 00025000 00:35 562949953865774            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/writers.cpython-39-x86_64-linux-gnu.so
7ff6e5f9d000-7ff6e5f9e000 ---p 0002c000 00:35 562949953865774            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/writers.cpython-39-x86_64-linux-gnu.so
7ff6e5f9e000-7ff6e5f9f000 r--p 0002c000 00:35 562949953865774            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/writers.cpython-39-x86_64-linux-gnu.so
7ff6e5f9f000-7ff6e5fa3000 rw-p 0002d000 00:35 562949953865774            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/writers.cpython-39-x86_64-linux-gnu.so
7ff6e5fa3000-7ff6e5fac000 r--p 00000000 00:35 562949953865629            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/internals.cpython-39-x86_64-linux-gnu.so
7ff6e5fac000-7ff6e5fdf000 r-xp 00009000 00:35 562949953865629            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/internals.cpython-39-x86_64-linux-gnu.so
7ff6e5fdf000-7ff6e5fe9000 r--p 0003c000 00:35 562949953865629            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/internals.cpython-39-x86_64-linux-gnu.so
7ff6e5fe9000-7ff6e5fea000 r--p 00045000 00:35 562949953865629            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/internals.cpython-39-x86_64-linux-gnu.so
7ff6e5fea000-7ff6e5fef000 rw-p 00046000 00:35 562949953865629            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/internals.cpython-39-x86_64-linux-gnu.so
7ff6e5fef000-7ff6e60b1000 rw-p 00000000 00:00 0
7ff6e60b1000-7ff6e60b4000 r--p 00000000 00:35 562949953865627            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/indexing.cpython-39-x86_64-linux-gnu.so
7ff6e60b4000-7ff6e60b9000 r-xp 00003000 00:35 562949953865627            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/indexing.cpython-39-x86_64-linux-gnu.so
7ff6e60b9000-7ff6e60bb000 r--p 00008000 00:35 562949953865627            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/indexing.cpython-39-x86_64-linux-gnu.so
7ff6e60bb000-7ff6e60bc000 r--p 00009000 00:35 562949953865627            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/indexing.cpython-39-x86_64-linux-gnu.so
7ff6e60bc000-7ff6e60bd000 rw-p 0000a000 00:35 562949953865627            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/indexing.cpython-39-x86_64-linux-gnu.so
7ff6e60bd000-7ff6e617d000 rw-p 00000000 00:00 0
7ff6e617d000-7ff6e6180000 r--p 00000000 00:35 562949953865661            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reduction.cpython-39-x86_64-linux-gnu.so
7ff6e6180000-7ff6e6183000 r-xp 00003000 00:35 562949953865661            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reduction.cpython-39-x86_64-linux-gnu.so
7ff6e6183000-7ff6e6184000 r--p 00006000 00:35 562949953865661            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reduction.cpython-39-x86_64-linux-gnu.so
7ff6e6184000-7ff6e6185000 ---p 00007000 00:35 562949953865661            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reduction.cpython-39-x86_64-linux-gnu.so
7ff6e6185000-7ff6e6186000 r--p 00007000 00:35 562949953865661            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reduction.cpython-39-x86_64-linux-gnu.so
7ff6e6186000-7ff6e6187000 rw-p 00008000 00:35 562949953865661            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/reduction.cpython-39-x86_64-linux-gnu.so
7ff6e6187000-7ff6e6207000 rw-p 00000000 00:00 0
7ff6e6207000-7ff6e6210000 r--p 00000000 00:35 562949953865666            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/sparse.cpython-39-x86_64-linux-gnu.so
7ff6e6210000-7ff6e62c1000 r-xp 00009000 00:35 562949953865666            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/sparse.cpython-39-x86_64-linux-gnu.so
7ff6e62c1000-7ff6e62cd000 r--p 000ba000 00:35 562949953865666            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/sparse.cpython-39-x86_64-linux-gnu.so
7ff6e62cd000-7ff6e62ce000 ---p 000c6000 00:35 562949953865666            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/sparse.cpython-39-x86_64-linux-gnu.so
7ff6e62ce000-7ff6e62cf000 r--p 000c6000 00:35 562949953865666            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/sparse.cpython-39-x86_64-linux-gnu.so
7ff6e62cf000-7ff6e62d4000 rw-p 000c7000 00:35 562949953865666            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/sparse.cpython-39-x86_64-linux-gnu.so
7ff6e62d4000-7ff6e6316000 rw-p 00000000 00:00 0
7ff6e6316000-7ff6e6325000 r--p 00000000 00:35 562949953865635            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/join.cpython-39-x86_64-linux-gnu.so
7ff6e6325000-7ff6e6599000 r-xp 0000f000 00:35 562949953865635            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/join.cpython-39-x86_64-linux-gnu.so
7ff6e6599000-7ff6e65b8000 r--p 00283000 00:35 562949953865635            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/join.cpython-39-x86_64-linux-gnu.so
7ff6e65b8000-7ff6e65b9000 ---p 002a2000 00:35 562949953865635            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/join.cpython-39-x86_64-linux-gnu.so
7ff6e65b9000-7ff6e65ba000 r--p 002a2000 00:35 562949953865635            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/join.cpython-39-x86_64-linux-gnu.so
7ff6e65ba000-7ff6e65c2000 rw-p 002a3000 00:35 562949953865635            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/join.cpython-39-x86_64-linux-gnu.so
7ff6e65c2000-7ff6e65c6000 rw-p 00000000 00:00 0
7ff6e65c6000-7ff6e65d0000 r--p 00000000 00:35 562949953865623            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/index.cpython-39-x86_64-linux-gnu.so
7ff6e65d0000-7ff6e6624000 r-xp 0000a000 00:35 562949953865623            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/index.cpython-39-x86_64-linux-gnu.so
7ff6e6624000-7ff6e6631000 r--p 0005e000 00:35 562949953865623            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/index.cpython-39-x86_64-linux-gnu.so
7ff6e6631000-7ff6e6632000 r--p 0006a000 00:35 562949953865623            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/index.cpython-39-x86_64-linux-gnu.so
7ff6e6632000-7ff6e6639000 rw-p 0006b000 00:35 562949953865623            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/index.cpython-39-x86_64-linux-gnu.so
7ff6e6639000-7ff6e673a000 rw-p 00000000 00:00 0
7ff6e673a000-7ff6e673e000 r--p 00000000 00:35 562949953865606            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/arrays.cpython-39-x86_64-linux-gnu.so
7ff6e673e000-7ff6e674d000 r-xp 00004000 00:35 562949953865606            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/arrays.cpython-39-x86_64-linux-gnu.so
7ff6e674d000-7ff6e6750000 r--p 00013000 00:35 562949953865606            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/arrays.cpython-39-x86_64-linux-gnu.so
7ff6e6750000-7ff6e6751000 ---p 00016000 00:35 562949953865606            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/arrays.cpython-39-x86_64-linux-gnu.so
7ff6e6751000-7ff6e6752000 r--p 00016000 00:35 562949953865606            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/arrays.cpython-39-x86_64-linux-gnu.so
7ff6e6752000-7ff6e6754000 rw-p 00017000 00:35 562949953865606            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/arrays.cpython-39-x86_64-linux-gnu.so
7ff6e6754000-7ff6e6794000 rw-p 00000000 00:00 0
7ff6e6794000-7ff6e6797000 r--p 00000000 00:35 562949953851302            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/_csv.cpython-39-x86_64-linux-gnu.so
7ff6e6797000-7ff6e679c000 r-xp 00003000 00:35 562949953851302            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/_csv.cpython-39-x86_64-linux-gnu.so
7ff6e679c000-7ff6e679e000 r--p 00008000 00:35 562949953851302            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/_csv.cpython-39-x86_64-linux-gnu.so
7ff6e679e000-7ff6e679f000 ---p 0000a000 00:35 562949953851302            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/_csv.cpython-39-x86_64-linux-gnu.so
7ff6e679f000-7ff6e67a0000 r--p 0000a000 00:35 562949953851302            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/_csv.cpython-39-x86_64-linux-gnu.so
7ff6e67a0000-7ff6e67a1000 rw-p 0000b000 00:35 562949953851302            /deployment/envs/bert_sentiment/lib/python3.9/lib-dynload/_csv.cpython-39-x86_64-linux-gnu.so
7ff6e67a1000-7ff6e67e1000 rw-p 00000000 00:00 0
7ff6e67e1000-7ff6e67e3000 r--p 00000000 00:35 562949953865204            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/move.cpython-39-x86_64-linux-gnu.so
7ff6e67e3000-7ff6e67f7000 r-xp 00002000 00:35 562949953865204            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/move.cpython-39-x86_64-linux-gnu.so
7ff6e67f7000-7ff6e67f9000 r--p 00016000 00:35 562949953865204            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/move.cpython-39-x86_64-linux-gnu.so
7ff6e67f9000-7ff6e67fa000 ---p 00018000 00:35 562949953865204            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/move.cpython-39-x86_64-linux-gnu.so
7ff6e67fa000-7ff6e67fb000 r--p 00018000 00:35 562949953865204            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/move.cpython-39-x86_64-linux-gnu.so
7ff6e67fb000-7ff6e67ff000 rw-p 00019000 00:35 562949953865204            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/move.cpython-39-x86_64-linux-gnu.so
7ff6e67ff000-7ff6e6801000 r--p 00000000 00:35 844424930575862            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce_axis.cpython-39-x86_64-linux-gnu.so
7ff6e6801000-7ff6e6807000 r-xp 00002000 00:35 844424930575862            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce_axis.cpython-39-x86_64-linux-gnu.so
7ff6e6807000-7ff6e6808000 r--p 00008000 00:35 844424930575862            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce_axis.cpython-39-x86_64-linux-gnu.so
7ff6e6808000-7ff6e6809000 r--p 00008000 00:35 844424930575862            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce_axis.cpython-39-x86_64-linux-gnu.so
7ff6e6809000-7ff6e680b000 rw-p 00009000 00:35 844424930575862            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce_axis.cpython-39-x86_64-linux-gnu.so
7ff6e680b000-7ff6e680c000 r--p 00000000 00:35 844424930575861            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce.cpython-39-x86_64-linux-gnu.so
7ff6e680c000-7ff6e680e000 r-xp 00001000 00:35 844424930575861            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce.cpython-39-x86_64-linux-gnu.so
7ff6e680e000-7ff6e680f000 r--p 00003000 00:35 844424930575861            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce.cpython-39-x86_64-linux-gnu.so
7ff6e680f000-7ff6e6810000 r--p 00003000 00:35 844424930575861            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce.cpython-39-x86_64-linux-gnu.so
7ff6e6810000-7ff6e6811000 rw-p 00004000 00:35 844424930575861            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/nonreduce.cpython-39-x86_64-linux-gnu.so
7ff6e6811000-7ff6e6813000 r--p 00000000 00:35 562949953865207            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/reduce.cpython-39-x86_64-linux-gnu.so
7ff6e6813000-7ff6e6826000 r-xp 00002000 00:35 562949953865207            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/reduce.cpython-39-x86_64-linux-gnu.so
7ff6e6826000-7ff6e6829000 r--p 00015000 00:35 562949953865207            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/reduce.cpython-39-x86_64-linux-gnu.so
7ff6e6829000-7ff6e682a000 r--p 00017000 00:35 562949953865207            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/reduce.cpython-39-x86_64-linux-gnu.so
7ff6e682a000-7ff6e682e000 rw-p 00018000 00:35 562949953865207            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/bottleneck/reduce.cpython-39-x86_64-linux-gnu.so
7ff6e682e000-7ff6e686e000 rw-p 00000000 00:00 0
7ff6e686e000-7ff6e686f000 ---p 00000000 00:00 0
7ff6e686f000-7ff6e706f000 rwxp 00000000 00:00 0
7ff6e706f000-7ff6e7070000 ---p 00000000 00:00 0
7ff6e7070000-7ff6e7870000 rwxp 00000000 00:00 0
7ff6e7870000-7ff6e7871000 ---p 00000000 00:00 0
7ff6e7871000-7ff6e8071000 rwxp 00000000 00:00 0
7ff6e8071000-7ff6e8072000 ---p 00000000 00:00 0
7ff6e8072000-7ff6e8872000 rwxp 00000000 00:00 0
7ff6e8872000-7ff6e8873000 ---p 00000000 00:00 0
7ff6e8873000-7ff6e9073000 rwxp 00000000 00:00 0
7ff6e9073000-7ff6e9074000 ---p 00000000 00:00 0
7ff6e9074000-7ff6e9874000 rwxp 00000000 00:00 0
7ff6e9874000-7ff6e9875000 ---p 00000000 00:00 0
7ff6e9875000-7ff6ea075000 rwxp 00000000 00:00 0
7ff6ea075000-7ff6ea076000 ---p 00000000 00:00 0
7ff6ea076000-7ff6ea876000 rwxp 00000000 00:00 0
7ff6ea876000-7ff6ea8b6000 rw-p 00000000 00:00 0
7ff6ea8b6000-7ff6ea8bc000 r--p 00000000 00:35 562949953865268            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/numexpr/interpreter.cpython-39-x86_64-linux-gnu.so
7ff6ea8bc000-7ff6ea8f3000 r-xp 00006000 00:35 562949953865268            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/numexpr/interpreter.cpython-39-x86_64-linux-gnu.so
7ff6ea8f3000-7ff6ea8f6000 r--p 0003d000 00:35 562949953865268            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/numexpr/interpreter.cpython-39-x86_64-linux-gnu.so
7ff6ea8f6000-7ff6ea8f7000 ---p 00040000 00:35 562949953865268            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/numexpr/interpreter.cpython-39-x86_64-linux-gnu.so
7ff6ea8f7000-7ff6ea8f8000 r--p 00040000 00:35 562949953865268            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/numexpr/interpreter.cpython-39-x86_64-linux-gnu.so
7ff6ea8f8000-7ff6ea8f9000 rw-p 00041000 00:35 562949953865268            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/numexpr/interpreter.cpython-39-x86_64-linux-gnu.so
7ff6ea8f9000-7ff6ea900000 r--p 00000000 00:35 562949953865649            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops.cpython-39-x86_64-linux-gnu.so
7ff6ea900000-7ff6ea923000 r-xp 00007000 00:35 562949953865649            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops.cpython-39-x86_64-linux-gnu.so
7ff6ea923000-7ff6ea92a000 r--p 0002a000 00:35 562949953865649            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops.cpython-39-x86_64-linux-gnu.so
7ff6ea92a000-7ff6ea92b000 r--p 00030000 00:35 562949953865649            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops.cpython-39-x86_64-linux-gnu.so
7ff6ea92b000-7ff6ea92e000 rw-p 00031000 00:35 562949953865649            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops.cpython-39-x86_64-linux-gnu.so
7ff6ea92e000-7ff6eaa2f000 rw-p 00000000 00:00 0
7ff6eaa2f000-7ff6eaa35000 r--p 00000000 00:35 562949953865614            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/hashing.cpython-39-x86_64-linux-gnu.so
7ff6eaa35000-7ff6eaa4e000 r-xp 00006000 00:35 562949953865614            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/hashing.cpython-39-x86_64-linux-gnu.so
7ff6eaa4e000-7ff6eaa54000 r--p 0001f000 00:35 562949953865614            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/hashing.cpython-39-x86_64-linux-gnu.so
7ff6eaa54000-7ff6eaa55000 ---p 00025000 00:35 562949953865614            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/hashing.cpython-39-x86_64-linux-gnu.so
7ff6eaa55000-7ff6eaa56000 r--p 00025000 00:35 562949953865614            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/hashing.cpython-39-x86_64-linux-gnu.so
7ff6eaa56000-7ff6eaa59000 rw-p 00026000 00:35 562949953865614            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/hashing.cpython-39-x86_64-linux-gnu.so
7ff6eaa59000-7ff6eaa5e000 r--p 00000000 00:35 562949953865696            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslib.cpython-39-x86_64-linux-gnu.so
7ff6eaa5e000-7ff6eaa7c000 r-xp 00005000 00:35 562949953865696            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslib.cpython-39-x86_64-linux-gnu.so
7ff6eaa7c000-7ff6eaa80000 r--p 00023000 00:35 562949953865696            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslib.cpython-39-x86_64-linux-gnu.so
7ff6eaa80000-7ff6eaa81000 ---p 00027000 00:35 562949953865696            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslib.cpython-39-x86_64-linux-gnu.so
7ff6eaa81000-7ff6eaa82000 r--p 00027000 00:35 562949953865696            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslib.cpython-39-x86_64-linux-gnu.so
7ff6eaa82000-7ff6eaa85000 rw-p 00028000 00:35 562949953865696            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslib.cpython-39-x86_64-linux-gnu.so
7ff6eaa85000-7ff6eaa94000 r--p 00000000 00:35 562949953865641            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/lib.cpython-39-x86_64-linux-gnu.so
7ff6eaa94000-7ff6eaafd000 r-xp 0000f000 00:35 562949953865641            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/lib.cpython-39-x86_64-linux-gnu.so
7ff6eaafd000-7ff6eab0e000 r--p 00078000 00:35 562949953865641            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/lib.cpython-39-x86_64-linux-gnu.so
7ff6eab0e000-7ff6eab0f000 ---p 00089000 00:35 562949953865641            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/lib.cpython-39-x86_64-linux-gnu.so
7ff6eab0f000-7ff6eab10000 r--p 00089000 00:35 562949953865641            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/lib.cpython-39-x86_64-linux-gnu.so
7ff6eab10000-7ff6eab1e000 rw-p 0008a000 00:35 562949953865641            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/lib.cpython-39-x86_64-linux-gnu.so
7ff6eab1e000-7ff6eab60000 rw-p 00000000 00:00 0
7ff6eab60000-7ff6eab72000 r--p 00000000 00:35 562949953865600            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/algos.cpython-39-x86_64-linux-gnu.so
7ff6eab72000-7ff6eacbc000 r-xp 00012000 00:35 562949953865600            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/algos.cpython-39-x86_64-linux-gnu.so
7ff6eacbc000-7ff6eacda000 r--p 0015c000 00:35 562949953865600            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/algos.cpython-39-x86_64-linux-gnu.so
7ff6eacda000-7ff6eacdb000 r--p 00179000 00:35 562949953865600            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/algos.cpython-39-x86_64-linux-gnu.so
7ff6eacdb000-7ff6eace7000 rw-p 0017a000 00:35 562949953865600            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/algos.cpython-39-x86_64-linux-gnu.so
7ff6eace7000-7ff6eacea000 rw-p 00000000 00:00 0
7ff6eacea000-7ff6eacee000 r--p 00000000 00:35 562949953865652            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops_dispatch.cpython-39-x86_64-linux-gnu.so
7ff6eacee000-7ff6eacf4000 r-xp 00004000 00:35 562949953865652            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops_dispatch.cpython-39-x86_64-linux-gnu.so
7ff6eacf4000-7ff6eacf6000 r--p 0000a000 00:35 562949953865652            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops_dispatch.cpython-39-x86_64-linux-gnu.so
7ff6eacf6000-7ff6eacf7000 r--p 0000b000 00:35 562949953865652            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops_dispatch.cpython-39-x86_64-linux-gnu.so
7ff6eacf7000-7ff6eacf9000 rw-p 0000c000 00:35 562949953865652            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/ops_dispatch.cpython-39-x86_64-linux-gnu.so
7ff6eacf9000-7ff6eacff000 r--p 00000000 00:35 562949953865762            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/vectorized.cpython-39-x86_64-linux-gnu.so
7ff6eacff000-7ff6ead22000 r-xp 00006000 00:35 562949953865762            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/vectorized.cpython-39-x86_64-linux-gnu.so
7ff6ead22000-7ff6ead29000 r--p 00029000 00:35 562949953865762            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/vectorized.cpython-39-x86_64-linux-gnu.so
7ff6ead29000-7ff6ead2a000 ---p 00030000 00:35 562949953865762            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/vectorized.cpython-39-x86_64-linux-gnu.so
7ff6ead2a000-7ff6ead2b000 r--p 00030000 00:35 562949953865762            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/vectorized.cpython-39-x86_64-linux-gnu.so
7ff6ead2b000-7ff6ead2e000 rw-p 00031000 00:35 562949953865762            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/vectorized.cpython-39-x86_64-linux-gnu.so
7ff6ead2e000-7ff6ead2f000 rw-p 00000000 00:00 0
7ff6ead2f000-7ff6ead3a000 r--p 00000000 00:35 562949953865734            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/period.cpython-39-x86_64-linux-gnu.so
7ff6ead3a000-7ff6ead77000 r-xp 0000b000 00:35 562949953865734            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/period.cpython-39-x86_64-linux-gnu.so
7ff6ead77000-7ff6ead8a000 r--p 00048000 00:35 562949953865734            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/period.cpython-39-x86_64-linux-gnu.so
7ff6ead8a000-7ff6ead8b000 r--p 0005a000 00:35 562949953865734            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/period.cpython-39-x86_64-linux-gnu.so
7ff6ead8b000-7ff6ead93000 rw-p 0005b000 00:35 562949953865734            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/period.cpython-39-x86_64-linux-gnu.so
7ff6ead93000-7ff6eadd5000 rw-p 00000000 00:00 0
7ff6eadd5000-7ff6eadd9000 r--p 00000000 00:35 562949953865658            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/properties.cpython-39-x86_64-linux-gnu.so
7ff6eadd9000-7ff6eade2000 r-xp 00004000 00:35 562949953865658            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/properties.cpython-39-x86_64-linux-gnu.so
7ff6eade2000-7ff6eade4000 r--p 0000d000 00:35 562949953865658            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/properties.cpython-39-x86_64-linux-gnu.so
7ff6eade4000-7ff6eade5000 ---p 0000f000 00:35 562949953865658            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/properties.cpython-39-x86_64-linux-gnu.so
7ff6eade5000-7ff6eade6000 r--p 0000f000 00:35 562949953865658            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/properties.cpython-39-x86_64-linux-gnu.so
7ff6eade6000-7ff6eade7000 rw-p 00010000 00:35 562949953865658            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/properties.cpython-39-x86_64-linux-gnu.so
7ff6eade7000-7ff6eadf4000 r--p 00000000 00:35 562949953865749            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timestamps.cpython-39-x86_64-linux-gnu.so
7ff6eadf4000-7ff6eae3b000 r-xp 0000d000 00:35 562949953865749            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timestamps.cpython-39-x86_64-linux-gnu.so
7ff6eae3b000-7ff6eae50000 r--p 00054000 00:35 562949953865749            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timestamps.cpython-39-x86_64-linux-gnu.so
7ff6eae50000-7ff6eae51000 ---p 00069000 00:35 562949953865749            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timestamps.cpython-39-x86_64-linux-gnu.so
7ff6eae51000-7ff6eae52000 r--p 00069000 00:35 562949953865749            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timestamps.cpython-39-x86_64-linux-gnu.so
7ff6eae52000-7ff6eae5f000 rw-p 0006a000 00:35 562949953865749            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timestamps.cpython-39-x86_64-linux-gnu.so
7ff6eae5f000-7ff6eae61000 rw-p 00000000 00:00 0
7ff6eae61000-7ff6eae6c000 r--p 00000000 00:35 562949953865742            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/strptime.cpython-39-x86_64-linux-gnu.so
7ff6eae6c000-7ff6eaeac000 r-xp 0000b000 00:35 562949953865742            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/strptime.cpython-39-x86_64-linux-gnu.so
7ff6eaeac000-7ff6eaeb6000 r--p 0004b000 00:35 562949953865742            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/strptime.cpython-39-x86_64-linux-gnu.so
7ff6eaeb6000-7ff6eaeb7000 r--p 00054000 00:35 562949953865742            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/strptime.cpython-39-x86_64-linux-gnu.so
7ff6eaeb7000-7ff6eaebe000 rw-p 00055000 00:35 562949953865742            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/strptime.cpython-39-x86_64-linux-gnu.so
7ff6eaebe000-7ff6eaeff000 rw-p 00000000 00:00 0
7ff6eaeff000-7ff6eaf08000 r--p 00000000 00:35 562949953865716            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/fields.cpython-39-x86_64-linux-gnu.so
7ff6eaf08000-7ff6eaf38000 r-xp 00009000 00:35 562949953865716            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/fields.cpython-39-x86_64-linux-gnu.so
7ff6eaf38000-7ff6eaf41000 r--p 00039000 00:35 562949953865716            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/fields.cpython-39-x86_64-linux-gnu.so
7ff6eaf41000-7ff6eaf42000 r--p 00041000 00:35 562949953865716            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/fields.cpython-39-x86_64-linux-gnu.so
7ff6eaf42000-7ff6eaf47000 rw-p 00042000 00:35 562949953865716            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/fields.cpython-39-x86_64-linux-gnu.so
7ff6eaf47000-7ff6eaf48000 rw-p 00000000 00:00 0
7ff6eaf48000-7ff6eaf54000 r--p 00000000 00:35 562949953865745            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timedeltas.cpython-39-x86_64-linux-gnu.so
7ff6eaf54000-7ff6eaf9d000 r-xp 0000c000 00:35 562949953865745            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timedeltas.cpython-39-x86_64-linux-gnu.so
7ff6eaf9d000-7ff6eafab000 r--p 00055000 00:35 562949953865745            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timedeltas.cpython-39-x86_64-linux-gnu.so
7ff6eafab000-7ff6eafac000 ---p 00063000 00:35 562949953865745            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timedeltas.cpython-39-x86_64-linux-gnu.so
7ff6eafac000-7ff6eafad000 r--p 00063000 00:35 562949953865745            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timedeltas.cpython-39-x86_64-linux-gnu.so
7ff6eafad000-7ff6eafb5000 rw-p 00064000 00:35 562949953865745            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timedeltas.cpython-39-x86_64-linux-gnu.so
7ff6eafb5000-7ff6eafb6000 rw-p 00000000 00:00 0
7ff6eafb6000-7ff6eafc9000 r--p 00000000 00:35 562949953865727            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/offsets.cpython-39-x86_64-linux-gnu.so
7ff6eafc9000-7ff6eb07a000 r-xp 00013000 00:35 562949953865727            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/offsets.cpython-39-x86_64-linux-gnu.so
7ff6eb07a000-7ff6eb093000 r--p 000c4000 00:35 562949953865727            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/offsets.cpython-39-x86_64-linux-gnu.so
7ff6eb093000-7ff6eb094000 ---p 000dd000 00:35 562949953865727            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/offsets.cpython-39-x86_64-linux-gnu.so
7ff6eb094000-7ff6eb095000 r--p 000dd000 00:35 562949953865727            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/offsets.cpython-39-x86_64-linux-gnu.so
7ff6eb095000-7ff6eb0a7000 rw-p 000de000 00:35 562949953865727            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/offsets.cpython-39-x86_64-linux-gnu.so
7ff6eb0a7000-7ff6eb0aa000 rw-p 00000000 00:00 0
7ff6eb0aa000-7ff6eb0b6000 r--p 00000000 00:35 562949953865730            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/parsing.cpython-39-x86_64-linux-gnu.so
7ff6eb0b6000-7ff6eb0fd000 r-xp 0000c000 00:35 562949953865730            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/parsing.cpython-39-x86_64-linux-gnu.so
7ff6eb0fd000-7ff6eb109000 r--p 00053000 00:35 562949953865730            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/parsing.cpython-39-x86_64-linux-gnu.so
7ff6eb109000-7ff6eb10a000 r--p 0005e000 00:35 562949953865730            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/parsing.cpython-39-x86_64-linux-gnu.so
7ff6eb10a000-7ff6eb111000 rw-p 0005f000 00:35 562949953865730            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/parsing.cpython-39-x86_64-linux-gnu.so
7ff6eb111000-7ff6eb113000 rw-p 00000000 00:00 0
7ff6eb113000-7ff6eb116000 r--p 00000000 00:35 562949953865704            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/ccalendar.cpython-39-x86_64-linux-gnu.so
7ff6eb116000-7ff6eb120000 r-xp 00003000 00:35 562949953865704            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/ccalendar.cpython-39-x86_64-linux-gnu.so
7ff6eb120000-7ff6eb122000 r--p 0000d000 00:35 562949953865704            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/ccalendar.cpython-39-x86_64-linux-gnu.so
7ff6eb122000-7ff6eb123000 r--p 0000e000 00:35 562949953865704            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/ccalendar.cpython-39-x86_64-linux-gnu.so
7ff6eb123000-7ff6eb125000 rw-p 0000f000 00:35 562949953865704            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/ccalendar.cpython-39-x86_64-linux-gnu.so
7ff6eb125000-7ff6eb12c000 r--p 00000000 00:35 562949953865757            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/tzconversion.cpython-39-x86_64-linux-gnu.so
7ff6eb12c000-7ff6eb15f000 r-xp 00007000 00:35 562949953865757            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/tzconversion.cpython-39-x86_64-linux-gnu.so
7ff6eb15f000-7ff6eb167000 r--p 0003a000 00:35 562949953865757            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/tzconversion.cpython-39-x86_64-linux-gnu.so
7ff6eb167000-7ff6eb168000 r--p 00041000 00:35 562949953865757            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/tzconversion.cpython-39-x86_64-linux-gnu.so
7ff6eb168000-7ff6eb16c000 rw-p 00042000 00:35 562949953865757            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/tzconversion.cpython-39-x86_64-linux-gnu.so
7ff6eb16c000-7ff6eb1ad000 rw-p 00000000 00:00 0
7ff6eb1ad000-7ff6eb1b4000 r--p 00000000 00:35 562949953865753            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timezones.cpython-39-x86_64-linux-gnu.so
7ff6eb1b4000-7ff6eb1d8000 r-xp 00007000 00:35 562949953865753            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timezones.cpython-39-x86_64-linux-gnu.so
7ff6eb1d8000-7ff6eb1df000 r--p 0002b000 00:35 562949953865753            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timezones.cpython-39-x86_64-linux-gnu.so
7ff6eb1df000-7ff6eb1e0000 ---p 00032000 00:35 562949953865753            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timezones.cpython-39-x86_64-linux-gnu.so
7ff6eb1e0000-7ff6eb1e1000 r--p 00032000 00:35 562949953865753            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timezones.cpython-39-x86_64-linux-gnu.so
7ff6eb1e1000-7ff6eb1e5000 rw-p 00033000 00:35 562949953865753            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/timezones.cpython-39-x86_64-linux-gnu.so
7ff6eb1e5000-7ff6eb1e8000 r--p 00000000 00:35 562949953865723            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/np_datetime.cpython-39-x86_64-linux-gnu.so
7ff6eb1e8000-7ff6eb1ee000 r-xp 00003000 00:35 562949953865723            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/np_datetime.cpython-39-x86_64-linux-gnu.so
7ff6eb1ee000-7ff6eb1f0000 r--p 00009000 00:35 562949953865723            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/np_datetime.cpython-39-x86_64-linux-gnu.so
7ff6eb1f0000-7ff6eb1f1000 r--p 0000a000 00:35 562949953865723            /deployment/envs/bert_sentiment/lib/python3.9/site-packages/pandas/_libs/tslibs/np_datetime.cpython-39-x86_64-linux-gnu.sorun.sh: line 18: 24993 Aborted                 ./example

```
