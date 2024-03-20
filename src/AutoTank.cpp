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
    // update axis values
    updateAxis();
    // get new X and Y values with updated axis
    newX = getNewX();
    newY = getNewY();

    // if auto tank instance is moving towards the edge of play area constantly
    // then an axis will be flipped to promote a change in direction
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
    // 15% chance of axis values changing
    if(rand() % 100 <= 15) {
        // axis values are changed by a value <= 3
        // if axis value is already equal to 3 or -3
        // then its will not be changed past these values
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
