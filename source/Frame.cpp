#include "stdafx.h"
#include "Frame.h"

Frame::Frame()
{
}

Frame::~Frame()
{
}

decltype(Frame::boxes_)& Frame::getBoxes() { return boxes_; }