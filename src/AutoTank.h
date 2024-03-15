#pragma once
#include "BaseEngine.h"
#include "Tank.h"
#ifndef AUTOTANK_H
#define AUTOTANK_H

class AutoTank :
    public Tank
{
    public:
        AutoTank(BaseEngine *pEngine)
            : Tank(pEngine)
        {
            m_iAxisX = 0;
            m_iAxisY = 0;
            setPosition(500, 500);
        }

        virtual void virtDraw() override;
        virtual void virtDoUpdate(int iCurrentTime) override;

        void updateAxis();

        void flipAxisX() {m_iAxisX = m_iAxisX*(-1);};
        void flipAxisY() {m_iAxisY = m_iAxisY*(-1);};

        int getNewX() const {return m_iCurrentScreenX + m_iAxisX;};
        int getNewY() const {return m_iCurrentScreenY + m_iAxisY;};

    private:
        int m_iAxisX;
        int m_iAxisY;

};

#endif /* AUTOTANK_H */
