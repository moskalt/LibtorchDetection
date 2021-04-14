#include "logger.h"
#include "V4l2Access.h"
#include "V4l2Capture.h"
#include "V4l2Device.h"
#include "V4l2MmapDevice.h"
#include "V4l2Output.h"
#include "V4l2ReadWriteDevice.h"
#include <iostream>
#include "processing.h"


int main(){
    V4L2DeviceParameters param("/dev/video0", 0, 416, 416, 30, IOTYPE_MMAP, 0);
    V4l2Capture* videoCapture = V4l2Capture::create(param);
    timeval timeout;
    bool isReadable = (videoCapture->isReadable(&timeout) == 1);
    char* buffer = new char[460800];
    size_t nb = videoCapture->read(buffer,460800);
}