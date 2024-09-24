#include "FileSystem.hpp"
#include<iostream>
using namespace std;

int main(){
    Directory* MovieFolder = new Directory("Movies");
    Directory* EnglishMovie = new Directory("English Movies");
    File* movie1 = new File("GOAT");
    File* movie2 = new File("Interstellar");
    Directory* EnglishMovie2 = new Directory("English Movie2");
    EnglishMovie->add(movie1);
    EnglishMovie->add(EnglishMovie2);
    EnglishMovie->add(movie2);
    MovieFolder->add(EnglishMovie);
    MovieFolder->ls();

    cout<<"After Deleting the English Movie2"<<'\n';
    EnglishMovie->Delete(EnglishMovie2);
    MovieFolder->ls();

    cout<<"After Resotring the English Movie2"<<'\n';
    EnglishMovie->restore();
    MovieFolder->ls();
}