#include <iostream>
#include "Orchestra.h"
#include "Utilities.h"
#include "ConsoleInterface.h"
#include "Musician.h"
#include "Cello.h"
#include "Flute.h"
#include "Violin.h"
#include "Piano.h"
#include "ElectricPiano.h"
#include "OrchestraExceptions.h"

using namespace std;

int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    // Data initialization
    {
        Orchestra::getInstance()->addMusician(Musician("James Galway", false));
        Orchestra::getInstance()->addMusician(Musician("Johann Sebastian Bach", true));
        Orchestra::getInstance()->addMusician(Musician("Wolfgang Amadeus Mozart ", false));
        Orchestra::getInstance()->addMusician(Musician("Ludwig van Beethoven", false));
        Orchestra::getInstance()->addMusician(Musician("Franz Schubert", true));
        Orchestra::getInstance()->addMusician(Musician("Frederic Chopin", false));
        Orchestra::getInstance()->addMusician(Musician("Johann Strauss II", false));
        Orchestra::getInstance()->addMusician(Musician("Niccolò Paganini", false));
        Orchestra::getInstance()->addMusician(Musician("Franz Liszt", false));
        Orchestra::getInstance()->addMusician(Musician("Pyotr Ilyich Tchaikovsky", true));
        Orchestra::getInstance()->addMusician(Musician("Johannes Brahms", false));
        Orchestra::getInstance()->addMusician(Musician("Sergei Rachmaninoff ", true));
        Orchestra::getInstance()->addMusician(Musician("Itzhak Perlman", false));
        Orchestra::getInstance()->addMusician(Musician("Yo-Yo Ma", true));
        Orchestra::getInstance()->addMusician(Musician("Lang Lang ", false));

        Orchestra::getInstance()->addInstrument(Cello("Stradivarius Cello", 3, true));
        Orchestra::getInstance()->addInstrument(Cello("Guadagnini Cello", 4, false));
        Orchestra::getInstance()->addInstrument(Flute("Yamaha Flute ", 5, false));
        Orchestra::getInstance()->addInstrument(Flute("Yamaha Clarinet", 4, true));
        Orchestra::getInstance()->addInstrument(Violin("Stradivarius Violin", 1));
        Orchestra::getInstance()->addInstrument(Violin("Amati Violin", 12));
        Orchestra::getInstance()->addInstrument(Piano("Steinway & Sons Piano", 4, true));
        Orchestra::getInstance()->addInstrument(Piano("Yamaha Piano", 2, false));
        Orchestra::getInstance()->addInstrument(ElectricPiano("Roland Electric Piano", 1, 3, 40));
        Orchestra::getInstance()->addInstrument(ElectricPiano("Korg Electric Piano", 1, 3, 60));

        Orchestra::getInstance()->assignInstrument(0, 0);
        Orchestra::getInstance()->assignInstrument(1, 1);
        Orchestra::getInstance()->assignInstrument(2, 2);
        Orchestra::getInstance()->assignInstrument(3, 3);
        Orchestra::getInstance()->assignInstrument(4, 4);
        Orchestra::getInstance()->assignInstrument(5, 5);
        Orchestra::getInstance()->assignInstrument(6, 6);
        Orchestra::getInstance()->assignInstrument(7, 7);
        Orchestra::getInstance()->assignInstrument(8, 8);
        Orchestra::getInstance()->assignInstrument(9, 9);
        Orchestra::getInstance()->assignInstrument(6, 9);
        Orchestra::getInstance()->assignInstrument(5, 10);
        Orchestra::getInstance()->assignInstrument(0, 10);
        Orchestra::getInstance()->assignInstrument(6, 11);
        Orchestra::getInstance()->assignInstrument(7, 12);
        Orchestra::getInstance()->assignInstrument(2, 13);
        Orchestra::getInstance()->assignInstrument(0, 14);

        Orchestra::getInstance()->addMusicPiece(MusicPiece("Symphony No. 9", "Ludwig van Beethoven", 1824, 70));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Brandenburg Concerto No. 3", "Johann Sebastian Bach", 1721, 20));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Symphony No. 40", "Wolfgang Amadeus Mozart", 1788, 30));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Symphony No. 5", "Pyotr Ilyich Tchaikovsky", 1888, 50));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Canon in D", "Johann Pachelbel", 1680, 5));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("The Four Seasons", "Antonio Vivaldi", 1725, 40));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Symphony No. 8", "Franz Schubert", 1822, 25));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("The Blue Danube", "Johann Strauss II", 1867, 10));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Clair de Lune", "Claude Debussy", 1890, 8));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Ride of the Valkyries", "Richard Wagner", 1856, 9));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Messiah", "George Frideric Handel", 1741, 120));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Bolero", "Maurice Ravel", 1928, 15));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Nocturne in E-flat major", "Frederic Chopin", 1830, 6));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Piano Concerto No. 2", "Sergei Rachmaninoff", 1901, 35));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Toccata and Fugue in D minor", "Johann Sebastian Bach", 1707, 8));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Eine kleine Nachtmusik", "Wolfgang Amadeus Mozart", 1787, 18));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("The Nutcracker Suite", "Pyotr Ilyich Tchaikovsky", 1892, 25));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Symphony No. 9", "Antonin Dvorak", 1893, 45));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Swan Lake", "Pyotr Ilyich Tchaikovsky", 1876, 30));
        Orchestra::getInstance()->addMusicPiece(MusicPiece("Symphony No. 6", "Ludwig van Beethoven", 1808, 40));

        Orchestra::getInstance()->createAutoConcert(100);
        Orchestra::getInstance()->createAutoConcert(240);
        Orchestra::getInstance()->createAutoConcert(60);
    }

    try {
        cout << "Welcome to our Orchestra" << endl << endl;
        bool keepAlive = true;
        do {
            Help();
            cout << "Please select the desired process, for help press H/h" << endl << endl;
            char userOption;
            receiveAlphaChar(&userOption);
            switch (userOption) {

            case 'H':
            case 'h':
                Help();
                break;

            case 'D':
            case 'd':
                displayOrchestra();
                break;

            case 'A':
            case 'a':
                addData();
                break;

            case 'I':
            case 'i':
                assignInstrument();
                break;

            case 'R':
            case 'r':
                removeConcert();
                break;

            case 'C':
            case 'c':
                composeMusicPiece();
                break;

            case 'N':
            case 'n':
                changeConductor();
                break;

            case 'T':
            case 't':
                checkAndTuneInstrument();
                break;

            case 'S':
            case 's':
                addSoloMusician();
                break;

            case 'P':
            case 'p':
                playConcert();
                break;
            case 'M':
            case 'm':
                subscibersEditor();
                break;
            case 'Q':
            case 'q':
                Orchestra::getInstance()->destroyInstance();
                keepAlive = false;
                exit(1);

            default:
                cout << "Incorrect input, please try again" << endl << endl;
                break;
            }
        } while (keepAlive);
    }
    catch (MaxCapacityException e) {
        e.show();
    }
    catch (ObjectNotExistsException e) {
        e.show();
    }
    catch (ObjectExistsException e) {
        e.show();
    }
    catch (InvalidNameException e) {
        e.show();
    }
    catch (OrchestraExceptions e) {
        e.show();
    }
}
