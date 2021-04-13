#include "../v4l2lib/inc/V4l2ReadWriteDevice.h"
#include "../v4l2lib/inc/V4l2MmapDevice.h"
#include "../v4l2lib/inc/V4l2Output.h"
#include "../v4l2lib/inc/V4l2Device.h"
#include "../v4l2lib/inc/V4l2Access.h"
#include "../v4l2lib/inc/V4l2Capture.h"
#include <iostream>



int main(){
    V4L2DeviceParameters param("/dev/video0", 0, 640, 480, 10, IOTYPE_MMAP, 0);
    V4l2Capture* videoCapture = V4l2Capture::create(param);
    timeval timeout;
    bool isReadable = (videoCapture->isReadable(&timeout) == 1);
    char* buffer = new char[460800];
    size_t nb = videoCapture->read(buffer,460800);
    std::cin.get();
    std::cin.ignore();
}