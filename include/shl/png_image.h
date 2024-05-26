#pragma once

#include <stdint.h>

namespace shl {
    struct Image {
        uint32_t height;
        uint32_t width;
        uint32_t* pixels;

        uint32_t getPixelAt(uint32_t height, uint32_t width);
    };
    // Loads png-file into Image object
    Image loadImage(const char* filename);
    // loads pixels into existing buffer and sets the loaded height and width.
    // logs a warning if buffer size is smaller than the required size.
    // sets the height and width to the dimensions read.
    bool loadImageIntoBuffer(const char* filename, void* buffer, size_t buffer_size, uint32_t* pWidth, uint32_t* pHeight);
}