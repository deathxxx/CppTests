#include <taglib/taglib.h>
#include <taglib/mp4file.h>
#include <iostream>

void readM4aTags(const std::string& filePath) {
    TagLib::MP4::File file(filePath.c_str());

    if (!file.isOpen()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    TagLib::MP4::Tag* tag = file.tag();

    std::cout << "Artist: " << tag->artist() << std::endl;
    std::cout << "Title: " << tag->title() << std::endl;
    std::cout << "Album: " << tag->album() << std::endl;
    std::cout << "Year: " << tag->year() << std::endl;
    std::cout << "Comment: " << tag->comment() << std::endl;
    std::cout << "Track: " << tag->track() << std::endl;
    std::cout << "Genre: " << tag->genre() << std::endl;
}

void writeM4aTags(const std::string& filePath) {
    TagLib::MP4::File file(filePath.c_str());

    if (!file.isOpen()) {
        std::cerr << "Error opening file for writing: " << filePath << std::endl;
        return;
    }

    TagLib::MP4::Tag* tag = file.tag();

    tag->setArtist("New Artist");
    tag->setTitle("New Title");
    tag->setAlbum("New Album");
    tag->setYear(2020);
    tag->setComment("This is a comment");
    tag->setTrack(1);
    tag->setGenre("New Genre");

    if (file.save()) {
        std::cout << "Tags written successfully." << std::endl;
    } else {
        std::cerr << "Failed to save tags." << std::endl;
    }
}

int main() {
    const std::string filePath = "example.m4a";

    std::cout << "Reading tags:" << std::endl;
    readM4aTags(filePath);

    std::cout << "\nWriting new tags..." << std::endl;
    writeM4aTags(filePath);

    std::cout << "\nReading new tags:" << std::endl;
    readM4aTags(filePath);

    return 0;
}
