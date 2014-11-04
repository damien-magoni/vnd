vnd
===

The Virtual Network Device (vnd) is a program for emulating network devices.
It can be used to interconnect virtual machines running on emulators (QEMU, Dynamips, etc) 
that support the same backends.

Compared to other existing solutions, vnd has the following features:
- runs in user space
- can make virtual links with TCP or UDP sockets, UNIX sockets, taps and VDEs
- each interface can have any parameter (bandwidth, delay, jitter, BER) modified 
separately on its input and output queues

It uses some of the Boost libs, OpenSSH libs and the libvdeplug.
See the manual for more information.
If you want to build complex virtual networks, please use NEmu (http://nemu.valab.net/) which internally uses vnd.

If you use either vnd or NEmu for your research or educational work, please cite:

    Network Emulator: a Network Virtualization Testbed for Overlay Experimentations.
    Vincent Autefage, Damien Magoni.
    CAMAD'12 - IEEE International Workshop on Computer-Aided Modeling Analysis and 
    Design of Communication Links and Networks,
    pp. 38-42, September 17-19, 2012, Barcelona, Spain.
