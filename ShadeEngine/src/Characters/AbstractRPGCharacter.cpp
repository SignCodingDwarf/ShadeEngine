/*!
 * @file AbstractRPGCharacter.cpp
 * @brief Interface of classes used to describe a RPG character.
 * @author SignC0dingDw@rf
 * @date 29 April 2018
 *
 * Implementation of RPG-like characters that can earn experience and level up. Optionnally they can also lose experience and level down. <br>
 * The class proposes a default behavior for XP win or loss that implies that character can go several levels up or down. You may overload these methods to enforce different behavior. <br>
 * Abstract class.
 *
 */
#include "include/Characters/AbstractRPGCharacter.h"

namespace ShadeEngine
{
    AbstractRPGCharacter::AbstractRPGCharacter(uint8_t level_max, bool can_level_down) : m_level(1), m_level_max(level_max),
        m_can_level_down(can_level_down), m_xp(0)
    {
    }

    void AbstractRPGCharacter::gainXP(uint64_t m_xp_gained)
    {
        if(m_level < m_level_max) // Ignore XP gain if level is equal to level max
        {
            (m_xp_gained + m_xp > getLevelXp(m_level_max)) && (m_xp = getLevelXp(m_level_max)) || (m_xp += m_xp_gained); // Clamp to XP of level max
            while(m_level <= m_level_max && m_xp >= getLevelXp(m_level+1)) // Use a while because XP gain can span accross multiple levels
            {
                ++m_level;
                onLevelUp();
            }
        }
    }

    void AbstractRPGCharacter::loseXP(uint64_t m_xp_lost)
    {
        if(m_can_level_down && m_xp > 0) // Ignore XP loss if XP is equal to 0 or if character cannot level down
        {
            (m_xp_lost >= m_xp) && (m_xp = 0) || (m_xp -= m_xp_lost); // Clamp to 0
            while(m_level > 1 && m_xp < getLevelXp(m_level-1)) // Use a while because XP loss can span accross multiple levels
            {
                --m_level;
                onLevelDown();
            }
        }
    }
}

//  ______________________________
// |                              |
// |    ______________________    |
// |   |                      |   |
// |   |         Sign         |   |
// |   |        C0ding        |   |
// |   |        Dw@rf         |   |
// |   |         1.0          |   |
// |   |______________________|   |
// |                              |
// |______________________________|
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |__|
