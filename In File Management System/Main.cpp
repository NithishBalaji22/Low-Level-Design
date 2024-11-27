#include <iostream>
#include "FileSystem.hpp"
#include "File.hpp"
#include "Directory.hpp"
using namespace std;

/*

	Module1: Create a new directory and file in all Levels.
	Module2: List all directories and files.
	Module3: Update file content.
	Module4: Update directory and file names.
	Module5: Delete directory and file.
	Module6: Restore deleted directories and files.

*/

int main(){
    Directory* movieDirectory = new Directory("Movies");
    Directory* tamilMovies = new Directory("Tamil Movies");
    File* Amaran = new File("Amaran");
    File* GOAT = new File("GOAT");

    // Module 1: Adding files and directories
    tamilMovies->add(Amaran);
    tamilMovies->add(GOAT);
    movieDirectory->add(tamilMovies);

    // Module 2: List all directories and files
    movieDirectory->ls();

    // Module 3: Update file content
    Amaran->updateContent("Amaran Movie");
    Amaran->updateContent("AMARAN MOVIE");
    Amaran->undoContent();

    // Module 4: Update directory and file names
    tamilMovies->changeName("TAMIL MOVIE");
    GOAT->changeName("GOAT_2024.mp4");

    // Module 5: Delete file
    tamilMovies->deleteFile(Amaran);
    movieDirectory->ls();

    // Module 6: Restore deleted file
    tamilMovies->restore();
    movieDirectory->ls();
}