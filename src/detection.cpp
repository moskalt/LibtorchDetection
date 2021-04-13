#include "torch/torch.h"
#include "../v4l2lib/inc/V4l2ReadWriteDevice.h"
#include "../v4l2lib/inc/V4l2MmapDevice.h"
#include "../v4l2lib/inc/V4l2Output.h"
#include "../v4l2lib/inc/V4l2Device.h"
#include "../v4l2lib/inc/V4l2Access.h"
#include "../v4l2lib/inc/V4l2Capture.h"


int main(){
    V4L2DeviceParameters param("/dev/video0", V4L2_PIX_FMT_RGB24, 400, 400, 10, IOTYPE_MMAP, 0);
    V4l2Capture* videoCapture = V4l2Capture::create(param);
    std::cout << "YES" << std::endl;
}