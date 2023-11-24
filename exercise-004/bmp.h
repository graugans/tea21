#ifndef WORKSPACES_TEA21_EXERCISE_004_BMP_H
#define WORKSPACES_TEA21_EXERCISE_004_BMP_H

#include <string>

class BMP {
public:
    BMP();
    ~BMP();
    bool read(const std::string&  filename);
    bool write(const std::string&  filename);
private:
    struct BitmapFileHeader {
        char bfType[2] = {'X','X'}; /*> The header field used to identify the BMP and DIB file is*/
        uint32_t bfSize  = 0; /*> The size of the BMP file in bytes */
        uint32_t bfReserved = 0; /*> reserved */
        uint32_t bfOffBits = 0; /*> The offset, i.e. starting address, of the byte where the bitmap image data (pixel array) can be found. */
        void print(); 
    };
    struct BitmapInfoHeader {
        uint32_t biSize = 0;
        int32_t biWidth = 0;
        int32_t biHeight = 0;
        uint16_t biPlanes = 0;
        uint16_t biBitCount = 0;
        uint32_t biCompression = 0;
        uint32_t biSizeImage = 0;
        int32_t biXPelsPerMeter = 0;
        int32_t biYPelsPerMeter = 0;
        uint32_t biClrUsed = 0;
        uint32_t biClrImportant = 0;
    };
    struct RGBA {
        uint8_t red   = 0;
        uint8_t green = 0;
        uint8_t blue  = 0;
        uint8_t alpha = 0; /* used in 32bit bitmaps */
    };
    BitmapFileHeader m_fileHeader;
    BitmapInfoHeader m_infoHeader;
};
#endif