#include <cstdio>
#include <iostream>

#include <xstypes/xsportinfo.h>
#include <xscontroller/xsscanner.h>
#include <xscontroller/xscontrol_def.h>
#include <xscontroller/xsdevice_def.h>



static XsBaudRate baudrate = XBR_115k2;
int main(){
  std::cout <<"HELLO"<<std::endl;
  XsPortInfoArray portInfoArray = XsScanner::scanPorts(baudrate);
  return 0;
}