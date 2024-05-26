#include "png_image.h"
#define SHL_LOG_WARN
#include "logging.h"

#include <fstream>

namespace shl {
    union PngHeader {
        uint8_t asBytes[8];
        char asChars[8];
        uint64_t asInteger;
    };
    const PngHeader PNG_HEADER = {.asBytes = {137, 80, 78, 71, 13, 10, 26, 10}};
    uint8_t* readBinaryFile(const char* filename, size_t* pSize) {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        if (!file.is_open()) {
            std::cerr << "Die Datei konnte nicht geöffnet werden!" << std::endl;
            return nullptr;
        }

        // Dateigröße ermitteln
        *pSize = file.tellg();
        file.seekg(0, std::ios::beg);
    }
    uint32_t Image::getPixelAt(uint32_t xpos, uint32_t ypos) {
        if (width <= xpos || height <= ypos) {
            logError("cannot get value for positions: {", xpos, ',', ypos, "} for dimensions: {", width, ',', height, '}');
            return 0;
        } else {
            return pixels[xpos+ ypos * height];
        }
    }
    bool loadImageIntoBuffer(const char* filename, void* buffer, size_t buffer_size, uint32_t* pWidth, uint32_t* pHeight) {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        if (file.is_open()) {
            LOG_ERROR("failed to open file: ",  filename);
            return false;
        }
        // Dateigröße ermitteln
        size_t filesize = file.tellg();
        file.seekg(0, std::ios::beg);
        // Check header for magic number
        {
            PngHeader header;
            file.read(header.asChars, 8);
            if(header.asInteger != PNG_HEADER.asInteger) {
                LOG_ERROR("file: ", filename, " is no png-file");
                return false;
            }
        }
        



        return true;
    }
}