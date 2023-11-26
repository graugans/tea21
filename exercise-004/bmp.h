#ifndef WORKSPACES_TEA21_EXERCISE_004_BMP_H
#define WORKSPACES_TEA21_EXERCISE_004_BMP_H

#include <string>
#include <vector>

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
        uint32_t biSize = 0; /* the size of this header, in bytes (40) */
        int32_t biWidth = 0; /* the bitmap width in pixels (signed integer) */
        int32_t biHeight = 0; /* the bitmap height in pixels (signed integer) */
        uint16_t biPlanes = 0; /* the number of color planes (must be 1) */
        uint16_t biBitCount = 0; /* the number of bits per pixel, which is the color depth of the image. Typical values are 1, 4, 8, 16, 24 and 32.*/
        uint32_t biCompression = 0; /* the compression method being used. See the next table for a list of possible values */
        uint32_t biSizeImage = 0; /* the image size. This is the size of the raw bitmap data; a dummy 0 can be given for BI_RGB bitmaps. */
        int32_t biXPelsPerMeter = 0; /* the horizontal resolution of the image. (pixel per metre, signed integer) */
        int32_t biYPelsPerMeter = 0; /* the vertical resolution of the image. (pixel per metre, signed integer) */
        uint32_t biClrUsed = 0; /* the number of colors in the color palette, or 0 to default to 2^n*/
        uint32_t biClrImportant = 0; /*the number of important colors used, or 0 when every color is important; generally ignored */
        void print(); 
    };
    struct RGBA {
        uint8_t red   = 0;
        uint8_t green = 0;
        uint8_t blue  = 0;
        uint8_t alpha = 0; /* used in 32bit bitmaps */
    };
    BitmapFileHeader m_fileHeader;
    BitmapInfoHeader m_infoHeader;
    std::vector< std::vector<RGBA> > m_pixelBuffer;
};
#endif