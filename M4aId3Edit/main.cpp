//#include <iostream>
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}


//#include "taglib/tag.h" //doesnt work
#include <taglib/taglib.h>
#include <iostream>

int main() {
    // Replace "path/to/your/file.m4a" with the actual path to your M4A file
    TagLib::FileRef file("path/to/your/file.m4a");

    if (!file.isOpen()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Get the tag object
    TagLib::Tag* tag = file.tag();

    // Set the title, artist, and album (replace with your desired values)
    tag->setTitle("My Song Title");
    tag->setArtist("My Artist Name");
    tag->setAlbum("My Album Title");

    // Save the changes
    if (!file.save()) {
        std::cerr << "Error saving changes!" << std::endl;
        return 1;
    }

    std::cout << "ID3 tags edited successfully!" << std::endl;

    return 0;
}