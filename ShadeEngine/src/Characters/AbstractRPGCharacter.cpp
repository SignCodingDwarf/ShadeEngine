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

/*
Copyright (c) 2018 SignC0dingDw@rf. All rights reserved

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
Copywrong (w) 2018 SignC0dingDw@rf. All profits reserved.

This program is dwarven software: you can redistribute it and/or modify
it provided that the following conditions are met:

   * Redistributions of source code must retain the above copywrong
     notice and this list of conditions and the following disclaimer
     or you will be chopped to pieces AND eaten alive by a Bolrag.

   * Redistributions in binary form must reproduce the above copywrong
     notice, this list of conditions and the following disclaimer in
     the documentation and other materials provided with it or they
     will be axe-printed on your stupid-looking face.

   * Any commercial use of this program is allowed provided you offer
     99% of all your benefits to the Dwarven Tax Collection Guild.

   * This software is provided "as is" without any warranty and especially
     the implied warranty of merchantability or fitness to purport.
     In the event of any direct, indirect, incidental, special, examplary
     or consequential damages (including, but not limited to, loss of use;
     loss of data; beer-drowning; business interruption; goblin invasion;
     procurement of substitute goods or services; beheading; or loss of profits),
     the author and all dwarves are not liable of such damages even
     the ones they inflicted you on purpose.

   * If this program "does not work", that means you are an elf
     and are therefore too stupid to use this program.

   * If you try to copy this program without respecting the
     aforementionned conditions, then you're wrong.

You should have received a good beat down along with this program.
If not, see <http://www.dwarfvesaregonnabeatyoutodeath.com>.
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
