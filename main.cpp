#include <curses.h>
#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;

int maxCharacters = 5;
int countChar = 0;


// Get time stamp in nanoseconds.
uint64_t nanos()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    return ns; 
}

int main(){
    std::vector<int> characters;
    std::vector<long> timesstorage;d
    initscr();
    noecho();
    cbreak();
    bool endFlag;
    endFlag = false;
    while (endFlag == false){
        int value = getch();
        long time = nanos();
        characters.push_back(value);
        timesstorage.push_back(time);

        if (countChar == maxCharacters){
            endFlag = true;
        }
        else{
            countChar += 1;
        }
    }

    endwin();
    for (int i : characters){
        cout << i << " ";
    }

    for (long i : timesstorage){
        cout << i << " ";
    }
    return 0;
}
