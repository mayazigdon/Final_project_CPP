#pragma once

#ifndef MUSICPIECE_H
#define MUSICPIECE_H

class MusicPiece
{
private:
    char* name;
    char* composerName;
    int yearOfRelease;
    int lengthInMinutes;

public:
    MusicPiece(const char* name, const char* composerName, int yearOfRelease, int lenghtInMinutes);
    MusicPiece(const MusicPiece& other);  // copy 
    MusicPiece(MusicPiece&& other) noexcept;  // move 

    const char* getMusicPieceName(void) const;
    const char* getMusicPieceComposerName(void) const;
    int getMusicPieceReleaseYear(void) const;
    int getMusicPieceLength(void) const;
    MusicPiece* clone(void) const;

    void setMusicPieceName(const char* name);
    void setMusicPieceComposerName(const char* composerName);
    void setMusicPieceReleaseYear(const int yearOfRelease);
    void setMusicPieceLength(const int lenghtInMinutes);
    void print(void) const;

    bool operator ==(const MusicPiece& other) const;
    MusicPiece& operator=(const MusicPiece& other);  // = operator

    ~MusicPiece(void);
};

#endif  // MUSICPIECE_H
