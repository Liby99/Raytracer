#include "util/Bitmap.h"

struct BitmapHeader {
    int fileSize;
    int reserved;
    int startAddress;
    int headerSize;
    short width;
    short height;
    short colorPlanes;
    short bitsPerPixel;
};

Bitmap::Bitmap(int width, int height) {
    this->width = width;
    this->height = height;
    this->pixel = new int[width * height];
}

Bitmap::~Bitmap() {
    delete [] pixel;
}

int Bitmap::getWidth() const {
    return width;
}

int Bitmap::getHeight() const {
    return height;
}

Color Bitmap::getPixel(int x, int y) const {
    return Color::parse(pixel[y * width + x]);
}

void Bitmap::setPixel(int x, int y, Color color) {
    pixel[y * width + x] = color.toInt();
}

bool Bitmap::saveImage(const char * filename) const {
    BitmapHeader head;
    head.fileSize = sizeof(BitmapHeader) + 2 + width * height * sizeof(int);
    head.reserved = 0;
    head.startAddress = sizeof(BitmapHeader) + 2;
    head.headerSize = 12;
    head.width = width;
    head.height = height;
    head.colorPlanes = 1;
    head.bitsPerPixel = 32;
    FILE * f = fopen(filename, "wb");
    if (f == 0) {
        printf("Can't open '%s'\n",filename);
        return false;
    }
    short magic = 19778;
    fwrite(&magic, sizeof(short), 1, f);
    fwrite(&head, sizeof(BitmapHeader), 1, f);
    fwrite(pixel, sizeof(int), width * height, f);
    fclose(f);
    return true;
}
