#include "header.h"

#include "AutoTank.h"

void AutoTank::virtDraw() {
    getEngine()->drawForegroundOval(m_iCurrentScreenX,
                                    m_iCurrentScreenY,
                                    m_iCurrentScreenX + m_iDrawWidth - 1,
                                    m_iCurrentScreenY + m_iDrawHeight - 1,
                                    0xff3401);
    getEngine()->drawForegroundString(m_iCurrentScreenX + 2,
                                      m_iCurrentScreenY + m_iDrawHeight/2,
                                      "Stay Away", 0xffffff);
}

void AutoTank::virtDoUpdate(int iCurrentTime) {
    int newX, newY;
    updateAxis();
    newX = getNewX();
    newY = getNewY();
    if(newX <= 50 || newX >= getEngine()->getWindowWidth() - m_iDrawWidth - 50) {
        flipAxisX();
        newX = getNewX();
    }
    if(newY <= 50 || newY >= getEngine()->getWindowHeight() - m_iDrawHeight - 50) {
        flipAxisY();
        newY = getNewY();
    }

    setPosition(newX, newY);
}

void AutoTank::updateAxis() {
    int xa, ya;
    if(rand() % 100 < 15) {
        xa = (rand() % 3) - 1;
        if(-3 < m_iAxisX+xa && 3 > m_iAxisX+xa) {
            m_iAxisX += xa;
        }
        ya = (rand() % 3) - 1;
        if(-3 < m_iAxisY+ya && 3 > m_iAxisY+ya) {
            m_iAxisY += ya;
        }
    }
}
