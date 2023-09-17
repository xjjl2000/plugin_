## qt GUI for vehicle2real

1. install env

```bash
apt-get install  qt5-default qttools5-dev libqt5x11extras5-dev
apt-get install  libvtk7-dev libpcl-dev #notest
```

2. build 

```bash
cd build
cmake ..
cmake --build .
```
2. run

```bash
./rvizplugin
```