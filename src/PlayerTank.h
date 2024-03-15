#pragma once
#include "BaseEngine.h"
#include "Tank.h"
#ifndef PLAYERTANK_H
#define PLAYERTANK_H

class PlayerTank :
    public Tank
{
    public:
        PlayerTank(BaseEngine *pEngine)
            : Tank(pEngine)
        {}

        virtual void virtDraw() override;
        virtual void virtDoUpdate(int iCurrentTime) override;


};

#endif /* PLAYERTANK_H */
