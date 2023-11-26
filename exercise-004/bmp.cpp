#include <fmt/format.h>
#include <fstream>
#include "bmp.h"
#include <array>

/* Some helper template function to reduce the risk of copy paste errors */
template<typename T>
static void read_value(std::fstream& file,T* value )
{
    file.read(reinterpret_cast<char*>(value), sizeof(T));
}

void BMP::BitmapFileHeader::print()
{
    fmt::println("======= The Bitmap File Info Header =======");
    fmt::println("  > The start: {}{}", bfType[0], bfType[1]);
    fmt::println("  > The size in bytes: {}", bfSize);
    fmt::println("  > The offset in bits: {}", bfOffBits);
}

void BMP::BitmapInfoHeader::print()
{
    fmt::println("======= The Bitmap Info Header =======");
    fmt::println("  > biSize: {}",biSize);
    fmt::println("  > biWidth: {}", biWidth);
    fmt::println("  > biHeight: {}", biHeight);
    fmt::println("  > biPlanes: {}", biPlanes);
    fmt::println("  > biBitCount: {}", biBitCount);
    fmt::println("  > biCompression: {}", biCompression);
    fmt::println("  > biSizeImage: {}", biSizeImage);
    fmt::println("  > biXPelsPerMeter: {}", biXPelsPerMeter);
    fmt::println("  > biYPelsPerMeter: {}", biYPelsPerMeter);
    fmt::println("  > biClrUsed: {}", biClrUsed);
    fmt::println("  > biClrImportant: {}", biClrImportant);
}

BMP::BMP() {
    fmt::println("BMP CTOR");
}

BMP::~BMP() {
    fmt::println("BMP DTOR");
}


bool BMP::read(const std::string& filename)
{
    auto ret = false;
    // insert your code here
    std::fstream input_file(filename, std::ios::binary | std::ios::in );
    if (!input_file.is_open()) {
        fmt::print("Unable to open the file: {}\n",filename);
        return ret;
    }
    // Read the Bitmap File Info Header
    read_value(input_file,&m_fileHeader.bfType);
    read_value(input_file,&m_fileHeader.bfSize);
    read_value(input_file,&m_fileHeader.bfReserved);
    read_value(input_file,&m_fileHeader.bfOffBits);
    m_fileHeader.print();

    // Read the Bitmap Info Header
    read_value(input_file, &m_infoHeader.biSize);
    read_value(input_file, &m_infoHeader.biWidth);
    read_value(input_file, &m_infoHeader.biHeight);
    read_value(input_file, &m_infoHeader.biPlanes);
    read_value(input_file, &m_infoHeader.biBitCount);
    read_value(input_file, &m_infoHeader.biCompression);
    read_value(input_file, &m_infoHeader.biSizeImage);
    read_value(input_file, &m_infoHeader.biXPelsPerMeter);
    read_value(input_file, &m_infoHeader.biYPelsPerMeter);
    read_value(input_file, &m_infoHeader.biClrUsed);
    read_value(input_file, &m_infoHeader.biClrImportant);
    m_infoHeader.print();

    auto rowSize = floor((m_infoHeader.biWidth*m_infoHeader.biBitCount+31)/32)*4;
    fmt::println("Row size: {}",rowSize);
    auto numPaddingBytes = rowSize - m_infoHeader.biWidth*m_infoHeader.biBitCount/8;
    uint32_t paddingBytes{0};
    fmt::println("Num padding Bytes: {}",numPaddingBytes);

    std::array<char,10> ascii_lut{'#','*','+','~','8','O','o',':',' ',' '};

    if(m_infoHeader.biBitCount==24)
    {
        m_pixelBuffer.resize(m_infoHeader.biHeight);
        for(int row = 0; row < m_infoHeader.biHeight; row++)
        {
            fmt::println("Row: {}",row);
            m_pixelBuffer[row].resize(m_infoHeader.biWidth);
            for (int col; col < m_infoHeader.biWidth; col++)
            {
                read_value(input_file, &m_pixelBuffer[row][col].red);
                read_value(input_file, &m_pixelBuffer[row][col].green);
                read_value(input_file, &m_pixelBuffer[row][col].blue);
                unsigned int gray = std::floor((m_pixelBuffer[row][col].red + m_pixelBuffer[row][col].red + m_pixelBuffer[row][col].red) / 3);
                auto ascii_index = 0;
                fmt::print("{}", ascii_lut[(int)((gray * (ascii_lut.size() - 1)) / 255)]);
            }
            fmt::println("|");
            input_file.read(reinterpret_cast<char*>(&paddingBytes), numPaddingBytes);    
        }
    }


    return ret;
}

bool BMP::write(const std::string& filename)
{
    auto ret = false;
    // insert your code here
    return ret;
}
