# Install MacOS

PlotJuggler uses Qt5, so the default install of Qt6 must be unlinked before
building, and Qt5 added to the path.

```bash
brew unlink qt
. ./setup.sh
```

```bash
colcon build --symlink-install --cmake-args -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_CXX_STANDARD=17 -DCMAKE_MACOSX_RPATH=FALSE -DCMAKE_INSTALL_NAME_DIR=$(pwd)/install/lib -DPython3_EXECUTABLE=$(which python3) --packages-select plotjuggler
```
