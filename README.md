# OpenView - Renderer Engine

## Build project

```bash
mkdir build

cd build

cmake ../renderer_engine -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_MANIFEST_DIR=..

cmake --build .
```
