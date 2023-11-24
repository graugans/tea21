#include <fmt/format.h>
#include <fstream>
#include "bmp.h"


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
    return ret;
}

bool BMP::write(const std::string& filename)
{
    auto ret = false;
    // insert your code here
    return ret;
}
