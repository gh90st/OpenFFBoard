/*
 * FFBWheel.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yannick
 */

#include "FFBWheel.h"
#include "usb_hid_ffb_desc.h"

// Unique identifier for listing
ClassIdentifier FFBWheel::info = {
		 .name = "FFB Wheel (1 Axis)" ,
		 .id=CLSID_MAIN_FFBWHEEL,
 };

const ClassIdentifier FFBWheel::getInfo(){
	return info;
}


FFBWheel::FFBWheel() : FFBHIDMain(1) {

}

FFBWheel::~FFBWheel() {

}



void FFBWheel::usbInit(){
	this->usbdev = std::make_unique<USBdevice>(&usb_devdesc_ffboard_composite,usb_cdc_hid_conf_1axis,&usb_ffboard_strings_default);
	FFBHIDMain::UsbHidHandler::setHidDesc(hid_1ffb_desc);
	usbdev->registerUsb();
}
