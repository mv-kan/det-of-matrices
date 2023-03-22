# How to compile 
For release mode
```
mkdir build 
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
# "./dom" bin is already compiled here
```


For debug mode (not recommended)
```
mkdir build 
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
# "./dom" bin is already compiled here
```