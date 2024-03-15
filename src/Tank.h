#pragma once
#include "BaseEngine.h"
#include "DisplayableObject.h"
#ifndef TANK_H
#define TANK_H

class Tank :
    public DisplayableObject
{
    public:
        Tank(BaseEngine *pEngine)
            : DisplayableObject(pEngine)
        {
            m_iCurrentScreenX = 200;
            m_iCurrentScreenY = 400;
            m_iDrawHeight = 100;
            m_iDrawWidth = 100;
        }

        virtual void virtDraw() override;
        virtual void virtDoUpdate(int iCurrentTime) override;

        int getScreenX() const {return m_iCurrentScreenX;}
        int getScreenY() const {return m_iCurrentScreenY;}

};

#endif /* TANK_H */
