#pragma once

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Person.h"
#include "MusicPiece.h"

class Conductor : public Person
{
private:
    enum Style { Classic, Romantic, Modern, Jazz };
    Style type = Classic;

public:
    Conductor(void) = default;
    Conductor(const char* Name, int type);
    Conductor(const Conductor& other);   //copy
    Conductor(Conductor&& other) noexcept;   //move
    const char* getStyleType(void) const;
    void setStyleType(int type);
    MusicPiece* compose(const char* name, int minDuration, int maxDuration) const;
    void print(void) const override;   //=
    const Conductor& operator=(const Conductor& other);
    virtual ~Conductor(void);
};

#endif // CONDUCTOR_H
